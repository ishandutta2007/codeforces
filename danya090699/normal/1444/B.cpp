#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int q=1, t=1;
    for(int a=2*n; a>n; a--) q=1ll*q*a%mod;
    for(int a=1; a<=n; a++) t=1ll*t*a%mod;
    q=1ll*q*po(t, mod-2)%mod;

    int ar[n*2], su=0;
    for(int a=0; a<n*2; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n*2);
    for(int a=0; a<n; a++)
    {
        su-=(ar[a]%mod);
        if(su<0) su+=mod;
    }
    for(int a=n; a<n*2; a++) su=(su+ar[a])%mod;
    cout<<1ll*su*q%mod;
}