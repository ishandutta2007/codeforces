// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
char e[105][105];
bool dp[105][105][26], vis[105][105][26];
bool dfs(int l, int r, int c)
{
    if (vis[l][r][c])
        return dp[l][r][c];
    vis[l][r][c] = true;
    for (int i = 1; i <= n; ++i)
        dp[l][r][c] |= e[l][i] - 'a' >= c && !dfs(r, i, e[l][i] - 'a');
    return dp[l][r][c];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        static char z;
        std::cin >> x >> y >> z;
        e[x][y] = z;
    }
    for (int i = 1; i <= n; ++i, std::cout << std::endl)
        for (int j = 1; j <= n; ++j)
            std::cout << (dfs(i, j, 0) ? 'A' : 'B');
    return 0;
}