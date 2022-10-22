// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, a[200005], c[200005], t, st;
long long ans, pre[200005];
std::vector<int> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> st;
    for (int i = 2; i <= n; ++i)
        std::cin >> c[i];
    std::cin >> t;
    for (int i = 2; i <= n; ++i)
        std::cin >> t, c[i] = t - c[i];
    a[1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i + i; j <= n; j += i)
            a[j] -= a[i], c[j] -= c[i];
    for (int i = 1; i <= n; ++i)
        if (!a[i])
            ans += std::abs(c[i]);
        else
            g.push_back(a[i] * c[i]);
    std::sort(g.begin(), g.end());
    for (int i = 1; i <= int(g.size()); ++i)
        pre[i] = pre[i - 1] + g[i - 1];
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> t;
        t -= st;
        long long mid = std::lower_bound(g.begin(), g.end(), -t) - g.begin();
        std::cout << ans - (mid * t + pre[mid]) + ((int(g.size()) - mid) * t + (pre[g.size()] - pre[mid])) << std::endl;
    }
    return 0;
}