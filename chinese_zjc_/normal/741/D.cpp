// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, fa[500005], v[500005], depth[500005], max[1 << 22], siz[500005], heavy[500005], ans[500005];
std::vector<int> son[500005];
char c;
void clear(int now)
{
    max[v[now]] = INT_MIN / 2;
    for (auto i : son[now])
        clear(i);
}
void calc(int now, int &res, int down)
{
    for (int i = 0; i != 22; ++i)
        res = std::max(res, max[v[now] ^ 1 << i] + depth[now] - down);
    res = std::max(res, max[v[now]] + depth[now] - down);
    for (auto i : son[now])
        calc(i, res, down);
}
void add(int now)
{
    max[v[now]] = std::max(max[v[now]], depth[now]);
    for (auto i : son[now])
        add(i);
}
void dfs(int now)
{
    for (auto i : son[now])
    {
        if (i == heavy[now])
            continue;
        dfs(i);
        clear(i);
        ans[now] = std::max(ans[now], ans[i]);
    }
    if (heavy[now])
        dfs(heavy[now]), ans[now] = std::max(ans[now], ans[heavy[now]]);
    for (auto i : son[now])
    {
        if (i == heavy[now])
            continue;
        calc(i, ans[now], 2 * depth[now]);
        add(i);
    }
    for (int i = 0; i != 22; ++i)
        ans[now] = std::max(ans[now], max[v[now] ^ 1 << i] - depth[now]);
    ans[now] = std::max(ans[now], max[v[now]] - depth[now]);
    max[v[now]] = std::max(max[v[now]], depth[now]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::fill(max, max + (1 << 22), INT_MIN / 2);
    std::cin >> n;
    for (int i = 2; i <= n; ++i)
        std::cin >> fa[i] >> c, v[i] = v[fa[i]] ^ 1 << (c - 'a'), son[fa[i]].push_back(i), depth[i] = depth[fa[i]] + 1;
    for (int i = n; i; --i)
    {
        siz[i] = 1;
        for (auto j : son[i])
        {
            siz[i] += siz[j];
            if (siz[j] > siz[heavy[i]])
                heavy[i] = j;
        }
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];
    return 0;
}