// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, k, a[20][20], c[20][20], pop[1024], app[10];
const int MOD = 1000000007;
int dfs(int x, int y)
{
    if (x == n + 1)
        return 1;
    if (y == m + 1)
        return dfs(x + 1, 1);
    c[x][y] = c[x - 1][y] | c[x][y - 1];
    if (n + m - x - y + 1 > k - pop[c[x][y]])
        return 0;
    int z = -1, res = 0;
    for (int i = 0; i != k; ++i)
        if ((~c[x][y] & 1 << i) && (!~a[x][y] || a[x][y] == i))
        {
            c[x][y] |= 1 << i;
            if (app[i])
            {
                ++app[i];
                res += dfs(x, y + 1);
                --app[i];
            }
            else
            {
                if (~z)
                    res += z;
                else
                {
                    ++app[i];
                    res += z = dfs(x, y + 1);
                    --app[i];
                }
            }
            if (res >= MOD)
                res -= MOD;
            c[x][y] &= ~(1 << i);
        }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    if (n + m - 1 > k)
        return std::cout << 0 << std::endl, 0;
    for (int i = 1; i != 1 << k; ++i)
        pop[i] = pop[i >> 1] + (i & 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> a[i][j], --a[i][j];
            if (~a[i][j])
                ++app[a[i][j]];
        }
    std::cout << dfs(1, 1) << std::endl;
    return 0;
}