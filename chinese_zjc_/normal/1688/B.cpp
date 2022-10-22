// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], x, y;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        x = 0;
        y = INT_MAX;
        for (int i = 1, t; i <= n; ++i)
            std::cin >> t, x += ~t & 1, y = std::min(y, t & -t);
        if (y == 1)
            std::cout << x << std::endl;
        else
            std::cout << n - 1 + __builtin_ctz(y) << std::endl;
    }
    return 0;
}