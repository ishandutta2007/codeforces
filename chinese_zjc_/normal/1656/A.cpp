// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::cout << std::min_element(a + 1, a + 1 + n) - a << ' ' << std::max_element(a + 1, a + 1 + n) - a << std::endl;
    }
    return 0;
}