// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long n, m, T, a[100005], b[100005], app[100005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        ans = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], app[a[i]] = i;
        for (int i = 1; i <= m; ++i)
            std::cin >> b[i];
        for (int i = 1, j = 0; i <= m; ++i)
        {
            if (j < app[b[i]])
            {
                j = app[b[i]];
                ans += 2 * (j - i);
            }
            ++ans;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}