// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k, fa[100005], sum[100005];
std::vector<int> son[100005];
bool flag;
void init(int now)
{
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        fa[i] = now;
        init(i);
        sum[now] ^= sum[i];
    }
}
bool dfs(int now)
{
    bool has = false;
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        if (dfs(i))
            (has ? flag : has) = true;
    }
    if (has && sum[now] == 0)
        flag = true;
    return has || sum[now] == sum[1];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            fa[i] = 0, std::cin >> sum[i], son[i].clear();
        for (int i = 1, a, b; i != n; ++i)
            std::cin >> a >> b, son[a].push_back(b), son[b].push_back(a);
        init(1);
        flag = false;
        if (sum[1] == 0)
            std::cout << "YES" << std::endl;
        else if (k >= 3)
            dfs(1), std::cout << (flag ? "YES" : "NO") << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}