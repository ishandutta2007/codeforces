#include<bits/stdc++.h>
using namespace std;

int main()
{
   long int n,k,count,i,ans=0,num;
   cin>>n>>k;
   for(i=0;i<n;i++)
   {
       count=0;
       cin>>num;
       while(num!=0 && count<=k)
       {
           if(num%10==4 || num%10==7)count++;
           num/=10;
       }
       if(count<=k)ans++;
   }
   cout<<ans;
    return 0; 
}