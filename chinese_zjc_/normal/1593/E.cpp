// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k, v[400005];
bool died[400005];
std::vector<int> to[400005];
std::vector<int> que[400005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        std::fill(died + 1, died + 1 + n, false);
        std::fill(v + 1, v + 1 + n, 0);
        for (int i = 1; i <= n; ++i)
            to[i].clear();
        for (int i = 1, x, y; i != n; ++i)
            std::cin >> x >> y, to[x].push_back(y), to[y].push_back(x), ++v[x], ++v[y];
        for (int i = 1; i <= n; ++i)
            if (v[i] <= 1)
                que[1].push_back(i);
        for (int i = 1; i <= std::min(n, k); ++i)
            while (!que[i].empty())
            {
                int now = que[i].back();
                que[i].pop_back();
                died[now] = true;
                for (auto j : to[now])
                    if (--v[j] == 1)
                        que[i + 1].push_back(j);
            }
        que[k + 1].clear();
        std::cout << std::count(died + 1, died + 1 + n, false) << std::endl;
    }
    return 0;
}