#include <stdio.h>
#include <stdlib.h>
//#include "bank.h"
int deleted_customer=1000;
char choice=0 ;
int index = 0,j=0, id_check=0,i=0;
struct customer_s {
char name[70];
char customertype [10];
int id ;
double cash ;
}customer[3];
void create_new_customer (struct customer_s * customer)
{

    printf("please enter the customer name : ");
    fflush(stdin);
    gets(customer[index].name);
    printf("please enter the customer type : ");
    fflush(stdin);
    gets(customer[index].customertype);
    printf("please , enter the customer ID : ");
    idcheck2 :
    scanf("%i",&customer[index].id);
    for(i = 0 ; i < index ; i++ )
    {
        if (customer[index].id == customer[i].id)

        {
            printf("\nerror : repeating customer id \ngive another id\n");
            goto idcheck2;
        }

    }
    printf("please enter the customer cash : ");
    reenter_cash :
    scanf("%lf",&customer[i].cash);
    if(customer[i].cash < 0 )
        {
            printf("\ncash must be grater than or equal 0 :\n");
            goto reenter_cash;
        }
    index++;
}
void edit_customer (struct customer_s * customer)
{
    printf("\nenter customer id to edit on it :\n");
    scanf("%i",&id_check);
    idcheck :
    for(i = 0 ; i < 3 ; i++ )
    {
        if (id_check == customer[i].id)
        {
            printf("please enter the new customer name : ");
            fflush(stdin);
            gets(customer[i].name);
            printf("please enter the new customer type : ");
            fflush(stdin);
            gets(customer[i].customertype);
            printf("please , enter the new customer ID : ");
            edit_id_repeated :
            scanf("%i",&customer[i].id);
            for(j = 0 ; j < 3 ; j++ )
           {

                if (customer[i].id == customer[j].id)
                    {
                        if(i == j )
                        break;
                        printf("\nerror : repeating customer id \ngive another id\n");
                        goto edit_id_repeated;
                    }
           }
            printf("please enter the new customer cash : ");
            reenter_cash :
            scanf("%lf",&customer[i].cash);
            if(customer[i].cash < 0 )
            {
                printf("\ncash must be grater than or equal 0 :\n");
                goto reenter_cash;
            }

            return 0 ;
        }

    }
    printf("\nerror : not existing customer id \ngive another id\n ");
    scanf("%i",&id_check);
    goto idcheck ;
}
void print_customer(struct customer_s * customer)
{
 printf("\nenter customer id to print it :\n");
    scanf("%i",&id_check);
    idcheck3 :
    for(i = 0 ; i < 3 ; i++ )
    {
        if (id_check == customer[i].id)
        {

            printf("customer name is : ");
            puts(customer[i].name);
            printf("customer type is : ");
            puts(customer[i].customertype);
            printf("customer  ID  is : ");
            printf("%i\n",customer[i].id);
            printf("customer cash is : ");
            printf("%lf\n",customer[i].cash);
            printf("\n\n");
            return 0 ;
        }

    }
    printf("\nerror : not existing customer id \ngive another id\n");
    scanf("%i",&id_check);
    goto idcheck3 ;
}
void trans_money (int source_id , int destination_id ,double cashmoney)
{
    int founded =0,i=0,j=0,indexto=0;
    printf("\nplease enter the destination id :");
    destination_id_check :
    scanf("%i",&destination_id);
    for(j = 0 ; j < 3 ; j++ )
    {
        if (destination_id == customer[j].id)
            { indexto = j ;founded = 1  ;}
        if( j==2 && founded == 0)
        {
            printf("\nerror : not existing destination id \ngive another id\n ");
            goto destination_id_check ;
        }
    }
    founded = 0 ;
    printf("\nplease enter the source id :");
    source_id_check :
    scanf("%i",&source_id);
    for(i = 0 ; i < 3 ; i++ )
    {
        if (source_id == customer[i].id)
        {
            printf("\nplease enter the cash money to transfer:");
            reenter_cash_money :
            scanf("%lf",&cashmoney);
            if(customer[i].cash >= cashmoney)
                {
                        customer[i].cash = customer[i].cash - cashmoney;
                        customer[indexto].cash = customer[indexto].cash + cashmoney;
                        return 0 ;
                }
            else
               {
                 printf("\nmoney wanted to transfer is larger than the current cash in this account:\nreenter cash money to transfer\n");
                 goto reenter_cash_money;
               }

            founded = 1  ;
        }
        if( i==2 && founded == 0)
        {
            printf("\nerror : not existing source id \ngive another id\n ");
            goto source_id_check ;
        }
    }
    return 0 ;
}
void printall(struct customer_s *customer , int size)
{
   for(i = 0 ; i < index ; i++ )
    {
            if(i == deleted_customer)
                continue;
            printf("customer name is : ");
            puts(customer[i].name);
            printf("customer type is : ");
            puts(customer[i].customertype);
            printf("customer  ID  is : ");
            printf("%i\n",customer[i].id);
            printf("customer cash is : ");
            printf("%lf\n",customer[i].cash);
            printf("\n\n");
    }

}
void delete_customer ( )
{
    int customer_id=0,i=0;
    printf("\nplease enter customer id to delete : ");
    reenteriddddd :
    scanf("%i",&customer_id);
    for(i =0 ; i < index ; i++ )
    {
        if(customer_id == customer[i].id)
        {

            customer[i].cash = -1 ;
            customer[i].id = -1 ;
            strcpy(customer[i].name,"-1" );
            strcpy(customer[i].customertype,"-1");
            //index--;
            deleted_customer = i;
        }
        else
        {
            printf("\nnot existing id:\nplease reenter id:");
            goto reenteriddddd;
        }

    }










}
int main()
{
    int x,y;double z = 0;
    printf("\nBANKER VIEW :\n");
    while(1)
    {
        printf("\n\nSelect one of the following options : \n\n");
        printf("1 : create new customer\n2 : edit on customer\n3 : delete customer\n4 : print customer\n5 : money transfer\n6 : print all data base\n7 : exist mode\n");;
        printf("whats your choice : ");
        fflush(stdin);
        scanf("%c",&choice);
        printf("\n");
        switch(choice)
            {
                case  '1' :
                    if(index == 3) // just 3 customers
                    {
                        printf("\n\narray is full :\nyou can't add more customers\n\n");
                        break;
                    }
                    create_new_customer(customer);
                    break;
                case '2' :
                    edit_customer(customer);
                    break;
                case '3' :
                    delete_customer();
                    break;
                case '4' :
                    print_customer(customer);
                    break;
                case '5' :
                    trans_money(x , y ,  z);
                    break;
                case '6' :
                    printall(customer ,sizeof(customer)/sizeof(struct customer_s));
                    break;
                case '7' :
                    printf("\nEnd of program : ");
                    exit(0);
                    break;
                default :
                    printf("\nwrong choice :");
            }

    }
return 0;
}
