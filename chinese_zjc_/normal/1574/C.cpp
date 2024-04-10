// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
long long a[200005], x, y, sum, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    std::sort(a, a + n);
    sum = std::accumulate(a, a + n, 0ll);
    std::cin >> m;
    for (int i = 0; i != m; ++i)
    {
        std::cin >> x >> y;
        long long *iter = std::lower_bound(a, a + n, x);
        ans = LLONG_MAX;
        if (iter != a + n)
            ans = std::min(ans, std::max(0ll, y - (sum - *iter)));
        if (iter != a)
            --iter, ans = std::min(ans, (x - *iter) + std::max(0ll, y - (sum - *iter)));
        std::cout << ans << std::endl;
    }
    return 0;
}