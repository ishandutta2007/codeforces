#include<bits/stdc++.h>
using namespace std;
#define ll long int
 
int main()
{
    ios_base::sync_with_stdio(0);
    ll x,y,n,i,m=1000000007,f[6];
    cin>>x>>y>>n;
    f[1]=x%m;f[2]=y%m;f[3]=(y-x)%m;f[4]=(-x)%m;f[5]=(-y)%m;f[0]=(x-y)%m;
    cout<<(f[n%6]+m)%m;
    
    return 0;
}