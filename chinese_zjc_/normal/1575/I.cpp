// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, a[100005], depth[100005], fa[20][100005], dfn[100005], end[100005], idfn[100005], tim;
std::vector<int> to[100005];
long long sum[100005];
void init(int now)
{
    idfn[dfn[now] = ++tim] = now;
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : to[now])
    {
        if (fa[0][now] == i)
            continue;
        fa[0][i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
    end[now] = tim + 1;
}
void add(int pos, int val)
{
    while (pos <= n)
    {
        sum[pos] += val;
        pos += pos & -pos;
    }
}
long long query(int pos)
{
    long long res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
int LCA(int A, int B)
{
    if (depth[A] > depth[B])
        std::swap(A, B);
    for (int i = 20; i--;)
        if (depth[B] - depth[A] >= 1 << i)
            B = fa[i][B];
    if (A == B)
        return A;
    for (int i = 20; i--;)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], a[i] = std::abs(a[i]);
    for (int i = 1, x, y; i < n; ++i)
    {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    init(1);
    for (int i = 1; i <= n; ++i)
        add(dfn[i], +a[i]), add(end[i], -a[i]);
    for (int i = 1, opt, x, y; i <= q; ++i)
    {
        std::cin >> opt >> x >> y;
        switch (opt)
        {
        case 1:
            add(dfn[x], -a[x]);
            add(end[x], +a[x]);
            a[x] = std::abs(y);
            add(dfn[x], +a[x]);
            add(end[x], -a[x]);
            break;
        case 2:
            opt = LCA(x, y);
            std::cout << 2 * (query(dfn[x]) + query(dfn[y]) - 2 * query(dfn[opt]) + a[opt]) - a[x] - a[y] << std::endl;
            break;
        }
    }
    return 0;
}