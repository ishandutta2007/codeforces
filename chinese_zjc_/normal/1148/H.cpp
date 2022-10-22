// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
struct node
{
    int ll, lr, rl;
    long long prel, prer;
    node() : ll(), lr(), rl(), prer() {}
    node(int ll_, int lr_, int rl_, node lst) : ll(ll_), lr(lr_), rl(rl_),
                                                prel(lst.prel + lst.ll * (rl - lst.rl)),
                                                prer(lst.prer + lst.lr * (rl - lst.rl)) {}
};
template <int node::*c>
bool cmp(const node &A, const node &B) { return A.*c < B.*c; }
std::vector<node> g[200005];
int min[1 << 19 | 5];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    min[now] = std::min(min[lson], min[rson]);
}
void modify(int pos, int val, int now = 1, int l = 0, int r = n)
{
    if (l == r)
        return void(min[now] = val);
    if (pos <= lmid)
        modify(pos, val, lson, l, lmid);
    else
        modify(pos, val, rson, rmid, r);
    pushup(now);
}
int query(int L, int R, int now = 1, int l = 0, int r = n)
{
    if (R < l || r < L)
        return INT_MAX;
    if (L <= l && r <= R)
        return min[now];
    return std::min(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
}
#undef lson
#undef rson
#undef lmid
#undef rmid
template <int node::*c>
std::vector<node>::const_iterator lower_bound(const std::vector<node> &x, const int &y)
{
    node t;
    t.*c = y;
    return std::lower_bound(x.begin(), x.end(), t, cmp<c>);
}
template <int node::*c>
std::vector<node>::const_iterator upper_bound(const std::vector<node> &x, const int &y)
{
    node t;
    t.*c = y;
    return std::upper_bound(x.begin(), x.end(), t, cmp<c>);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i <= n; ++i)
        g[i].emplace_back();
    for (int i = 1, a, l, r, k; i <= n; ++i)
    {
        static long long ans;
        std::cin >> a >> l >> r >> k;
        a = (a + ans) % (n + 1);
        l = (l + ans) % i + 1;
        r = (r + ans) % i + 1;
        k = (k + ans) % (n + 1);
        if (l > r)
            std::swap(l, r);
        if (a)
            g->emplace_back(query(0, 0), i, i, g->back());
        int lst = query(a, a);
        modify(a, i);
        int h = std::min(i, query(0, a - 1));
        for (int j = a; h > lst; ++j)
        {
            int tmp = h;
            h = std::min(h, query(j, j));
            // std::cout << h << ' ' << tmp << "   " << lst << ' ' << j << ' ' << query(2, 2) << ' ' << a << std::endl;
            g[j].emplace_back(h, tmp, i, g[j].back());
        }
        // for (auto j : g[k])
        //     std::cout << j.ll << ' ' << j.lr << ' ' << j.rl << std::endl;
        std::vector<node>::const_iterator A = lower_bound<&node::lr>(g[k], l),
                                          B = lower_bound<&node::ll>(g[k], l),
                                          C = --upper_bound<&node::rl>(g[k], r + 1);
        // std::cout << A - g[k].begin() << ' ' << B - g[k].begin() << ' ' << C - g[k].begin() << std::endl;
        B = std::min(B, C);
        A = std::min(A, B);
        ans = (B->prer - A->prer) - (B->rl - A->rl) * (l - 1ll) +
              (C->prer - B->prer) - (C->prel - B->prel) +
              (r + 1ll - std::max(l, C->rl)) * (std::max(C->lr, l - 1) - std::max(C->ll, l - 1));
        std::cout << ans << std::endl;
    }
    return 0;
}