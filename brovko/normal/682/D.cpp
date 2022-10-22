#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, m, k, a[1005][1005], dp[1005][1005][15];
string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> s >> t;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        if(s[i] == t[j])
        {
            if(i == 0 || j == 0)
                a[i][j] = 1;
            else a[i][j] = 1 + a[i - 1][j - 1];
        }
    }

    int ans = 0;

    for(int p = 1; p <= k; p++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(i > 0)
                    dp[i][j][p] = max(dp[i][j][p], dp[i - 1][j][p]);

                if(j > 0)
                    dp[i][j][p] = max(dp[i][j][p], dp[i][j - 1][p]);

                if(i >= a[i][j] && j >= a[i][j])
                    dp[i][j][p] = max(dp[i][j][p], dp[i - a[i][j]][j - a[i][j]][p - 1] + a[i][j]);

                else dp[i][j][p] = max(dp[i][j][p], a[i][j]);

                ans = max(ans, dp[i][j][p]);
            }

    cout << ans;
}