#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MOD = 1e9 + 7;

int t, n, k, dp[1005][1005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i <= n; i++)
            dp[i][1] = 1;

        for(int j = 1; j <= k; j++)
        {
            dp[0][j] = 1;

            for(int i = 1; i <= n; i++)
                dp[i][j] = add(dp[i - 1][j], dp[n - i][j - 1]);
        }

        cout << dp[n][k] << "\n";
    }
}