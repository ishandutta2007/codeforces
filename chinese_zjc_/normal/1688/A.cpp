// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        if (n == 1)
            std::cout << 3 << std::endl;
        else if (n & (n - 1))
            std::cout << (n & -n) << std::endl;
        else
            std::cout << n + 1 << std::endl;
    }
    return 0;
}