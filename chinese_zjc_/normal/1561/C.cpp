// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
std::pair<int, int> a[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1, k, x; i <= n; ++i)
        {
            std::cin >> k;
            a[i].first = 0;
            a[i].second = k;
            for (int j = 0; j != k; ++j)
                std::cin >> x, a[i].first = std::max(a[i].first, x + 1 - j);
        }
        std::sort(a + 1, a + 1 + n);
        long long max = 0, add = 0;
        for (int i = 1; i <= n; ++i)
            max = std::max(max, a[i].first - add), add += a[i].second;
        std::cout << max << std::endl;
    }
    return 0;
}