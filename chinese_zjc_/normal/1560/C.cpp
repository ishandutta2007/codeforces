// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, k;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> k;
        int x = sqrt(k);
        if (k == x * x)
            std::cout << x << ' ' << 1 << std::endl;
        else if (k <= x * (x + 1))
            std::cout << k - x * x << ' ' << x + 1 << std::endl;
        else
            std::cout << x + 1 << ' ' << (x + 1) * (x + 1) - k + 1 << std::endl;
    }
    return 0;
}