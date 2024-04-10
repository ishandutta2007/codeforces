// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, m;
char c[55][55];
bool check()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (c[i][j] == '*')
            {
                int cnt = 0, minx = i, maxx = i, miny = j, maxy = j;
                for (int k = i - 1; k <= i + 1; ++k)
                    for (int l = j - 1; l <= j + 1; ++l)
                        if (c[k][l] == '*')
                        {
                            ++cnt;
                            minx = std::min(minx, k);
                            maxx = std::max(maxx, k);
                            miny = std::min(miny, l);
                            maxy = std::max(maxy, l);
                        }
                if (cnt != 3 || maxx - minx == 2 || maxy - miny == 2)
                    return false;
            }
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        std::memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> c[i][j];
        std::cout << (check() ? "YES" : "NO") << std::endl;
    }
    return 0;
}