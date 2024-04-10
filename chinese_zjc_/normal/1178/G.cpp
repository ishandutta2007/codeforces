// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, fa[200005], dfn[200005], r[200005], idfn[200005], tim;
long long a[200005], b[200005];
std::vector<int> son[200005];
struct node
{
    long long a, b, t;
    node(long long a_ = 0, long long b_ = 0, long long t_ = 0) : a(a_), b(b_), t(t_) {}
    friend node max(node A, node B)
    {
        if (A.a < B.a)
        {
            B.t = std::min(B.t, A.t);
            if (A.b > B.b)
                B.t = std::min(B.t, (B.a - A.a) / (A.b - B.b) + 1);
            return B;
        }
        else
        {
            A.t = std::min(A.t, B.t);
            if (B.b > A.b)
                A.t = std::min(A.t, (A.a - B.a) / (B.b - A.b) + 1);
            return A;
        }
    }
    friend node min(node A, node B)
    {
        if (A.a > B.a)
        {
            B.t = std::min(B.t, A.t);
            if (A.b < B.b)
                B.t = std::min(B.t, (B.a - A.a) / (A.b - B.b) + 1);
            return B;
        }
        else
        {
            A.t = std::min(A.t, B.t);
            if (B.b < A.b)
                A.t = std::min(A.t, (A.a - B.a) / (B.b - A.b) + 1);
            return A;
        }
    }
};
struct tree
{
    node max, min;
    long long tag;
} t[1 << 19];
void init(int now)
{
    idfn[dfn[now] = ++tim] = now;
    for (auto i : son[now])
        init(i);
    r[now] = tim;
}
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    t[now].max = max(t[lson].max, t[rson].max);
    t[now].min = min(t[lson].min, t[rson].min);
}
void pushdown(int now)
{
    if (t[now].tag)
    {
        t[lson].max.a += t[lson].max.b * t[now].tag;
        t[rson].max.a += t[rson].max.b * t[now].tag;
        t[lson].min.a += t[lson].min.b * t[now].tag;
        t[rson].min.a += t[rson].min.b * t[now].tag;
        t[lson].max.t -= t[now].tag;
        t[rson].max.t -= t[now].tag;
        t[lson].min.t -= t[now].tag;
        t[rson].min.t -= t[now].tag;
        t[lson].tag += t[now].tag;
        t[rson].tag += t[now].tag;
        t[now].tag = 0;
    }
}
void update(int now)
{
    if (t[now].max.t <= 0 || t[now].min.t <= 0)
    {
        pushdown(now);
        update(lson);
        update(rson);
        pushup(now);
    }
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        t[now].max = t[now].min = node(a[idfn[l]] * b[idfn[l]], b[idfn[l]], LLONG_MAX);
        t[now].tag = 0;
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void add(int L, int R, int val, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        t[now].max.a += t[now].max.b * val;
        t[now].min.a += t[now].min.b * val;
        t[now].max.t -= val;
        t[now].min.t -= val;
        t[now].tag += val;
        update(now);
        return;
    }
    pushdown(now);
    add(L, R, val, lson, l, lmid);
    add(L, R, val, rson, rmid, r);
    pushup(now);
}
long long query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return 0;
    update(now);
    if (L <= l && r <= R)
        return std::max(t[now].max.a, -t[now].min.a);
    pushdown(now);
    return std::max(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 2; i <= n; ++i)
        std::cin >> fa[i], son[fa[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    for (int i = 2; i <= n; ++i)
        a[i] += a[fa[i]], b[i] += b[fa[i]];
    for (int i = 1; i <= n; ++i)
        b[i] = std::abs(b[i]);
    init(1);
    build();
    for (int i = 1; i <= m; ++i)
    {
        static long long opt, x, y;
        std::cin >> opt >> x;
        switch (opt)
        {
        case 1:
            std::cin >> y;
            add(dfn[x], r[x], y);
            break;
        case 2:
            std::cout << query(dfn[x], r[x]) << std::endl;
            break;
        }
        // for (int j = 1; j <= n; ++j)
        //     query(j, j);
    }
    return 0;
}