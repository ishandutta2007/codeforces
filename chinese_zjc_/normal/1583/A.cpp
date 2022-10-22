// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[105];
bool good(int x)
{
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return true;
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], sum += a[i];
        if (good(sum))
        {
            std::cout << n << std::endl;
            for (int i = 1; i <= n; ++i)
                std::cout << i << " \n"[i == n];
            continue;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (good(sum - a[i]))
            {
                std::cout << n - 1 << std::endl;
                for (int j = 1; j <= n; ++j)
                    if (i != j)
                        std::cout << j << ' ';
                std::cout << std::endl;
                goto next;
            }
        }
    next:;
    }
    return 0;
}