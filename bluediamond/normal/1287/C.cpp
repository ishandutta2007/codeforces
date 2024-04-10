#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
const int INF = (int) 1e9;
int n;
int a[N];
int dp[N][N][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] == 0)
    {
        dp[1][0][0] = 0;
        dp[1][1][1] = 0;
    }
    else
    {
        dp[1][a[1] % 2][a[1] % 2] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int x = 0; x <= 1; x++)
            {
                int l, r;
                if (a[i + 1] == 0)
                {
                    l = 0;
                    r = 1;
                }
                else
                {
                    l = r = a[i + 1] % 2;
                }
                for (int y = l; y <= r; y++)
                {
                    dp[i + 1][j + y][y] = min(dp[i + 1][j + y][y], (x != y) + dp[i][j][x]);
                }
            }
        }
    }
    cout << min(dp[n][n - n / 2][0], dp[n][n - n / 2][1]) << "\n";
}