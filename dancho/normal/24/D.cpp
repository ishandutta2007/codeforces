#include <cstdio>
#include <cstring>

int n, m;

double x[1024][1024], y[1024][1024];
double dp[1024][1024];

int main()
{
    memset(dp, -1, sizeof(dp));
    int a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int j = 0; j <= m; ++j)
        dp[n][j] = 0;
    if (m == 1)
    {
        printf("%d\n", 2 * (n - a));
        return 0;
    }

    for (int i = n - 1; i >= a; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j == 1)
            {
                // dp[i][j] = 1 + 1/3 * (dp[i + 1][j] + dp[i][j] + dp[i][j + 1])

                double c = 1.0 - 1.0 / 3;
                // c * dp[i][j] = 1 + 1/3 * (dp[i + 1][j] + dp[i][j + 1]);
                x[i][j] = 1.0 / c + 1.0 / 3 * dp[i + 1][j] / c;
                y[i][j] = 1.0 / 3 / c;
            }
            else if (j < m)
            {
                // dp[i][j] = 1 + 1/4 * (dp[i + 1][j] + dp[i][j-1] + dp[i][j] + dp[i][j+1])
                // dp[i][j] = 1 + 1/4 * (dp[i + 1][j] + x[i][j-1] + y[i][j-1] * dp[i][j] + dp[i][j] + dp[i][j+1])

                double c = 1.0 - 1.0 / 4 * (1.0 + y[i][j - 1]);
                x[i][j] = 1.0 / c + 1.0 / 4 / c * (dp[i + 1][j] + x[i][j - 1]);
                y[i][j] = 1.0 / 4 / c;
            }
            else if (j == m)
            {
                // dp[i][j] = 1 + 1/3 * (dp[i + 1][j] + dp[i][j - 1] + dp[i][j])
                // dp[i][j] = 1 + 1/3 * (dp[i + 1][j] + x[i][j - 1] + y[i][j - 1] * dp[i][j] + dp[i][j])

                double c = 1.0 - 1.0 / 3 * (y[i][j - 1] + 1.0);
                dp[i][j] = (1.0 + 1.0 / 3 * (dp[i + 1][j] + x[i][j - 1])) / c;
            }
        }
        for (int j = m - 1; j > 0; --j)
        {
            dp[i][j] = x[i][j] + y[i][j] * dp[i][j + 1];
        }
    }
    printf("%.10lf\n", dp[a][b]);
    return 0;
}