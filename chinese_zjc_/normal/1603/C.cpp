// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const long long MOD = 998244353;
int T, n, a[100005];
long long ans;
std::vector<std::pair<long long, long long>> dp[2];
bool now = true, lst = false;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        ans = 0;
        dp[now].clear();
        dp[now].push_back({0, 0});
        for (int i = 1; i <= n; ++i)
        {
            std::swap(now, lst);
            dp[now].clear();
            std::vector<std::pair<long long, long long>>::iterator iter = dp[lst].begin();
            for (int l = 1, r; l <= a[i] - 1; l = r + 1)
            {
                r = std::min((a[i] - 1) / ((a[i] - 1) / l), a[i] / (a[i] / l));
                while (iter->first >= a[i] / l)
                    ++iter;
                dp[now].push_back({(a[i] - 1) / l, ((l - 1ll) * i + iter->second) % MOD});
            }
            dp[now].push_back({0, ((a[i] - 1ll) * i + dp[lst].back().second) % MOD});
            ans = (ans + dp[now].front().second) % MOD;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}