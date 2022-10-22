// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
long long ans, a[200005], add;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::sort(a + 1, a + 1 + n);
        ans = LLONG_MIN;
        add = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans = std::max(ans, a[i] + add);
            add -= a[i] + add;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}