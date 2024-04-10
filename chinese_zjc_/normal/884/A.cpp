// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, t;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> t;
    for (int i = 1, x; i <= n; ++i)
    {
        std::cin >> x;
        t -= 86400 - x;
        if (t <= 0)
            return std::cout << i << std::endl, 0;
    }
    return 0;
}