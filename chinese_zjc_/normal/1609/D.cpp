// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, fa[1005], siz[1005], fr;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i, siz[i] = 1;
    for (int i = 1, a, b; i <= m; ++i)
    {
        std::cin >> a >> b;
        if (find(a) == find(b))
            ++fr;
        else
        {
            siz[find(b)] += siz[find(a)];
            fa[find(a)] = find(b);
        }
        std::vector<int> g;
        for (int j = 1; j <= n; ++j)
            if (find(j) == j)
                g.push_back(siz[j]);
        std::sort(g.begin(), g.end(), std::greater<int>());
        int ans = 0;
        for (int i = 0; i != (int)g.size(); ++i)
            if (i <= fr)
                ans += g[i];
        std::cout << ans - 1 << std::endl;
    }
    return 0;
}