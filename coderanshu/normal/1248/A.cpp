#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long t,e1=0,e2=0,j,n,m,a[100003];
   cin>>t;
   for(int i=0;i<t;i++)
   {
       e1=0,e2=0;
       cin>>n;
       for(j=0;j<n;j++)
       {
           cin>>a[j];
           if(a[j]%2==0)e1++;
       }
       cin>>m;
       for(j=0;j<m;j++)
       {
           cin>>a[j];
           if(a[j]%2==0)e2++;
       }
       cout<<(e1*e2)+(n-e1)*(m-e2)<<"\n";
   }
   return 0;
}