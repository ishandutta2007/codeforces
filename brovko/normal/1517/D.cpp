#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int n, m, k, a[505][505], b[505][505], dp[505][505][25];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m - 1; j++)
            cin >> a[i][j];

    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m; j++)
            cin >> b[i][j];

    for(int z = 1; z <= k; z++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                dp[i][j][z] = 1e18;

                if(i > 0)
                    dp[i][j][z] = min(dp[i][j][z], dp[i - 1][j][z - 1] + b[i - 1][j]);

                if(i < n - 1)
                    dp[i][j][z] = min(dp[i][j][z], dp[i + 1][j][z - 1] + b[i][j]);

                if(j > 0)
                    dp[i][j][z] = min(dp[i][j][z], dp[i][j - 1][z - 1] + a[i][j - 1]);

                if(j < m - 1)
                    dp[i][j][z] = min(dp[i][j][z], dp[i][j + 1][z - 1] + a[i][j]);
            }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            if(dp[i][j][k / 2] == 1e18 || k % 2 != 0)
                cout << -1 << ' ';
            else cout << dp[i][j][k / 2] * 2 << ' ';

        cout << "\n";
    }
}