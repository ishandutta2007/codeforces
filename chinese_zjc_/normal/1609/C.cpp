// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, e, n;
long long a[200005], ans;
bool is[1000005];
std::vector<int> p;
std::map<long long, long long> dp[200005];
bool check(long long x) { return x <= 1000000 && is[x]; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::fill(is + 1, is + 1000001, true);
    for (int i = 2; i <= 1000000; ++i)
    {
        if (is[i])
            p.push_back(i);
        for (auto j : p)
        {
            if (i * j > 1000000)
                break;
            is[i * j] = false;
            if (i % j == 0)
                break;
        }
    }
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> e;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], dp[i].clear();
        for (int i = n; i; --i)
            if (i + e <= n)
            {
                if (check(a[i] * a[i + e]))
                    ++dp[i][a[i] * a[i + e]];
                for (auto j : dp[i + e])
                    if (check(a[i] * j.first))
                        dp[i][a[i] * j.first] += j.second;
            }
        for (int i = 1; i <= n; ++i)
            for (auto j : dp[i])
                if (j.first > 1)
                    ans += j.second;
        std::cout << ans << std::endl;
        ans = 0;
    }
    return 0;
}