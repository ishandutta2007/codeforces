#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, mod=1e9+7;
int f[sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int c(int n, int k)
{
    return (1ll*f[n]*po((1ll*f[n-k]*f[k])%mod, mod-2))%mod;
}
int s(int n, int k)
{
    if(k>n) return 0;
    int re=0;
    for(int a=1; a<=k; a++)
    {
        int q=(1ll*c(k, a)*po(a, n))%mod;
        if((k-a)%2) q=(mod-q)%mod;
        re=(re+q)%mod;
    }
    re=(1ll*re*po(f[k], mod-2))%mod;
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, su=0;
    cin>>n>>k;
    f[0]=1;
    for(int a=1; a<=n; a++) f[a]=(1ll*f[a-1]*a)%mod;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        su=(su+x)%mod;
    }
    cout<<(1ll*su*((s(n, k)+1ll*(n-1)*s(n-1, k))%mod))%mod;
}