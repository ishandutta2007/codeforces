// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, dfn[400005], idfn[400005], fa[400005], cnt, v[400005], tim, ans1[200005], ans2[200005],
    val[200005], min[200005], max[200005], F[20][400005], depth[400005];
struct edge
{
    int f, t, cost, flow;
} e[200005];
struct query
{
    int s, v, p;
} a[200005];
std::vector<int> son[400005];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
void init(int now)
{
    dfn[idfn[now] = ++tim] = now;
    for (int i = 1; 1 << i <= depth[now]; ++i)
        F[i][now] = F[i - 1][F[i - 1][now]];
    for (auto i : son[now])
    {
        F[0][i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
}
int LCA(int A, int B)
{
    if (depth[A] > depth[B])
        std::swap(A, B);
    for (int i = 20; i--;)
        if (depth[B] - depth[A] >= 1 << i)
            B = F[i][B];
    if (A == B)
        return A;
    for (int i = 20; i--;)
        if (F[i][A] != F[i][B])
            A = F[i][A], B = F[i][B];
    return F[0][A];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> val[i];
    for (int i = 1; i <= n + n; ++i)
        fa[i] = i;
    cnt = n;
    for (int i = 1; i != n; ++i)
        std::cin >> e[i].f >> e[i].t >> e[i].flow >> e[i].cost;
    for (int i = 1; i <= q; ++i)
        std::cin >> a[i].v >> a[i].s, a[i].p = i;
    std::sort(e + 1, e + n, [&](const edge &A, const edge &B)
              { return A.cost < B.cost; });
    for (int i = 1; i != n; ++i)
    {
        ++cnt;
        son[cnt].push_back(find(e[i].f));
        son[cnt].push_back(find(e[i].t));
        v[cnt] = e[i].cost;
        fa[find(e[i].f)] = cnt;
        fa[find(e[i].t)] = cnt;
    }
    init(cnt);
    std::sort(e + 1, e + n, [&](const edge &A, const edge &B)
              { return A.flow > B.flow; });
    std::sort(a + 1, a + 1 + q, [&](const query &A, const query &B)
              { return A.v > B.v; });
    for (int i = 1; i <= n; ++i)
        fa[i] = i, min[i] = max[i] = idfn[i];
    e[n].flow = 0;
    for (int i = 1, j = 1; true; ++i)
    {
        while (j <= q && a[j].v > e[i].flow)
        {
            ans1[a[j].p] = val[dfn[min[find(a[j].s)]]];
            ans2[a[j].p] = v[LCA(dfn[std::min(idfn[a[j].s], min[find(a[j].s)])],
                                 dfn[std::max(idfn[a[j].s], max[find(a[j].s)])])];
            ++j;
        }
        if (i == n)
            break;
        if (val[dfn[min[find(e[i].f)]]] == val[dfn[min[find(e[i].t)]]])
        {
            min[find(e[i].f)] = std::min(min[find(e[i].f)], min[find(e[i].t)]);
            max[find(e[i].f)] = std::max(max[find(e[i].f)], max[find(e[i].t)]);
        }
        if (val[dfn[min[find(e[i].f)]]] < val[dfn[min[find(e[i].t)]]])
        {
            min[find(e[i].f)] = min[find(e[i].t)];
            max[find(e[i].f)] = max[find(e[i].t)];
        }
        fa[find(e[i].t)] = find(e[i].f);
    }
    for (int i = 1; i <= q; ++i)
        std::cout << ans1[i] << ' ' << ans2[i] << std::endl;
    return 0;
}