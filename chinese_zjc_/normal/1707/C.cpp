// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int n, m, fa[100005], F[20][100005], dfn[100005], depth[100005], tim, end[100005], idfn[100005];
std::vector<int> to[100005];
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
void init(int now)
{
    F[0][now] = fa[now];
    for (int i = 1; 1 << i <= depth[now]; ++i)
        F[i][now] = F[i - 1][F[i - 1][now]];
    idfn[dfn[now] = ++tim] = now;
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
    end[now] = tim;
}
int sum[100005];
void add(int pos, int val)
{
    while (pos <= n)
    {
        sum[pos] += val;
        pos += pos & -pos;
    }
}
void add(int l, int r, int val)
{
    if (l <= r)
    {
        add(l, val);
        add(r + 1, -val);
    }
}
int query(int pos)
{
    int res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
bool in(int A, int B) { return dfn[A] <= dfn[B] && dfn[B] <= end[A]; }
std::vector<std::pair<int, int>> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    std::iota(fa + 1, fa + 1 + n, 1);
    for (int i = 1, x, y; i <= m; ++i)
    {
        std::cin >> x >> y;
        if (find(x) != find(y))
        {
            to[x].push_back(y);
            to[y].push_back(x);
            fa[find(x)] = find(y);
        }
        else
            g.push_back({x, y});
    }
    fa[1] = 0;
    init(1);
    for (auto i : g)
    {
        if (dfn[i.first] > dfn[i.second])
            std::swap(i.first, i.second);
        if (in(i.first, i.second))
        {
            int x = depth[i.second] - depth[i.first] - 1, y = i.second;
            for (int j = 20; j--;)
                if (x >> j & 1)
                    y = F[j][y];
            add(dfn[i.second], end[i.second], 1);
            add(1, dfn[y] - 1, 1);
            add(end[y] + 1, n, 1);
        }
        else
        {
            add(dfn[i.first], end[i.first], 1);
            add(dfn[i.second], end[i.second], 1);
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cout << (query(dfn[i]) == int(g.size()));
    return 0;
}