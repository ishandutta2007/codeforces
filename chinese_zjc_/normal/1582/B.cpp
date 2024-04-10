// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
long long c[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        c[0] = c[1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            std::cin >> x;
            if (x < 2)
                ++c[x];
        }
        std::cout << (c[1] << c[0]) << std::endl;
    }
    return 0;
}