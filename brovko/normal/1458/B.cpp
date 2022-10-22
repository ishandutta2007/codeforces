#include <bits/stdc++.h>
//#define int long long
#define ld long double

using namespace std;

int n, a[105], b[105], dp[105][105][10005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    for(int k = 1; k < 10005; k++)
    {
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                dp[i][j][k] = -1e9;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 0; k < 10005; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k];

                if(k - a[i - 1] >= 0)
                    dp[i][j][k] = max(dp[i][j][k],  dp[i - 1][j - 1][k - a[i - 1]] + b[i - 1]);
            }

    int s = 0;

    for(int i = 0; i < n; i++)
        s += b[i];

    for(int j = 1; j <= n; j++)
    {
        ld ans = 0;

        for(int k = 0; k < 10005; k++)
            ans = max(ans, min((ld)(dp[n][j][k] + s) / 2, (ld)k));

        cout << setprecision(50) << ans << ' ';
    }
}