#include <iostream>

using namespace std;

bool dp[501][501][501] = {0}, dp2[501][501];
int c[501];

void calc(int n, int k)
{
    dp[0][0][0] = 1;

    for (int j = 1; j <= k; ++j)
        for (int x = 0; x <= j; ++x)
            dp[0][j][x] = 0;

    for (int i = 0; i <= n; ++i)
    {
        dp2[i][0] = 1;
        dp[i][0][0] = 1;
    }

    for (int j = 1; j <= k; ++j)
        dp2[0][j] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            dp2[i][j] = dp2[i - 1][j];

            if (j >= c[i])
                dp2[i][j] |= dp2[i - 1][j - c[i]];

            dp[i][j][0] = dp2[i][j];

            if (!dp2[i][j])
                continue;

            for (int x = 1; x <= j; ++x)
            {
                dp[i][j][x] = dp[i - 1][j][x];

                if (x >= c[i])
                {
                    dp[i][j][x] |= dp[i - 1][j - c[i]][x - c[i]];
                }

                if (j >= c[i] and x <= j - c[i])
                    dp[i][j][x] |= dp[i - 1][j - c[i]][x];

            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k, ans = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    calc(n, k);

    for (int i = 0; i <= k; ++i)
    {
        if (dp[n][k][i])
            ++ans;
    }

    cout << ans << '\n';

    for (int i = 0; i <= k; ++i)
    {
        if (dp[n][k][i])
            cout << i << ' ';
    }

    return 0;
}