// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, q, depth[300005], fa[300005], ans;
bool v[300005];
std::vector<int> to[300005], son[300005], p[300005];
void init(int now)
{
    for (auto i : to[now])
    {
        if (fa[i])
            continue;
        fa[i] = now;
        depth[i] = depth[now] + 1;
        son[now].push_back(i);
        init(i);
    }
}
bool dfs(int now)
{
    bool has = false;
    for (auto i : son[now])
        if (dfs(i))
            ans += has, has ^= true;
    if (!v[now] && has)
        ++ans, has = false;
    return v[now];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1, a, b; i <= m; ++i)
    {
        std::cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    fa[1] = -1;
    init(1);
    std::cin >> q;
    for (int i = 1, a, b; i <= q; ++i)
    {
        std::cin >> a >> b;
        std::vector<int> A, B;
        while (a != b)
            if (depth[a] < depth[b])
                B.push_back(b), v[b] ^= true, b = fa[b];
            else
                A.push_back(a), v[a] ^= true, a = fa[a];
        A.push_back(a);
        std::reverse(B.begin(), B.end());
        p[i] = A;
        p[i].insert(p[i].end(), B.begin(), B.end());
    }
    dfs(1);
    if (ans)
    {
        std::cout << "NO" << std::endl
                  << ans << std::endl;
    }
    else
    {
        std::cout << "YES" << std::endl;
        for (int i = 1; i <= q; ++i)
        {
            std::cout << p[i].size() << std::endl;
            for (int j = 0; j != (int)p[i].size(); ++j)
                std::cout << p[i][j] << " \n"[j + 1 == int(p[i].size())];
        }
    }
    return 0;
}