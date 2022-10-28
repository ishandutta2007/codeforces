#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,x,y,z,a[3],i;
   cin>>n;
   for(i=0;i<n;i++)
   {
       cin>>x>>y>>z;
       if(i==0)
       {
       a[0]=x;a[1]=y;a[2]=z;
       }
       else {
           a[0]+=x;
           a[1]+=y;
           a[2]+=z;
       }
   }
  if(a[0]==0 && a[1]==0 && a[2]==0)
  cout<<"YES";
  else cout<<"NO";
   return 0; 
}