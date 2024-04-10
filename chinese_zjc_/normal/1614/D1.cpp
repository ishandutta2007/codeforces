// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int lim = 20000000;
int n, a[100005], cnt[lim + 5], from[lim + 5];
long long dp[lim + 5];
std::vector<int> p;
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 2; i <= lim; ++i)
    {
        if (!from[i])
        {
            p.push_back(i);
            from[i] = i;
        }
        for (auto j : p)
        {
            if (i * j > lim)
                break;
            from[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> a[i];
        for (int j = 1; j * j <= a[i]; ++j)
            if (a[i] % j == 0)
            {
                ++cnt[j];
                if (j * j != a[i])
                    ++cnt[a[i] / j];
            }
    }
    for (long long i = 20000000; i; --i)
    {
        dp[i] = std::max(dp[i], cnt[i] * i);
        int j = i;
        while (j > 1)
        {
            int k = from[j];
            while (j % k == 0)
                j /= k;
            dp[i / k] = std::max(dp[i / k], dp[i] + (i / k) * (cnt[i / k] - cnt[i]));
        }
    }
    std::cout << dp[1] << std::endl;
    return 0;
}