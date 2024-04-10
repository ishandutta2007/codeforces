// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, k, p[105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> p[i];
            if (i <= k && p[i] > k)
                ++ans;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}