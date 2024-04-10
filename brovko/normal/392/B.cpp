#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, dp[3][3][45], a[3][3];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
            dp[i][j][0] = a[i][j];
        }

    for(int k = 0; k < 3; k++)
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                dp[i][j][0] = min(dp[i][j][0], dp[i][k][0] + dp[k][j][0]);

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        for(int x = 0; x < 3; x++)
            for(int y = 0; y < 3; y++)
                if(x != y)
                {
                    int z = 3 - x - y;

                    dp[x][y][i] = min(dp[x][z][i - 1] + a[x][y] + dp[z][y][i - 1], dp[x][y][i - 1] + a[x][z] + dp[y][x][i - 1] + a[z][y] + dp[x][y][i - 1]);
                }

        for(int z = 0; z < 3; z++)
            for(int x = 0; x < 3; x++)
                for(int y = 0; y < 3; y++)
                    dp[x][y][i] = min(dp[x][y][i], dp[x][z][i] + dp[z][y][i]);
    }

    cout << dp[0][2][n - 1];
}