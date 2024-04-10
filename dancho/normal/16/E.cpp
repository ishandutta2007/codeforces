#include <cstdio>
#include <cstring>

int n;
double a[32][32];
double dp[1 << 18];
double sl[32];

double solve(int ma)
{
    if (dp[ma] == dp[ma])
    {
        return dp[ma];
    }
    int k = __builtin_popcount(ma) + 1;
    dp[ma] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ma & (1 << i))
        {
            for (int j = 0; j < n; ++j)
            {
                if (!(ma & (1 << j)))
                {
                    dp[ma] += 1.0 / (k * (k - 1) / 2) * a[i][j] * solve(ma | (1 << j));
                }
            }
        }
    }
    return dp[ma];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%lf", &a[i][j]);
    dp[(1 << n) - 1] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i + 1 < n)
            printf("%.10lf ", solve(1 << i));
        else
            printf("%.10lf\n", solve(1 << i));
    }
    return 0;
}