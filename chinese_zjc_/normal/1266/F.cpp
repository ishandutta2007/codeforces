// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#define F(x) (x * 2)
// #define debug
int n, depth[500005], maxdepth[500005], fa[500005], ans[500005];
std::vector<int> son[500005];
void cmax(int &A, int B) { A = std::max(A, B); }
void init(int now)
{
    maxdepth[now] = depth[now];
    for (auto &i : son[now])
    {
        if (fa[now] == i)
            continue;
        fa[i] = now;
        depth[i] = depth[now] + 1;
        init(i);
        maxdepth[now] = std::max(maxdepth[now], maxdepth[i]);
    }
}
void dfs1(int now, int x)
{
    std::vector<int> res(1, x);
    for (std::size_t i = 0; i != son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
            continue;
        res.push_back(maxdepth[son[now][i]] - depth[now]);
    }
    std::sort(res.begin(), res.end());
    std::reverse(res.begin(), res.end());
    for (std::size_t i = 1; i != res.size(); ++i)
        if (res[i] == res[i - 1])
            cmax(ans[res[i] * 2 - 1], i + 1);
        else
            cmax(ans[res[i] * 2 + 1], i + 1);
    res.clear();
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        res.push_back(maxdepth[i] - depth[now]);
    }
    res.push_back(0);
    for (std::size_t i = res.size() - 1; i--;)
        cmax(res[i], res[i + 1]);
    std::reverse(res.begin(), res.end());
    res.pop_back();
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        dfs1(i, std::max(x, res.back()) + 1);
        res.pop_back();
        cmax(x, maxdepth[i] - depth[now]);
    }
}
void dfs2(int now, int x)
{
    std::vector<std::pair<int, int>> res(1, {x, -1});
    std::vector<int> siz(son[now].size(), -1);
    for (std::size_t i = 0; i != son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
            continue;
        res.push_back({maxdepth[son[now][i]] - depth[now], -1});
        for (auto j : son[son[now][i]])
        {
            if (now == j)
                continue;
            res.push_back({maxdepth[j] - depth[son[now][i]], i});
        }
    }
    std::sort(res.begin(), res.end());
    std::reverse(res.begin(), res.end());
    int cnt = 0, max = 0;
    for (auto i : res)
        if (~i.second)
            cmax(ans[i.first * 2], cnt + ++siz[i.second]), cmax(max, siz[i.second]);
        else
            cmax(ans[i.first * 2], ++cnt + max);
    siz.clear();
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        siz.push_back(maxdepth[i] - depth[now]);
    }
    siz.push_back(0);
    for (std::size_t i = siz.size() - 1; i--;)
        cmax(siz[i], siz[i + 1]);
    std::reverse(siz.begin(), siz.end());
    siz.pop_back();
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        dfs2(i, std::max(x, siz.back()) + 1);
        siz.pop_back();
        cmax(x, maxdepth[i] - depth[now]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, a, b; i != n; ++i)
    {
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    ans[n] = ans[n - 1] = 1;
    init(1);
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i)
        cmax(ans[1], son[i].size() + 1);
    for (int i = n - 2; i >= 1; --i)
        cmax(ans[i], ans[i + 2]);
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];
    return 0;
}