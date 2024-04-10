// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, ans, a[200005], fa[200005], depth[200005];
std::vector<int> to[200005];
bool vis[200005];
void init(int now)
{
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
}
void del(int now)
{
    vis[now] = true;
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        del(i);
    }
}
int gofa(int x, int y)
{
    while (y--)
        x = fa[x];
    return x;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            to[i].clear();
        for (int i = 1; i <= m; ++i)
            std::cin >> a[i];
        std::fill(vis + 1, vis + 1 + n, false);
        for (int i = 1, x, y; i < n; ++i)
        {
            std::cin >> x >> y;
            to[x].push_back(y);
            to[y].push_back(x);
        }
        init(1);
        std::sort(a + 1, a + 1 + m, [&](const int &A, const int &B)
                  { return depth[A] < depth[B]; });
        ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (vis[a[i]])
                continue;
            del(gofa(a[i], depth[a[i]] / 2));
            ++ans;
        }
        for (int i = 2; i <= n; ++i)
            if (int(to[i].size()) == 1 && !vis[i])
                ans = -1;
        std::cout << (ans < 0 ? "YES" : "NO") << std::endl;
    }
    return 0;
}