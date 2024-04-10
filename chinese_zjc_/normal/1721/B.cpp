// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, sx, sy, d;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> sx >> sy >> d;
        std::cout << ((sx - d <= 1 || sy + d >= m) && (sy - d <= 1 || sx + d >= n) ? -1 : n + m - 2) << std::endl;
    }
    return 0;
}