// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, m, a[1000005], dp[1005][1005], L[1005], R[1005];
std::vector<int> app[505];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i];
        if (a[i - 1] == a[i])
            --i, --m;
        else
            app[a[i]].push_back(i);
    }
    if (m > n * 2)
        return std::cout << 0 << std::endl, 0;
    for (int k = n; k; --k)
        if (!app[k].empty())
        {
            int tmp = dp[app[k].front()][app[k].back()];
            tmp = 1;
            for (std::size_t j = 1; j != app[k].size(); ++j)
                tmp = 1ll * tmp * dp[app[k][j - 1] + 1][app[k][j] - 1] % MOD;
            int l = app[k].front(), r = app[k].back();
            L[l] = 1;
            while (a[l - 1] > k)
                --l, L[l] = dp[l][app[k].front() - 1];
            R[r] = 1;
            while (k < a[r + 1])
                ++r, R[r] = dp[app[k].back() + 1][r];
            for (int i = l; i <= app[k].front(); ++i)
                for (int j = i + 1; j <= app[k].front(); ++j)
                    L[i] = (L[i] + 1ll * L[j] * dp[i][j - 1]) % MOD;
            for (int i = r; i >= app[k].back(); --i)
                for (int j = i - 1; j >= app[k].back(); --j)
                    R[i] = (R[i] + 1ll * R[j] * dp[j + 1][i]) % MOD;
            for (int i = app[k].front(); i >= l; --i)
                for (int j = app[k].back(); j <= r; ++j)
                    dp[i][j] = 1ll * L[i] * tmp % MOD * R[j] % MOD;
        }
    std::cout << dp[1][m] << std::endl;
    return 0;
}