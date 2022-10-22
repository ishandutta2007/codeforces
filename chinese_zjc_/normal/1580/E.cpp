// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, q, a[300005], b[300005], c[300005], from[200005], pre[200005], t[200005], cnt;
int rk[200005], tim, p[200005], x[200005];
long long dis[200005], w[200005];
unsigned long long ans[200005];
std::vector<int> to[200005], d[200005], e[200005];
void add(int A, int B)
{
    if (from[A] == -1)
        return;
    else if (from[A] == 0)
        from[A] = B;
    else if (from[A] != B || from[A] == 1 || B == 1)
        from[A] = -1;
}
void get_dis()
{
    std::priority_queue<std::pair<long long, int>> que;
    std::fill(dis + 1, dis + 1 + n, LLONG_MAX / 2);
    que.push({-(dis[1] = 0), 1});
    while (!que.empty())
    {
        if (dis[que.top().second] + que.top().first)
        {
            que.pop();
            continue;
        }
        int now = que.top().second;
        que.pop();
        for (auto i : to[now])
            if (dis[a[i] ^ b[i] ^ now] > dis[now] + c[i])
                que.push({-(dis[a[i] ^ b[i] ^ now] = dis[now] + c[i]), a[i] ^ b[i] ^ now});
    }
    for (int i = 1; i <= m; ++i)
        if (dis[a[i]] + c[i] == dis[b[i]])
            add(b[i], a[i]);
        else if (dis[b[i]] + c[i] == dis[a[i]])
            add(a[i], b[i]);
    for (int i = 1; i <= n; ++i)
        if (from[i] == 1)
            from[i] = 0;
    std::iota(rk + 1, rk + 1 + n, 1);
    std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
              { return dis[A] < dis[B]; });
    for (int i = 2; i <= n; ++i)
        d[t[rk[i]] = tim += dis[rk[i]] != dis[rk[i - 1]]].push_back(rk[i]);
    std::copy(t + 1, t + 1 + n, rk + 1);
}
int query(int pos, int x) { return std::upper_bound(e[pos].begin(), e[pos].end(), x) - e[pos].begin(); }
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
#define lson (now << 1)
#define rson (lson | 1)
struct SGT
{
    int bes[1 << 19], sec[1 << 19], app[1 << 19];
    long long tag[1 << 19];
    unsigned long long sum[1 << 19];
    void calc(int now, int l, int r)
    {
        int A = pre[r] - pre[l - 1],
            B = query(bes[now], r) - query(bes[now], l - 1);
        A -= B;
        sum[now] = A * w[bes[now]] + B * w[sec[now]];
        app[now] = B;
    }
    void down(int now, int val, int l, int r)
    {
        sum[now] -= 1ll * (pre[r] - pre[l - 1] - app[now]) * val;
    }
    void pushdown(int now, int l, int r)
    {
        if (~tag[now])
        {
            if (~bes[now])
                bes[lson] = bes[now],
                bes[rson] = bes[now];
            if (~sec[now])
            {
                sec[lson] = sec[now],
                sec[rson] = sec[now];
                calc(lson, l, lmid);
                calc(rson, rmid, r);
            }
            else
            {
                down(lson, tag[now], l, lmid);
                down(rson, tag[now], rmid, r);
            }
            if (~tag[lson])
                tag[lson] += tag[now];
            else
                tag[lson] = tag[now];
            if (~tag[rson])
                tag[rson] += tag[now];
            else
                tag[rson] = tag[now];
            tag[now] = -1;
        }
    }
    void pushup(int now)
    {
        bes[now] = bes[lson] == bes[rson] ? bes[lson] : -1;
        sec[now] = sec[lson] == sec[rson] ? sec[lson] : -1;
        sum[now] = sum[lson] + sum[rson];
        app[now] = app[lson] + app[rson];
    }
    void build(int now = 1, int l = 1, int r = tim)
    {
        if (l == r)
        {
            bes[now] = a[l];
            sec[now] = b[l];
            calc(now, l, r);
            return;
        }
        build(lson, l, lmid);
        build(rson, rmid, r);
        tag[now] = -1;
        pushup(now);
    }
    void modify(int pos, int val, int now = 1, int l = 1, int r = tim)
    {
        if (r <= rk[pos])
            return;
        if (rk[pos] < l && ~bes[now])
        {
            if (pos == bes[now])
            {
                down(now, val, l, r);
                if (~tag[now])
                    tag[now] += val;
                else
                    tag[now] = val;
            }
            else if (w[pos] < w[bes[now]])
            {
                sec[now] = bes[now];
                bes[now] = pos;
                if (!~tag[now])
                    tag[now] = 0;
                calc(now, l, r);
            }
            else if (~sec[now])
            {
                if (w[pos] < w[sec[now]])
                    sec[now] = pos;
                if (w[sec[now]] < w[bes[now]])
                    std::swap(bes[now], sec[now]);
                if (!~tag[now])
                    tag[now] = 0;
                calc(now, l, r);
            }
            else
            {
                pushdown(now, l, r);
                modify(pos, val, lson, l, lmid);
                modify(pos, val, rson, rmid, r);
                pushup(now);
            }
        }
        else
        {
            pushdown(now, l, r);
            modify(pos, val, lson, l, lmid);
            modify(pos, val, rson, rmid, r);
            pushup(now);
        }
    }
    void update(int now = 1, int l = 1, int r = tim)
    {
        if (l == r)
        {
            // calc(now, l, r);
            return;
        }
        std::cout << '(' << bes[now] << ',' << sec[now] << ',' << sum[now] << ')';
        if (!tag[now])
        {
            pushdown(now, l, r);
            update(lson, l, lmid);
            update(rson, rmid, r);
            pushup(now);
        }
    }
} s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> w[i];
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i] >> c[i];
        to[a[i]].push_back(i);
        to[b[i]].push_back(i);
    }
    get_dis();
    for (int i = 1; i <= tim; ++i)
    {
        pre[i] = pre[i - 1];
        for (auto j : d[i])
            if (~from[j])
                ++pre[i], e[from[j]].push_back(i);
    }
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> p[i] >> x[i];
        w[p[i]] += x[i];
    }
    w[0] = LLONG_MAX;
    a[1] = b[1] = 1;
#ifdef debug
    for (int i = 1; i <= n; ++i)
        std::cout << dis[i] << " \n"[i == n];
    for (int i = 1; i <= n; ++i)
        std::cout << from[i] << " \n"[i == n];
    for (int i = 1; i <= n; ++i)
        std::cout << rk[i] << " \n"[i == n];
    for (int i = 1; i <= tim; ++i)
        std::cout << pre[i] << " \n"[i == tim];
#endif
    for (int i = 1; i <= tim; ++i)
    {
        a[i + 1] = a[i];
        b[i + 1] = b[i];
        for (auto j : d[i])
        {
            if (w[j] < w[b[i + 1]])
                b[i + 1] = j;
            if (w[b[i + 1]] < w[a[i + 1]])
                std::swap(a[i + 1], b[i + 1]);
        }
    }
    s.build();
    ans[q] = s.sum[1];
    for (int i = q; i; --i)
    {
        w[p[i]] -= x[i];
        s.modify(p[i], x[i]);
#ifdef debug
        s.update();
        std::cout << std::endl;
        std::cout << "----------------------------" << std::endl;
#endif
        ans[i - 1] = s.sum[1];
    }
    for (int i = 0; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}