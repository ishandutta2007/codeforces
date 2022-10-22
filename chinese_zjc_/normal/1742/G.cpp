// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], cur;
bool vis[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        cur = 0;
        std::memset(vis, false, sizeof(vis));
        for (int i = 0; i != n && i != 30; ++i)
        {
            int max = 0;
            for (int j = 1; j <= n; ++j)
                if (!vis[j] && (cur | a[j]) >= (cur | a[max]))
                    max = j;
            std::cout << a[max] << ' ';
            cur |= a[max];
            vis[max] = true;
        }
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
                std::cout << a[i] << ' ';
        std::cout << std::endl;
    }
    return 0;
}