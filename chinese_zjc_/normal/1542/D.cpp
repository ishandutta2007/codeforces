// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, dp[2][505], a[505], rk[505], ik[505], ans;
bool now = true, lst = false;
void add(int &A, int B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static char c;
        std::cin >> c;
        if (c == '-')
            a[i] = -1;
        else
            std::cin >> a[i];
        rk[i] = i;
    }
    std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
              { return a[A] < a[B]; });
    for (int i = 1; i <= n; ++i)
        ik[rk[i]] = i;
    for (int i = n; i; --i)
        if (~a[rk[i]])
        {
            memset(dp, 0, sizeof(dp));
            dp[now][0] = 1;
            for (int j = 1; j < rk[i]; ++j)
            {
                std::swap(now, lst);
                memset(dp[now], 0, sizeof(dp[now]));
                if (~a[j])
                    if (ik[j] < i)
                        for (int k = 0; k <= n; ++k)
                            add(dp[now][k + 1], dp[lst][k]), add(dp[now][k], dp[lst][k]);
                    else
                        for (int k = 0; k <= n; ++k)
                            add(dp[now][k], dp[lst][k] * 2 % MOD);
                else
                    for (int k = 0; k <= n; ++k)
                        add(dp[now][std::max(0, k - 1)], dp[lst][k]), add(dp[now][k], dp[lst][k]);
            }
            for (int j = rk[i]; ++j <= n;)
            {
                std::swap(now, lst);
                memset(dp[now], 0, sizeof(dp[now]));
                if (~a[j])
                    if (ik[j] < i)
                        for (int k = 0; k <= n; ++k)
                            add(dp[now][k + 1], dp[lst][k]), add(dp[now][k], dp[lst][k]);
                    else
                        for (int k = 0; k <= n; ++k)
                            add(dp[now][k], dp[lst][k] * 2 % MOD);
                else
                    for (int k = 0; k <= n; ++k)
                        k ? add(dp[now][k - 1], dp[lst][k]) : void(), add(dp[now][k], dp[lst][k]);
            }
            add(ans, std::accumulate(dp[now], dp[now] + 1 + n, 0ll) % MOD * a[rk[i]] % MOD);
        }
        else
            break;
    std::cout << ans << std::endl;
    return 0;
}