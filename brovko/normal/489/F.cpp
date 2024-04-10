#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long

using namespace std;

int n, m, MOD, k[505];
char a[505][505];
int dp[505][505][2];

int add(int x, int y)
{
    x += y;

    if(x >= MOD)
        x -= MOD;

    return x;
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

    cin >> n >> m >> MOD;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];

            if(a[i][j] == '1')
                k[j]++;
        }

    int x = 0, y = 0;

    for(int i = 0; i < n; i++)
    {
        if(k[i] == 1)
            x++;

        if(k[i] == 0)
            y++;
    }

    dp[x][y][0] = 1;

//    cout << dp[0][3][0] << endl;

    for(int i = m - 1; i < n - 1; i++)
    {
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= n; k++)
                if(dp[j][k][0])
                {
                    if(j >= 2)
                        dp[j - 2][k][1] = add(dp[j - 2][k][1], mul(dp[j][k][0], (j - 1) * j >> 1));

                    if(k >= 1 && j >= 1)
                        dp[j][k - 1][1] = add(dp[j][k - 1][1], mul(dp[j][k][0], j * k));

                    if(k >= 2)
                        dp[j + 2][k - 2][1] = add(dp[j + 2][k - 2][1], mul(dp[j][k][0], (k - 1) * k >> 1));
                }

        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= n; k++)
            {
                dp[j][k][0] = dp[j][k][1];
                dp[j][k][1] = 0;
            }

//        cout << dp[0][1][0] << ' ' << dp[0][0][0] << endl;
    }

    cout << dp[0][0][0];
}