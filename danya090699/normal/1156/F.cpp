#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10, mod=998244353;
int q[sz], dp[sz][sz], inv[sz];
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
int de(int x, int y)
{
    return (1ll*x*inv[y])%mod;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    for(int a=0; a<=n; a++) inv[a]=po(a, mod-2);
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        q[x]++;
    }
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        int su=0;
        for(int b=0; b<=n; b++)
        {
            if(q[b])
            {
                an=(an+1ll*dp[a][b]*de(q[b]-1, n-a))%mod;
                dp[a+1][b]=(1ll*su*de(q[b], n-a))%mod;
            }
            su=(su+dp[a][b])%mod;
        }
    }
    cout<<an;
}