// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        if ((n & -n) == n)
            std::cout << -1 << std::endl;
        else
            for (int i = 0; 1ll << i < n; ++i)
                if (n % (1ll << i << 1) == (1ll << i))
                {
                    long long x = 1ll << i, y = n / x;
                    x <<= 1;
                    if (x > 1 && n * 2 / x / (x + 1) >= 1)
                        std::cout << x << std::endl;
                    else
                        std::cout << y << std::endl;
                    break;
                }
    }
    return 0;
}