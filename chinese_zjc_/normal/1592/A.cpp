// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, h, a[1005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> h;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::sort(a + 1, a + 1 + n, std::greater<int>());
        std::cout << (h / (a[1] + a[2]) * 2 + (h % (a[1] + a[2]) > 0) + (h % (a[1] + a[2]) > a[1])) << std::endl;
    }
    return 0;
}