#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
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
int de(int x, int y){return (1ll*x*po(y, mod-2))%mod;}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, l;
    cin>>n>>k>>l;
    l=de(l%mod, 2*n+1);
    int dp[2*n+1][n+1], dp2[2*n+1][n+1];
    for(int a=0; a<=2*n; a++) for(int b=0; b<=n; b++) dp[a][b]=0, dp2[a][b]=0;
    dp2[0][0]=1;
    for(int a=0; a<2*n; a++)
    {
        for(int b=0; b<=n; b++)
        {
            if(dp2[a][b])
            {
                if(b)
                {
                    int wq=(1ll*dp2[a][b]*b)%mod;

                    dp2[a+1][b-1]=(dp2[a+1][b-1]+wq)%mod;

                    int add=(1ll*dp[a][b]*b)%mod;
                    if(b-1>=k) add=(add+1ll*l*wq)%mod;

                    dp[a+1][b-1]=(dp[a+1][b-1]+add)%mod;
                }
                if(b+1<=n*2-a-1)
                {
                    dp2[a+1][b+1]=(dp2[a+1][b+1]+dp2[a][b])%mod;

                    int add=dp[a][b];
                    if(b+1>=k) add=(add+1ll*l*dp2[a][b])%mod;

                    dp[a+1][b+1]=(dp[a+1][b+1]+add)%mod;
                }
            }
        }
    }
    cout<<de(dp[2*n][0], dp2[2*n][0]);
}