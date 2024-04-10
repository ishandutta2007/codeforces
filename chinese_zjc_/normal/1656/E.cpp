// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, v[100005], g[100005];
std::vector<int> to[100005];
void dfs(int now, int dep, int fa)
{
    if (to[now].size() == 1 && now != 1)
        return void(v[now] = g[now] = dep);
    int tmp = 0;
    for (auto i : to[now])
    {
        if (i == fa)
            continue;
        dfs(i, -dep, now);
        tmp = g[i];
    }
    v[now] = -tmp * to[now].size();
    g[now] = -tmp;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1, x, y; i < n; ++i)
        {
            std::cin >> x >> y;
            to[x].push_back(y);
            to[y].push_back(x);
        }
        dfs(1, 1, 0);
        for (int i = 1; i <= n; ++i)
            std::cout << v[i] << " \n"[i == n], to[i].clear();
    }
    return 0;
}