// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 Rand(seed);
int n, k, m;
unsigned long long c[100005], p[100005];
struct lhash
{
    int len;
    unsigned long long hash;
    lhash() = default;
    lhash(int x) : len(1), hash(c[x]) {}
    lhash(int len_, unsigned long long hash_) : len(len_), hash(hash_) {}
    friend lhash operator+(const lhash &A, const lhash &B) { return lhash(A.len + B.len, A.hash + B.hash * p[A.len]); }
};
struct rhash
{
    int len;
    unsigned long long hash;
    rhash() = default;
    rhash(int x) : len(1), hash(c[x]) {}
    rhash(int len_, unsigned long long hash_) : len(len_), hash(hash_) {}
    friend rhash operator+(const rhash &A, const rhash &B) { return rhash(A.len + B.len, A.hash * p[B.len] + B.hash); }
};
struct node
{
    rhash r;
    lhash l;
    bool bad;
    node() = default;
    node(int x) : r(), l(), bad()
    {
        if (x < 0)
            r = -x;
        else
            l = +x;
    }
} t[1 << 18];
int ls[1 << 18], rs[1 << 18], tot;
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
rhash gethashr(int L, int R, int now)
{
    int &lson = ls[now], &rson = rs[now];
    if (R == 0)
        return rhash();
    if (L == 0 && R == t[now].r.len)
        return t[now].r;
    if (R <= t[lson].r.len)
        return gethashr(L, R, lson);
    if (t[lson].r.len <= L)
        return gethashr(L - t[lson].r.len + t[lson].l.len, R - t[lson].r.len + t[lson].l.len, rson);
    return gethashr(L, t[lson].r.len, lson) +
           gethashr(t[lson].l.len, R - t[lson].r.len + t[lson].l.len, rson);
}
lhash gethashl(int L, int R, int now)
{
    int &lson = ls[now], &rson = rs[now];
    if (R == 0)
        return lhash();
    if (L == 0 && R == t[now].l.len)
        return t[now].l;
    if (R <= t[rson].l.len)
        return gethashl(L, R, rson);
    if (t[rson].l.len <= L)
        return gethashl(L - t[rson].l.len + t[rson].r.len, R - t[rson].l.len + t[rson].r.len, lson);
    return gethashl(t[rson].r.len, R - t[rson].l.len + t[rson].r.len, lson) +
           gethashl(L, t[rson].l.len, rson);
}
void pushup(int now)
{
    int &lson = ls[now], &rson = rs[now];
    t[now].bad = t[lson].bad || t[rson].bad;
    if (t[lson].l.len < t[rson].r.len)
    {
        int len = t[lson].l.len;
        unsigned long long h = gethashr(0, len, rson).hash;
        t[now].bad |= t[lson].l.hash != h;
        t[now].r = t[lson].r + rhash(t[rson].r.len - len, t[rson].r.hash - h * p[t[rson].r.len - len]);
        t[now].l = t[rson].l;
    }
    else
    {
        int len = t[rson].r.len;
        unsigned long long h = gethashl(0, len, lson).hash;
        t[now].bad |= h != t[rson].r.hash;
        t[now].r = t[lson].r;
        t[now].l = lhash(t[lson].l.len - len, t[lson].l.hash - h * p[t[lson].l.len - len]) + t[rson].l;
    }
}
void build(int now = 0, int l = 1, int r = n)
{
    int &lson = ls[now], &rson = rs[now];
    if (l == r)
    {
        static int x;
        std::cin >> x;
        t[now] = x;
        return;
    }
    build(lson = ++tot, l, lmid);
    build(rson = ++tot, rmid, r);
    pushup(now);
}
void modify(int pos, int v, int now = 0, int l = 1, int r = n)
{
    int &lson = ls[now], &rson = rs[now];
    if (l == r)
    {
        t[now] = v;
        return;
    }
    if (pos <= lmid)
        modify(pos, v, lson, l, lmid);
    else
        modify(pos, v, rson, rmid, r);
    pushup(now);
}
int g[100005], cnt;
void visit(int L, int R, int now = 0, int l = 1, int r = n)
{
    int &lson = ls[now], &rson = rs[now];
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
        return void(g[++cnt] = now);
    visit(L, R, lson, l, lmid);
    visit(L, R, rson, rmid, r);
}
void make(int &now, int l = 1, int r = cnt)
{
    int &lson = ls[now], &rson = rs[now];
    if (l == r)
    {
        --tot;
        now = g[l];
        return;
    }
    make(lson = ++tot, l, lmid);
    make(rson = ++tot, rmid, r);
    pushup(now);
}
bool query(int l, int r)
{
    cnt = 0;
    visit(l, r);
    int root = tot = n << 1;
    make(root);
    return !(t[root].l.len || t[root].r.len || t[root].bad);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= k; ++i)
        c[i] = Rand();
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] * 19260817;
    build();
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, y;
        std::cin >> opt >> x >> y;
        switch (opt)
        {
        case 1:
            modify(x, y);
            break;
        case 2:
            std::cout << (query(x, y) ? "Yes" : "No") << std::endl;
            break;
        }
    }
    return 0;
}