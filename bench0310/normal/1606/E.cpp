#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    int n,x;
    cin >> n >> x;
    int m=max(n,x);
    vector c(n+1,vector(n+1,ll(0)));
    for(int i=0;i<=n;i++) c[i][0]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=add(c[i-1][j],c[i-1][j-1]);
    vector p(m+1,vector(m+1,ll(0)));
    for(int i=0;i<=m;i++) p[i][0]=1;
    for(int i=0;i<=m;i++) for(int j=1;j<=m;j++) p[i][j]=mul(p[i][j-1],i);
    vector dp(n+1,vector(x+1,ll(0)));
    for(int j=0;j<=x;j++) dp[0][j]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            ll &d=dp[i][j];
            if(j<=i-1) d=p[j][i];
            else
            {
                for(int k=0;k<=i;k++)
                {
                    d=add(d,mul(mul(c[i][k],p[i-1][i-k]),dp[k][j-(i-1)]));
                }
            }
            
        }
    }
    cout << dp[n][x] << "\n";
    return 0;
}