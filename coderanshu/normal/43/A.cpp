#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,i,sc=0,sb=0;
   char a[12],b[12],c[12];
   cin>>n;
   for(i=0;i<n;i++)
   {
       cin>>a;
       if(i==0)
       {
           strcpy(b,a);sb++;
       }
       else{
           if(strcmp(a,b)==0)sb++;
           else
           {
               if(sc==0)
               strcpy(c,a);
               sc++;
           }
           
       }
   }
   (sc>sb)?cout<<c:cout<<b;
    return 0;
}