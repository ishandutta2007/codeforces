// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, a[100005], min[100005], cnt, lson[3000005], rson[3000005], t[3000005], ans[300005], root;
std::vector<std::pair<int, int>> ask[100005];
void update_min(int pos, int val)
{
    while (pos)
    {
        min[pos] = std::min(min[pos], val);
        pos -= pos & -pos;
    }
}
int query_min(int pos)
{
    int res = INT_MAX;
    while (pos <= n)
    {
        res = std::min(res, min[pos]);
        pos += pos & -pos;
    }
    return res;
}
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void update(int pos, int val, int &now = root, int l = 0, int r = 1000000000)
{
    if (!now)
        now = ++cnt;
    t[now] = val;
    if (l == r)
        return;
    if (pos <= lmid)
        update(pos, val, lson[now], l, lmid);
    else
        update(pos, val, rson[now], rmid, r);
}
int query(int L, int R, int &now = root, int l = 0, int r = 1000000000)
{
    if (R < l || r < L || !now)
        return 0;
    if (L <= l && r <= R)
        return t[now];
    return std::max(query(L, R, lson[now], l, lmid), query(L, R, rson[now], rmid, r));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::cin >> m;
    for (int i = 1, l, r; i <= m; ++i)
    {
        std::cin >> l >> r;
        ask[r].push_back({l, i});
    }
    std::fill(min + 1, min + 1 + n, INT_MAX);
    for (int i = 1; i <= n; ++i)
    {
        static int lst;
        lst = query(a[i], 1000000000);
        while (lst)
        {
            int v = a[lst] - a[i];
            update_min(lst, v);
            lst = query(a[i], (a[i] + a[lst] + 1) / 2 - 1);
        }
        lst = query(0, a[i]);
        while (lst)
        {
            int v = a[i] - a[lst];
            update_min(lst, v);
            lst = query((a[i] + a[lst]) / 2 + 1, a[i]);
        }
        update(a[i], i);
        for (auto j : ask[i])
            ans[j.second] = query_min(j.first);
    }
    for (int i = 1; i <= m; ++i)
        std::cout << ans[i] << '\n';
    return 0;
}