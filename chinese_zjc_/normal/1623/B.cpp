// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, l[1005], r[1005];
bool vis[1005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> l[i] >> r[i];
        std::fill(vis + 1, vis + 1 + n, false);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (r[j] - l[j] + 1 == i)
                    for (int k = l[j]; k <= r[j]; ++k)
                        if (!vis[k])
                        {
                            vis[k] = true;
                            std::cout << l[j] << ' ' << r[j] << ' ' << k << std::endl;
                            break;
                        }
    }
    return 0;
}