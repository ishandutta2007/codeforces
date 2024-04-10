// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, k;
char c[25][25], d[25][25];
int worka(int x, int y) { return x == 0 || y == 0 ? 0 : c[x][y] == '*' ? worka(x - 1, y - 1) + 1
                                                                       : 0; }
int workb(int x, int y) { return x == 0 || y > m ? 0 : c[x][y] == '*' ? workb(x - 1, y + 1) + 1
                                                                      : 0; }
void painta(int x, int y, int len)
{
    if (x == 0 || y == 0 || len == 0)
        return;
    d[x][y] = '*';
    painta(x - 1, y - 1, len - 1);
}
void paintb(int x, int y, int len)
{
    if (x == 0 || y > m || len == 0)
        return;
    d[x][y] = '*';
    paintb(x - 1, y + 1, len - 1);
}
bool check()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (c[i][j] != d[i][j])
                return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> c[i][j], d[i][j] = '.';
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '*')
                {
                    int len = std::min(worka(i, j), workb(i, j));
                    if (len > k)
                        painta(i, j, len), paintb(i, j, len);
                }
        // for (int i = 1; i <= n; ++i, std::cout << std::endl)
        //     for (int j = 1; j <= m; ++j)
        //         std::cout << d[i][j];
        std::cout << (check() ? "YES" : "NO") << std::endl;
    }
    return 0;
}