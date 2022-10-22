// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, a, b, c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> a >> b >> c;
        if (c > std::abs(b - a) << 1 || std::min(a, b) > std::abs(b - a))
            std::cout << -1 << std::endl;
        else
            std::cout << (c <= std::abs(b - a) ? c + std::abs(b - a) : c - std::abs(b - a)) << std::endl;
    }
    return 0;
}