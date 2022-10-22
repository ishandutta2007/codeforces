// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
bool d[55][55];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    n = std::min(n, 50);
    for (int i = 1, x, y; i <= m; ++i)
    {
        std::cin >> x >> y;
        if (x <= n && y <= n)
            d[x][y] = d[y][x] = true;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (d[i][j])
                for (int k = j + 1; k <= n; ++k)
                    if (d[i][k] && d[j][k])
                        for (int l = k + 1; l <= n; ++l)
                            if (d[i][l] && d[j][l] && d[k][l])
                                for (int o = l + 1; o <= n; ++o)
                                    if (d[i][o] && d[j][o] && d[k][o] && d[l][o])
                                        return std::cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << o << std::endl, 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d[i][j] = !d[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (d[i][j])
                for (int k = j + 1; k <= n; ++k)
                    if (d[i][k] && d[j][k])
                        for (int l = k + 1; l <= n; ++l)
                            if (d[i][l] && d[j][l] && d[k][l])
                                for (int o = l + 1; o <= n; ++o)
                                    if (d[i][o] && d[j][o] && d[k][o] && d[l][o])
                                        return std::cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << o << std::endl, 0;
    std::cout << -1 << std::endl;
    return 0;
}