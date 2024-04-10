// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, sx, sy, ex, ey;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> sx >> sy >> ex >> ey;
        std::cout << std::min(sy <= ey ? ey - sy : 2 * m - sy - ey, sx <= ex ? ex - sx : 2 * n - sx - ex) << std::endl;
    }
    return 0;
}