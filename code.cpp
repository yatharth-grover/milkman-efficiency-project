#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<process.h>
#include<time.h>

using namespace std;
int completed[10],n1,cost=0;
int ary[10][10];
int ret;
int sum;
bool mem[10000][10000];

void takeInput()
{
    int i,j;

    printf("\nEnter the Transportation Cost Matrix\n");

    for(i=0;i < n1;i++)
    {
        for( j=0;j < n1;j++)
            scanf("%d",&ary[i][j]);
        completed[i]=0;
    }
}

void find(vector<vector<int> >& mem_coinage,int row,int col,int ret,int deno[])
{
    int j,flag=0;
    if(ret==0)
    {
       return ;
    }
    if(ret!=0)
    {
        for(j=row; j>=0; j--)
        {
            if(mem_coinage[j][col]==mem_coinage[j-1][col])
            {
                flag=0;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"\n Denomination: "<<deno[j-1]<<endl;
            row=j;
            col=ret-deno[j-1];
            ret=ret-deno[j-1];
        }
        find(mem_coinage,row,col,ret,deno);
    }
}

int find_min(int a,int b)
{
    int s1;
        if(a<b)
            s1=a;
        else
            s1=b;
        return s1;
}
int least(int c)
{
        int i,nc=999;
        int min=999,kmin;
        for(i=0;i < n1;i++)
        {
            if((ary[c][i]!=0)&&(completed[i]==0))
                if(ary[c][i]+ary[i][c] < min)
                {
                    min=ary[i][0]+ary[c][i];
                    kmin=ary[c][i];
                    nc=i;
                }
        }
        if(min!=999)
            cost+=kmin;
        return nc;
}
int coin_change(int deno[],int size_deno,vector<vector<int> >& quan)
{
    int i,j,x,y;
    int mem_coinage[size_deno+1][ret+1];
    for(i=0; i<size_deno+1; i++)
    {
        for(j=0; j<ret+1; j++)
        {
            mem_coinage[i][j]=0;
        }
    }

    for(j=0; j<=ret; j++)
        mem_coinage[0][j]=99999;
    for(i=1; i<=size_deno; i++)
        mem_coinage[i][0]=0;

    for(i=1; i<=size_deno; i++)
    {
        for(j=1; j<=ret; j++)
        {
            if(deno[i-1]<=j)
                mem_coinage[i][j]=find_min((1+mem_coinage[i][j-deno[i-1]]),mem_coinage[i-1][j]);
            else
                mem_coinage[i][j]=mem_coinage[i-1][j];
        }
    }
    for(i=0; i<size_deno+1; i++)
    {
        quan.push_back(vector<int>());
         for(j=0; j<ret+1; j++)
        {
            quan[i].push_back(mem_coinage[i][j]);
        }
    }
    return mem_coinage[size_deno][ret];
}

void mincost(int city)
{
    int i,ncity;
    completed[city]=1;
    cout<<city+1<<"--->";
    ncity=least(city);
    if(ncity==999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=ary[city][ncity];
        return;
    }

    mincost(ncity);
}
void memrecur(int i,int j,int arr[],vector<int>& p,vector<vector<int> >& myVector,vector<int>& p1,vector<vector<int> >& quant,int quality[])
{
    if(j<0)
    {
        return;
    }
    if(i<=0)
    {
        int su=0;
        for(int k=0;k<p.size();k++)
        {
            su+=p[k];
        }
        if(su==sum)
        {
            myVector.push_back(p);
            quant.push_back(p1);
        }
        return;
    }
    if((j-arr[i]>=0)&&(mem[i-1][j-arr[i]]==true))
    {
        p.push_back(arr[i]);
        p1.push_back(quality[i]);
        memrecur(i-1,j-arr[i],arr,p,myVector,p1,quant,quality);
        int pos=0;
        for (int k =0;k< p.size();k++)
        {
            if(p[k]==arr[i])
            {
                pos=k;
            }
        }
        while(pos<p.size())
        {
            p.pop_back();
            p1.pop_back();
            pos++;
        }
    }
    if((i-1>=0)&&(mem[i-1][j]==true))
    {
        memrecur(i-1,j,arr,p,myVector,p1,quant,quality);
    }
    return;
}
COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int main()
{
    gotoxy(1,2);
	cout<<  "\t\t    ��      �� ������� ��      ������� ������� ���� ���� �������";
    cout<<"\n\t\t    ��      �� ��      ��      ��      ��   �� �� ��� �� ��     ";
    cout<<"\n\t\t    ��  ��  �� �����   ��      ��      ��   �� ��  �  �� �����  ";
    cout<<"\n\t\t    ��  ��  �� ��      ��      ��      ��   �� ��     �� ��     ";
    cout<<"\n\t\t    ���������� ������� ������� ������� ������� ��     �� �������";
	gotoxy(6,9);
	cout << "\t\t **************************************************************" << endl;
	gotoxy(6,10);
	cout << "\t\t              ALGORITHM AND PROBLEM SOLVING PROJECT                     " << endl;
	gotoxy(6,11);
	cout << "\t\t **************************************************************" << endl;
    cout<<"\t\t\t      S H Y A M  D A I R Y  P R O B L E M ";
    cout<<endl<<endl<<"\n\t\t\t\t Made By: \n\t\t\t Yatharth Grover(9922103119)"<<endl;
    delay(4000);
    system("cls");
    int cust_quantity[n1],sum_quantity=0,quantity,lo=0;
    printf("Enter the number of customers: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        cout<<"\n\t\t Enter the quantity of milk required by Customer "<<i+1<<": ";
        cin>>quantity;
        cust_quantity[lo]=quantity;
        lo++;
        sum_quantity+=quantity;
    }
    sum=sum_quantity;

    int i,j=0;
    int arr[]={0,2,1,3,7,5,6,8,10,12,15,18,27,22,25,50};              //milking capacity of each cows(quantity)
    int quality[]={0,25,15,45,66,89,24,70,99,53,15,87,23,65,43,68};   //percentage purity of cows
    int n=15;
    for(i=0;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                int temp1=quality[i];
                quality[i]=quality[j];
                quality[j]=temp1;
            }
        }
    }

    for(i=0;i<=n;i++)
    {
        mem[i][0]=true;
    }

    for(i=1;i<=sum;i++)
    {
        mem[0][i]=false;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(arr[i]>j)
            {
                mem[i][j]=mem[i-1][j];
            }
            else
            {
               if(mem[i-1][j]==true)
               {
                   mem[i][j]=mem[i-1][j];
               }
               else
               {
                   mem[i][j]=mem[i-1][j-arr[i]];
               }
            }

        }
    }

    vector<int> ss;
    vector< vector<int> > myVector;
    vector<int> qs;
    vector< vector<int> > quant;

    memrecur(n,sum,arr,ss,myVector,qs,quant,quality);

    float weighted_average[myVector.size()];
    for (int i = 0; i < myVector.size(); i++)
    {
        float sumw=0.0;
        float sumww=0.0;
        for(int j=0;j<myVector[i].size();j++)
        {
            sumw=sumw+myVector[i][j]*quant[i][j];
            sumww+=myVector[i][j];
        }
    weighted_average[i]=sumw/sumww;
    }

    int max=0;
    int pos=-1;

    for(int i=0;i<myVector.size();i++)
    {
        if(max<weighted_average[i])
        {
            max=weighted_average[i];
            pos=i;
        }
    }
    cout<<"\n\n\t\t IN ORDER TO OBTAIN PUREST MILK, MILK COWS WITH MILKING CAPACITY\n\t\t";

    for(int j=0;j<myVector[pos].size();j++)
    {
        cout<<"\t "<<myVector[pos][j]<<"L  ";
    }
    cout<<endl;


    takeInput();
    mincost(0); //passing 0 because starting vertex
    cout<<"\n\n\t\t Minimum cost of transportation for Shyam "<<cost<<endl;

//####################################################### COINAGE PROBLEM #####################################################################

    int deno[]= {1,2,5,10,20,50,100,200,500,1000,2000};
    int size_deno=sizeof(deno)/sizeof(deno[0]);

    int amt,cust;
    for(int z=0;z<lo;z++)
    {
      amt=cust_quantity[z]*45;
      A:
        cout<<"\n\t Total cost of milk for customer"<<z+1<<": "<<amt;
        cout<<"\n\t Amount of money customer "<<z+1<<" has given:";
        cin>>cust;
        ret=cust-amt;

        vector< vector<int> > Vec;
        if(ret>0)
        {
           int change=coin_change(deno,size_deno,Vec);
           cout<<"\nAmount to be returned by Shyam:"<<ret<<endl;
           cout<<"\n----Shyam should return the following denomination(s) to the customer---- ";
           find(Vec,size_deno,ret,ret,deno);
           cout<<"------------------------------------------------------------------------------------------------------------------\n";
        }
        else
        {
           cout<<"\n-----PLEASE GIVE  "<<(ret)*-1<<" .RS MORE-----";
           cout<<"---------------------------------------------------------------------------";
           goto A;
         }
    }
    return 0;
}
