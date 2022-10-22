// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
char c[20005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> (c + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (c[i] == '0')
            {
                if (i > n / 2)
                    std::cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << std::endl;
                else
                    std::cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << std::endl;
                goto nextcase;
            }
        }
        std::cout << 1 << ' ' << n / 2 << ' ' << n - n / 2 + 1 << ' ' << n << std::endl;
    nextcase:;
    }
    return 0;
}