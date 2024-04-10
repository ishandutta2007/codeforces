// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, q;
long long a[105], b[100005], sum0[1 << 18], sum1[1 << 18], min[1 << 18], max[1 << 18], tag[1 << 18], sum2;
template <class T1, class T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2> &A, const std::pair<T1, T2> &B)
{
    return {A.first + B.first, A.second + B.second};
}
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    sum0[now] = sum0[lson] + sum0[rson];
    sum1[now] = sum1[lson] + sum1[rson];
    min[now] = min[lson];
    max[now] = max[rson];
}
void pushdown(int now)
{
    if (tag[now])
    {
        sum1[lson] += tag[now] * sum0[lson];
        min[lson] += tag[now];
        max[lson] += tag[now];
        tag[lson] += tag[now];
        sum1[rson] += tag[now] * sum0[rson];
        min[rson] += tag[now];
        max[rson] += tag[now];
        tag[rson] += tag[now];
        tag[now] = 0;
    }
}
void build(int now = 1, int l = 2, int r = m)
{
    if (l == r)
    {
        sum0[now] = 1;
        sum1[now] = b[l];
        min[now] = max[now] = b[l];
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
std::pair<long long, long long> lower_bound(long long lim, int now = 1, int l = 2, int r = m)
{
    if (min[now] >= lim)
        return {0, 0};
    if (max[now] < lim)
        return {sum0[now], sum1[now]};
    pushdown(now);
    return lower_bound(lim, lson, l, lmid) + lower_bound(lim, rson, rmid, r);
}
void add(int pos, int val, int now = 1, int l = 2, int r = m)
{
    if (pos <= l)
    {
        sum1[now] += val * sum0[now];
        min[now] += val;
        max[now] += val;
        tag[now] += val;
        return;
    }
    if (r < pos)
        return;
    pushdown(now);
    add(pos, val, lson, l, lmid);
    add(pos, val, rson, rmid, r);
    pushup(now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
        std::cin >> b[i];
    for (int i = n; i; --i)
        a[i] -= a[i - 1];
    for (int i = m; i; --i)
        b[i] -= b[i - 1];
    for (int i = m; i >= 2; --i)
        sum2 += b[i] * (m - i + 1);
    build();
    for (int i = 1, opt, x, y; i <= q; ++i)
    {
        std::cin >> opt >> x >> y;
        if (opt == 1)
            for (int j = n - x + 1; j <= n; ++j)
                a[j] += y;
        else
            add(m - x + 1, y), x == m ? b[1] += y, --x : x, sum2 += y * (x + 1ll) * x / 2;
        long long ans = (a[1] + b[1]) * (n + m - 1) + sum2;
        for (int j = 2; j <= n; ++j)
        {
            std::pair<long long, long long> res = lower_bound(a[j]);
            ans += (n - j + 1 + m - res.first - 1) * a[j] + res.second;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}