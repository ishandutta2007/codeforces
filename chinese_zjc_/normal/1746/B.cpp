// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, pre[100005], a[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i)
            ans = std::min(ans, std::max(pre[i], (n - i) - (pre[n] - pre[i])));
        std::cout << ans << std::endl;
    }
    return 0;
}