// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[1000005];
std::vector<int> g[5005];
int ans[1 << 13];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::fill(ans, ans + (1 << 13), 5001);
    ans[0] = 0;
    std::for_each(g + 1, g + 5001, [&](std::vector<int> &x)
                  { x.push_back(0); });
    for (int i = 1; i <= n; ++i)
    {
        for (auto j : g[a[i]])
        {
            if (a[i] < ans[j ^ a[i]])
            {
                for (int k = a[i] + 1; k <= ans[j ^ a[i]]; ++k)
                    g[k].push_back(j ^ a[i]);
                ans[j ^ a[i]] = a[i];
            }
        }
        g[a[i]].clear();
    }
    std::cout << (1 << 13) - std::count(ans, ans + (1 << 13), 5001) << std::endl;
    for (int i = 0; i != 1 << 13; ++i)
        if (ans[i] != 5001)
            std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}