#include <cmath>
#include <cstdio>
#include <cstring>

int n, m;
int a[64];
int cdep;

double com[64][64];

double gcom(int n, int k)
{
    if (com[n][k] == com[n][k])
        return com[n][k];
    if (n < k)
        return 0;
    if (k == 0)
        return 1;
    if (n == 0)
        return 1;

    com[n][k] = gcom(n - 1, k - 1) + gcom(n - 1, k);
    return com[n][k];
}

double dp[64][64];

double getDP(int p, int c)
{
    if (dp[p][c] == dp[p][c])
    {
        return dp[p][c];
    }
    if (c == 0)
    {
        return 1.0;
    }
    if (p == m)
    {
        return 0.0;
    }
    double ans = 0.0;
    for (int i = 0; i <= c; ++i)
    {
        int mq = (i + a[p] - 1) / a[p];
        int r = m - p;
        if (mq <= cdep)
        {
            ans += gcom(c, i) * pow(1.0 / r, i) * pow(1.0 - 1.0 / r, c - i) * getDP(p + 1, c - i);
        }
    }
    dp[p][c] = ans;

    return dp[p][c];
}

int main()
{
    memset(com, -1, sizeof(com));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &a[i]);

    double ans = 0;
    double prev = 0;

    for (cdep = 1; cdep <= n; ++cdep)
    {
        memset(dp, -1, sizeof(dp));
        ans += (getDP(0, n) - prev) * cdep;
        prev = getDP(0, n);
    }
    printf("%.11lf\n", ans);

    return 0;
}