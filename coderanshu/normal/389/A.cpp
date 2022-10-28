#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,i,t;
   cin>>n;
   int a[n];
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }
   sort(a,a+n);
   while(a[0]!=a[n-1])
   {
       t=a[n-1]%a[0];
       if(t==0)t=a[0];
       for(i=n-1;i>0;i--)
       {
           a[i]=a[i-1];
       }
       a[0]=t;
   }
   cout<<n*a[0];
    return 0;
}