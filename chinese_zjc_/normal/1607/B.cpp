// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long x, n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> x >> n;
        for (long long i = n / 4 * 4 + 1; i <= n; ++i)
            if (x & 1)
                x += i;
            else
                x -= i;
        std::cout << x << std::endl;
    }
    return 0;
}