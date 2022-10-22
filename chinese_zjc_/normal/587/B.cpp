// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
std::vector<int> dp[1000005];
long long l;
int n, k, a[1000005], rk[1000005], sum[1000005], ans;
void add(int &A, const int &B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> l >> k;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i], rk[i] = i, dp[i].resize(k + 1);
    std::sort(rk, rk + n, [&](const int &A, const int &B)
              { return a[A] < a[B]; });
    sum[0] = 1;
    for (int i = 0; i != n;)
    {
        int l = i, r = std::find_if_not(rk + i, rk + n, [&](const int x)
                                        { return a[x] == a[rk[i]]; }) -
                       rk;
        for (int j = 1; j <= k; ++j)
            for (int o = l; o != r; ++o)
                add(sum[j], dp[rk[o]][j] = sum[j - 1]);
        i = r;
    }
    for (int i = 1; i <= k; ++i)
        for (int j = 0; j != n; ++j)
            add(ans, dp[j][i] * (std::max(0ll, l / n - i + 1 + (j < l % n)) % MOD) % MOD);
    std::cout << ans << std::endl;
    return 0;
}