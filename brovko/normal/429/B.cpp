#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[1005][1005], dp[1005][1005][4][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {

            if(i > 0)
                dp[i][j][0][0] = max(dp[i - 1][j][0][0], dp[i - 1][j][0][1]) + a[i - 1][j];

            if(j > 0)
                dp[i][j][0][1] = max(dp[i][j - 1][0][0], dp[i][j - 1][0][1]) + a[i][j - 1];
        }

    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
        {
            if(i < n - 1)
                dp[i][j][1][0] = max(dp[i + 1][j][1][0], dp[i + 1][j][1][1]) + a[i + 1][j];

            if(j < m - 1)
                dp[i][j][1][1] = max(dp[i][j + 1][1][0], dp[i][j + 1][1][1]) + a[i][j + 1];
        }

    for(int i = 0; i < n - 1; i++)
        for(int j = m - 1; j >= 0; j--)
        {
            if(i > 0)
                dp[i][j][2][0] = max(dp[i - 1][j][2][0], dp[i - 1][j][2][1]) + a[i - 1][j];

            if(j < m - 1)
                dp[i][j][2][1] = max(dp[i][j + 1][2][0], dp[i][j + 1][2][1]) + a[i][j + 1];
        }

    for(int i = n - 1; i >= 0; i--)
        for(int j = 0; j < m; j++)
        {
            if(i < n - 1)
                dp[i][j][3][0] = max(dp[i + 1][j][3][0], dp[i + 1][j][3][1]) + a[i + 1][j];

            if(j > 0)
                dp[i][j][3][1] = max(dp[i][j - 1][3][0], dp[i][j - 1][3][1]) + a[i][j - 1];
        }

    int ans = 0;

    for(int i = 1; i < n - 1; i++)
        for(int j = 1; j < m - 1; j++)
            ans = max({ans, dp[i][j][0][0] + dp[i][j][1][0] + dp[i][j][2][1] + dp[i][j][3][1], dp[i][j][0][1] + dp[i][j][1][1] + dp[i][j][2][0] + dp[i][j][3][0]});

    cout << ans;
}