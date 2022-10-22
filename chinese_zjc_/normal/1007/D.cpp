// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, fa[100005], heavy[100005], siz[100005], top[100005], dfn[100005], idfn[100005], tim, cnt, ncnt, p[100005];
std::vector<int> son[100005], app[1 << 18], to[4000005];
void add_edge(int A, int B) { to[A].push_back(B), to[B ^ 1].push_back(A ^ 1); }
int new_node() { return (ncnt += 2) - 2; }
void init1(int now)
{
    siz[now] = 1;
    for (std::size_t i = 0; i != son[now].size(); ++i)
    {
        if (son[now][i] == fa[now])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        const int &t = son[now][i];
        fa[t] = now;
        init1(t);
        siz[now] += siz[t];
        if (siz[heavy[now]] < siz[t])
            heavy[now] = t;
    }
}
void init2(int now)
{
    idfn[dfn[now] = ++tim] = now;
    if (!top[now])
        top[now] = now;
    if (heavy[now])
        top[heavy[now]] = top[now], init2(heavy[now]);
    for (auto i : son[now])
        if (i != heavy[now])
            init2(i);
}
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void add(int L, int R, int v, int now = 1, int l = 2, int r = n)
{
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
        return app[now].push_back(v);
    add(L, R, v, lson, l, lmid);
    add(L, R, v, rson, rmid, r);
}
void build(int lst, int now = 1, int l = 2, int r = n)
{
    for (auto i : app[now])
    {
        int nxt = new_node();
        add_edge(lst, nxt);
        add_edge(i, nxt);
        add_edge(lst, i ^ 1);
        lst = nxt;
    }
    if (l == r)
        return;
    build(lst, lson, l, lmid);
    build(lst, rson, rmid, r);
}
#undef lson
#undef rson
#undef lmid
#undef rmid
int tdfn[4000005], tlow[4000005], in[4000005], ttim, tcnt;
bool ins[4000005];
std::stack<int> sta;
void Tarjan(int now)
{
    sta.push(now);
    ins[now] = true;
    tdfn[now] = tlow[now] = ++ttim;
    for (auto i : to[now])
        if (!tdfn[i])
        {
            Tarjan(i);
            tlow[now] = std::min(tlow[now], tlow[i]);
        }
        else if (ins[i])
            tlow[now] = std::min(tlow[now], tlow[i]);
    if (tdfn[now] == tlow[now])
    {
        while (sta.top() != now)
        {
            in[sta.top()] = tcnt;
            ins[sta.top()] = false;
            sta.pop();
        }
        in[now] = tcnt++;
        ins[now] = false;
        sta.pop();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, x, y; i != n; ++i)
        std::cin >> x >> y, son[x].push_back(y), son[y].push_back(x);
    init1(1);
    init2(1);
    std::cin >> m;
    for (int i = 0, a, b; i != m; ++i)
    {
        std::cin >> a >> b;
        p[i] = new_node();
        while (top[a] != top[b])
            if (dfn[top[a]] > dfn[top[b]])
                add(dfn[top[a]], dfn[a], p[i]), a = fa[top[a]];
            else
                add(dfn[top[b]], dfn[b], p[i]), b = fa[top[b]];
        if (dfn[a] > dfn[b])
            std::swap(a, b);
        if (a != b)
            add(dfn[a] + 1, dfn[b], p[i]);
        p[i] ^= 1;
        std::cin >> a >> b;
        while (top[a] != top[b])
            if (dfn[top[a]] > dfn[top[b]])
                add(dfn[top[a]], dfn[a], p[i]), a = fa[top[a]];
            else
                add(dfn[top[b]], dfn[b], p[i]), b = fa[top[b]];
        if (dfn[a] > dfn[b])
            std::swap(a, b);
        if (a != b)
            add(dfn[a] + 1, dfn[b], p[i]);
        p[i] ^= 1;
    }
    build(new_node());
    for (int i = 0; i != ncnt; ++i)
        if (!tdfn[i])
            Tarjan(i);
    for (int i = 0; i != m; ++i)
        if (in[p[i]] == in[p[i] ^ 1])
            return std::cout << "NO" << std::endl, 0;
    std::cout << "YES" << std::endl;
    for (int i = 0; i != m; ++i)
        std::cout << (in[p[i] ^ 1] < in[p[i]]) + 1 << std::endl;
    return 0;
}