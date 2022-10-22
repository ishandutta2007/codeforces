// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, T;
bool app[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            app[i] = false;
        for (int i = 1, a, b, c; i <= m; ++i)
        {
            std::cin >> a >> b >> c;
            app[b] = true;
        }
        int root = std::find(app + 1, app + 1 + n, false) - app;
        for (int i = 1; i <= n; ++i)
            if (i != root)
                std::cout << i << ' ' << root << '\n';
    }
    return 0;
}