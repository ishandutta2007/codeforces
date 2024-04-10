// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], b[200005], max[1 << 19], tag[1 << 19], ans;
bool open[200005];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    max[now] = std::max(max[lson], max[rson]);
}
void pushdown(int now)
{
    if (tag[now])
    {
        max[lson] += tag[now];
        max[rson] += tag[now];
        tag[lson] += tag[now];
        tag[rson] += tag[now];
        tag[now] = 0;
    }
}
void build(int now = 1, int l = 1, int r = n)
{
    tag[now] = 0;
    if (l == r)
    {
        max[now] = ((l + 1) & 1) - 1;
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
        max[now] += val;
        tag[now] += val;
        return;
    }
    pushdown(now);
    add(L, R, val, lson, l, lmid);
    add(L, R, val, rson, rmid, r);
    pushup(now);
}
int query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return 0;
    if (L <= l && r <= R)
        return max[now];
    pushdown(now);
    return std::max(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
}
std::set<int> s[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        ans = 0;
        s[0].clear();
        s[1].clear();
        build();
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], b[a[i]] = i, s[0].insert(i), add(1, i - 1, +1);
        for (int i = n; i > 1; --i)
        {
            add(1, b[i] - 1, -1);
            add(b[i], n, +1);
            s[0].erase(b[i]);
            s[1].insert(b[i]);
            ans = std::max(ans, query(*s[1].begin(), *s[0].rbegin() - 1));
        }
        std::cout << ans << std::endl;
    }
    return 0;
}