// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, a[1000005], b[1000005], rk[1000005];
std::vector<int> app;
long long ans;
struct segmenttree
{
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    int min[1 << 21], tag[1 << 21];
    void pushdown(int now)
    {
        if (tag[now])
        {
            min[lson] += tag[now];
            min[rson] += tag[now];
            tag[lson] += tag[now];
            tag[rson] += tag[now];
            tag[now] = 0;
        }
    }
    void pushup(int now)
    {
        min[now] = std::min(min[lson], min[rson]);
    }
    void build(int now = 1, int l = 0, int r = n)
    {
        tag[now] = 0;
        if (l == r)
        {
            min[now] = 0;
            return;
        }
        build(lson, l, lmid);
        build(rson, rmid, r);
    }
    void add(int L, int R, int val, int now = 1, int l = 0, int r = n)
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
        {
            min[now] += val;
            tag[now] += val;
            return;
        }
        pushdown(now);
        add(L, R, val, lson, l, lmid);
        add(L, R, val, rson, rmid, r);
        pushup(now);
    }
    int query(int L, int R, int now = 1, int l = 0, int r = n)
    {
        if (R < l || r < L)
            return INT_MAX;
        if (L <= l && r <= R)
            return min[now];
        pushdown(now);
        return std::min(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
    }
} t;
struct BIT
{
    int sum[2000005];
    void add(int pos, int val)
    {
        while (pos <= 2000000)
        {
            sum[pos] += val;
            pos += pos & -pos;
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
} y;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        ans = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], rk[i] = i;
        for (int i = 1; i <= m; ++i)
            std::cin >> b[i];
        std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
                  { return a[A] < a[B]; });
        std::sort(b + 1, b + 1 + m);
        t.build();
        for (int i = 1; i <= n; ++i)
            t.add(i, n, +1);
        int l = 1, r = 1;
        for (int i = 1; i <= m; ++i)
        {
            while (r <= n && a[rk[r]] <= b[i])
                t.add(rk[r++], n, -1);
            while (l <= n && a[rk[l]] < b[i])
                t.add(0, rk[l++] - 1, +1);
            ans += t.query(0, n);
        }
        app.clear();
        for (int i = 1; i <= n; ++i)
            app.push_back(a[i]);
        std::sort(app.begin(), app.end());
        app.erase(std::unique(app.begin(), app.end()), app.end());
        for (int i = 1; i <= n; ++i)
        {
            int v = std::upper_bound(app.begin(), app.end(), a[i]) - app.begin();
            ans += y.query(app.size()) - y.query(v);
            y.add(v, 1);
        }
        for (int i = 1; i <= n; ++i)
            y.add(std::upper_bound(app.begin(), app.end(), a[i]) - app.begin(), -1);
        std::cout << ans << std::endl;
    }
    return 0;
}