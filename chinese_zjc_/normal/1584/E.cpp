// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const long long INF = 1e16;
int T, n, a[300005], to[300005];
long long sum[300005], min[2][1 << 20], dp[300005], ans;
std::map<long long, int> app[2];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        min[0][now] = min[1][now] = +INF;
        min[l & 1][now] = sum[l];
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    for (int i = 0; i != 2; ++i)
        min[i][now] = std::min(min[i][lson], min[i][rson]);
}
long long qmin(int L, int R, int pos, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return +INF;
    if (L <= l && r <= R)
        return min[pos][now];
    return std::min(qmin(L, R, pos, lson, l, lmid), qmin(L, R, pos, rson, rmid, r));
}
int find(const std::map<long long, int> &map, long long v)
{
    return map.count(v) ? map.find(v)->second : INT_MAX;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        app[0].clear();
        app[1].clear();
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], sum[i] = a[i] - sum[i - 1];
        build();
        for (int i = n; i; --i)
        {
            app[i & 1][sum[i]] = i;
            to[i] = std::min(find(app[(i - 1) & 1], +sum[i - 1]), find(app[~(i - 1) & 1], -sum[i - 1]));
            if (!(qmin(i, to[i], +(i - 1) & 1) - sum[i - 1] >= 0 &&
                  qmin(i, to[i], ~(i - 1) & 1) + sum[i - 1] >= 0))
                to[i] = INT_MAX;
        }
        ans = 0;
        std::fill(dp, dp + 1 + n, 1);
        for (int i = 1; i <= n; ++i)
            if (to[i] != INT_MAX)
                dp[to[i]] += dp[i - 1];
        for (int i = 0; i <= n; ++i)
            ans += dp[i];
        ans -= n + 1;
        std::cout << ans << std::endl;
    }
    std::cerr << clock() << std::endl;
    return 0;
}