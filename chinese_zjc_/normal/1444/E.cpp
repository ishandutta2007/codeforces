// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
typedef __int128_t bigint;
int n, fa[105], v[105];
std::vector<int> to[105], son[105];
bigint merge(std::priority_queue<std::pair<bigint, int>> &x)
{
    bigint res = 0;
    for (int i = 100; i--;)
    {
        std::priority_queue<std::pair<bigint, int>> tmp = x;
        for (int j = i; j && !tmp.empty() && !(tmp.top().first >> j--);)
        {
            if (tmp.top().first >> j & 1)
                tmp.push({tmp.top().first ^ bigint(1) << j, tmp.top().second});
            tmp.pop();
        }
        if (tmp.empty())
            continue;
        res |= bigint(1) << i;
        if (x.top().first >> i & 1)
            x.push({x.top().first ^ bigint(1) << i, x.top().second});
        else
            v[x.top().second] = i;
        x.pop();
    }
    return res;
}
bigint dfs(int now)
{
    std::priority_queue<std::pair<bigint, int>> res;
    for (int i : to[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        res.push({dfs(i), i});
    }
    return merge(res);
}
bool vis[105];
int get(int now)
{
    int res = now;
    for (int i : son[now])
    {
        if (vis[i])
            continue;
        int tmp = get(i);
        if (v[res] < v[tmp])
            res = tmp;
    }
    return res;
}
void work(int now)
{
    while (true)
    {
        v[now] = -1;
        int pos = get(now);
        if (pos == now)
            return void(std::cout << "! " << now << std::endl);
        std::cout << "? " << pos << ' ' << fa[pos] << std::endl;
        int tmp;
        std::cin >> tmp;
        if (tmp == pos)
            return work(pos);
        else
            vis[pos] = true;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(v, -1, sizeof(v));
    std::cin >> n;
    for (int i = 1, x, y; i != n; ++i)
    {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    dfs(1);
    for (int i = 2; i <= n; ++i)
        son[fa[i]].push_back(i);
    work(1);
    return 0;
}