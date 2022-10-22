// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int xx[] = {0, -1, 0, +1},
          yy[] = {-1, 0, +1, 0};
int T, n, m;
char a[505][505];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        std::memset(a, '1', sizeof(a));
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> a[i][j], cnt += a[i][j] == '1';
        int min = 3;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                for (int k = 0; k != 4; ++k)
                    min = std::min(min, (a[i][j] == '1') +
                                            (a[i + xx[k]][j + yy[k]] == '1') +
                                            (a[i + xx[(k + 1) & 3]][j + yy[(k + 1) & 3]] == '1'));
        min = std::max(min, 1);
        if (cnt)
            std::cout << cnt - min + 1 << std::endl;
        else
            std::cout << 0 << std::endl;
    }
    return 0;
}