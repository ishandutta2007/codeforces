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
        std::cout << std::max({0, b - a + 1, c - a + 1}) << ' '
                  << std::max({0, a - b + 1, c - b + 1}) << ' '
                  << std::max({0, a - c + 1, b - c + 1}) << std::endl;
    }
    return 0;
}