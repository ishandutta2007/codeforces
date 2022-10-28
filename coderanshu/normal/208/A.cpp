#include<bits/stdc++.h>
using namespace std;

int main()
{
   char a[202];
   cin>>a;
   int i,flag=0;
   for(i=0;i<strlen(a);i++)
   {
      
       if(a[i]=='W' && a[i+1]=='U' && a[i+2]=='B' && i<=strlen(a)-3)
       {
          
           if(i==0 || flag==2)flag=2;
           else flag=1;
           i+=2;
           
       }
       else 
       {
           if(flag==1)cout<<" ";
           cout<<a[i];
           flag=0;
           
       }
   }
  
   return 0; 
}