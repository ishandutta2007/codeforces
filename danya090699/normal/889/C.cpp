#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int po(int x, int y)
{
    if(y==0) return 1;
    else
    {
        if(y&1) return (1ll*x*po(x, y-1))%mod;
        else
        {
            int x2=po(x, y/2);
            return (1ll*x2*x2)%mod;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, su=0;
    cin>>n>>k;
    int ar[n], f[n+1];
    ar[0]=1, f[0]=1;
    for(int a=1; a<=n; a++) f[a]=(1ll*f[a-1]*a)%mod;
    for(int a=1; a<n; a++)
    {
        su=(1ll*su*(a-1)+ar[a-1])%mod;
        if(a-k-1>=0)
        {
            su-=(ar[a-k-1]*((1ll*f[a-1]*po(f[a-k-1], mod-2))%mod))%mod;
            if(su<0) su+=mod;
        }
        ar[a]=su;
    }
    int an=f[n];
    su=1;
    for(int a=n-1; a>=0; a--)
    {
        an-=(1ll*ar[a]*su)%mod;
        if(an<0) an+=mod;
        su=(1ll*su*a)%mod;
    }
    cout<<an;
}