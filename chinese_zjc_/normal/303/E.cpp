// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, l[81], r[81];
double ans[81][81], p[81];
std::vector<int> a;
double J(int l, int r, int L, int R) { return r <= L || R <= l ? 0 : a[std::min(R, r)] - a[std::max(L, l)]; }
void solve(int now, int ll, int rr, double lst[81][81])
{
    if (rr - ll == 1)
    {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; i + j <= n; ++j)
                if (l[ll] <= now && now + 1 <= r[ll])
                {
                    double M = lst[i][j] * (a[now + 1] - a[now]) * p[ll] / (j + 1);
                    for (int k = i; k <= i + j; ++k)
                        ans[ll][k] += M;
                }
        return;
    }
    double dp[2][81][81];
    int mid = (ll + rr) / 2;
    bool NOW = true, LST = false;
    memcpy(dp[NOW], lst, sizeof(dp[NOW]));
    for (int i = mid, P = n - (rr - ll); i != rr; ++i, ++P)
    {
        double L = l[i] < now ? (a[std::min(r[i], now)] - a[l[i]]) * p[i] : 0,
               R = r[i] > now + 1 ? (a[r[i]] - a[std::max(l[i], now + 1)]) * p[i] : 0,
               M = 1 - L - R;
        std::swap(NOW, LST);
        memset(dp[NOW], 0, sizeof(dp[NOW]));
        for (int k = 0; k <= P; ++k)
            for (int l = 0; k + l <= P; ++l)
            {
                dp[NOW][k + 1][l] += dp[LST][k][l] * L;
                dp[NOW][k][l + 1] += dp[LST][k][l] * M;
                dp[NOW][k][l] += dp[LST][k][l] * R;
            }
    }
    solve(now, ll, mid, dp[NOW]);
    memcpy(dp[NOW], lst, sizeof(dp[NOW]));
    for (int i = ll, P = n - (rr - ll); i != mid; ++i, ++P)
    {
        double L = l[i] < now ? (a[std::min(r[i], now)] - a[l[i]]) * p[i] : 0,
               R = r[i] > now + 1 ? (a[r[i]] - a[std::max(l[i], now + 1)]) * p[i] : 0,
               M = 1 - L - R;
        std::swap(NOW, LST);
        memset(dp[NOW], 0, sizeof(dp[NOW]));
        for (int k = 0; k <= P; ++k)
            for (int l = 0; k + l <= P; ++l)
            {
                dp[NOW][k + 1][l] += dp[LST][k][l] * L;
                dp[NOW][k][l + 1] += dp[LST][k][l] * M;
                dp[NOW][k][l] += dp[LST][k][l] * R;
            }
    }
    solve(now, mid, rr, dp[NOW]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> l[i] >> r[i], p[i] = 1.0 / (r[i] - l[i]), a.push_back(l[i]), a.push_back(r[i]);
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    for (int i = 0; i != n; ++i)
        l[i] = std::lower_bound(a.begin(), a.end(), l[i]) - a.begin(),
        r[i] = std::lower_bound(a.begin(), a.end(), r[i]) - a.begin();
    static double dp[81][81];
    dp[0][0] = 1;
    for (int i = 0; i != (int)a.size(); ++i)
        solve(i, 0, n, dp);
    std::cout << std::fixed << std::setprecision(10);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            std::cout << ans[i][j] << " \n"[j + 1 == n];
    return 0;
}