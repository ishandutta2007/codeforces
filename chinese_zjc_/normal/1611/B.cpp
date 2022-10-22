// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, a, b;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> a >> b;
        std::cout << std::min({a, b, (a + b) / 4}) << std::endl;
    }
    return 0;
}