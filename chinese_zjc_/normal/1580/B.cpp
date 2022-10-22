// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, k;
long long dp[105][105][105], p, P[105], C[105][105];
// dp[a][b][c] abc
long long dfs(int a, int b, int c)
{
    if (a < c)
        return 0;
    if (a == 0 && c == 0)
        return 1;
    if (b == 1)
        return c == 1 ? P[a] : 0;
    if (~dp[a][b][c])
        return dp[a][b][c];
    long long &v = dp[a][b][c];
    v = 0;
    for (int i = 1; i <= a; ++i)
    {
        for (int j = std::max(0, i + c - a); j < i && j <= c; ++j)
        {
            v = (v + dfs(i - 1, b - 1, j) * dfs(a - i, b - 1, c - j) % p * C[a - 1][i - 1]) % p;
        }
    }
    return v;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    std::cin >> n >> m >> k >> p;
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    }
    P[0] = P[1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            P[i] = (P[i] + P[j] * P[i - j - 1] % p * C[i - 1][j]) % p;
    std::cout << dfs(n, m, k) << std::endl;
    return 0;
}