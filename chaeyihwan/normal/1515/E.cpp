#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[2][402][402];
ll Inv[402];

ll inv(ll x, ll M)
{
    int t = 0; ll ans = 1;
    while((1LL<<t) <= M-2)
    {
        if((1LL << t) & M-2)
        {
            ans *= x;
            ans %= M;
        }
        x = (x * x)%M;
        t++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; ll M; cin >> n >> M;
    dp[0][1][1] = 1;
    for(int k=1;k<=n;k++)
    {
        Inv[k] = inv(k, M);
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=i/2;j<=i;j++)
        {
            for(int k=1;k<=j;k++)
            {
                dp[1][j][0] = (dp[1][j][0] + dp[0][j][k])%M;
            }
            dp[1][j][1] = (dp[0][j-1][0] * j)%M;
            for(int k=2;k<=j;k++)
            {
                dp[1][j][k] = (dp[0][j-1][k-1] * 2)%M;
                dp[1][j][k] = (dp[1][j][k] * j)%M;
                dp[1][j][k] = (dp[1][j][k] *Inv[k])%M;
            }
        }

        for(int j=i/2;j<=i;j++)
        {
            for(int k=0;k<=j;k++)
            {
                dp[0][j][k] = dp[1][j][k];
            }
        }
        for(int j=i/2;j<=i;j++)
        {
            for(int k=0;k<=j;k++)
            {
                dp[1][j][k] = 0;
            }
        }
    }
    ll ans = 0;

    for(int j=n/2;j<=n;j++)
    {
        for(int k=1;k<=j;k++)
        {
            ans += dp[0][j][k];
            ans %= M;
        }
    }

    cout << ans;
}