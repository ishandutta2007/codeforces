// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct node
{
    int d[30], cnt;
    node() { clear(); }
    void clear()
    {
        std::fill(d, d + 30, 0);
        cnt = 0;
    }
    void insert(int now)
    {
        for (int i = 30; i--;)
            if (now & 1 << i)
            {
                if (d[i])
                    now ^= d[i];
                else
                {
                    d[i] = now;
                    ++cnt;
                    return;
                }
            }
    }
    friend node operator+(const node &A, const node &B)
    {
        node res = A;
        for (int i = 30; i--;)
            if (B.d[i])
                res.insert(B.d[i]);
        return res;
    }
} t[1 << 19];
int n, q, a[200005], b[200005];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        t[now].clear();
        t[now].insert(b[l]);
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    t[now] = t[lson] + t[rson];
}
void modify(int pos, int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        t[now].clear();
        t[now].insert(b[l]);
        return;
    }
    if (pos <= lmid)
        modify(pos, lson, l, lmid);
    else
        modify(pos, rson, rmid, r);
    t[now] = t[lson] + t[rson];
}
node query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return node();
    if (L <= l && r <= R)
        return t[now];
    return query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r);
}
int sum[200005];
void add(int pos, int x)
{
    while (pos <= n)
    {
        sum[pos] ^= x;
        pos += pos & -pos;
    }
}
int query(int pos)
{
    int res = 0;
    while (pos)
    {
        res ^= sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], add(i, b[i] = a[i] ^ a[i - 1]);
    build();
    for (int i = 1, opt, l, r, x; i <= q; ++i)
    {
        std::cin >> opt >> l >> r;
        if (opt == 1)
        {
            std::cin >> x;
            b[l] ^= x;
            b[++r] ^= x;
            modify(l);
            modify(r);
            add(l, x);
            add(r, x);
        }
        else
        {
            node tmp = query(l + 1, r);
            tmp.insert(query(l));
            std::cout << (1 << tmp.cnt) << std::endl;
        }
    }
    return 0;
}