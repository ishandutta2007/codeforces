// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k, r, c, g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k >> r >> c;
        g = (r + c) % k;
        for (int i = 1; i <= n; ++i, std::cout << std::endl)
            for (int j = 1; j <= n; ++j)
                std::cout << ((i + j) % k == g ? 'X' : '.');
    }
    return 0;
}