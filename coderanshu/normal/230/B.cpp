#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   ll n,m,x,y,j,k;
   cin>>n;
   for(ll i=0;i<n;i++)
   {
       cin>>m;
       x=sqrt(m);
       if(x==1 || x*x!=m){ cout<<"NO\n"; continue; }
       y=1;k=sqrt(x);
       for(j=2;j<=k;j++)
       {
           if(x%j==0){cout<<"NO\n";y=0;break;}
       }
       if(y)cout<<"YES\n";
   }
    return 0;
}