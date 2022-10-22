// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k;
long long L[55], R[55], c[55], dp[55][55][55][4][4];
void cmin(long long &A, long long B) { A = std::min(A, B); }
long long dfs(int l, int r, int p, int ll, int rr)
{
    if (p == k)
        return 0;
    if (~dp[l][r][p][ll][rr])
        return dp[l][r][p][ll][rr];
    long long &now = dp[l][r][p][ll][rr] = LLONG_MAX / 2;
    for (int i = l; ++i != r;)
        if (L[i] >> p != R[i] >> p)
        {
            if (~L[i] >> p & 1 && ((L[i] ^ 1ll << p) | +((1ll << p) - 1)) <= R[i])
                cmin(now, dfs(l, i, p, ll, 1) + dfs(i, r, p, 1, rr));
            if (+R[i] >> p & 1 && ((R[i] ^ 1ll << p) & ~((1ll << p) - 1)) >= L[i])
                cmin(now, dfs(l, i, p, ll, 2) + dfs(i, r, p, 2, rr));
            // std::cout << l << ' ' << r << ' ' << p << ' ' << ll << ' ' << rr << ' ' << now << std::endl;
        }
    for (int i = l; ++i != r;)
    {
        long long lll = L[i], rrr = R[i];
        if (lll % (1ll << p << 1))
            lll = lll + (1ll << p << 1) - lll % (1ll << p << 1);
        if (rrr - lll + 1 < 1ll << p << 1)
            return now;
    }
    cmin(now, dfs(l, r, p + 1, (ll & 2) | ((ll & 2 ? R : L)[l] >> p >> 1 & 1),
                  (rr & 2) | ((rr & 2 ? R : L)[r] >> p >> 1 & 1)) +
                  ((ll ^ rr) & 1 && l >= 1 && r <= n ? c[p] : 0));
    return now;
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> L[i] >> R[i], L[i] = L[i] << 1, R[i] = R[i] << 1 | 1;
    for (int i = 1; i <= k; ++i)
        std::cin >> c[i];
    ++k;
    L[0] = L[n + 1] = 0;
    R[0] = R[n + 1] = (1ll << k) - 1;
    std::cout << dfs(0, n + 1, 0, 0, 0) << std::endl;
    return 0;
}