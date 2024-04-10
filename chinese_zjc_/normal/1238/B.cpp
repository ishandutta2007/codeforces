// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k;
std::vector<int> x;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        x.clear();
        for (int i = 1, y; i <= n; ++i)
            std::cin >> y, x.push_back(y);
        std::sort(x.begin(), x.end());
        x.erase(std::unique(x.begin(), x.end()), x.end());
        std::reverse(x.begin(), x.end());
        for (int i = 0; i != int(x.size()); ++i)
            if (x[i] <= i * k)
            {
                std::cout << i << std::endl;
                goto next;
            }
        std::cout << x.size() << std::endl;
    next:;
    }
    return 0;
}