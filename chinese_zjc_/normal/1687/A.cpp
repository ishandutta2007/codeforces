// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int n, k, T, a[200005];
long long sum[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        if (n < k)
        {
            for (int i = 1; i <= n; ++i)
                a[i] += k - n;
            k = n;
        }
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + a[i];
        long long ans = 0;
        for (int i = k; i <= n; ++i)
            ans = std::max(ans, sum[i] - sum[i - k]);
        std::cout << ans + k * (k - 1ll) / 2 << std::endl;
    }
    return 0;
}