// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], b[200005], sum[200005], ans[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + (a[i] <= b[i + 1]);
        sum[n] = sum[n - 1];
        for (int i = 1, j = 1; i <= n; ++i)
        {
            while (sum[i - 1] - sum[j - 1] < i - j || b[j] < a[i])
                ++j;
            std::cout << b[j] - a[i] << " \n"[i == n];
        }
        sum[1] = 0;
        for (int i = 2; i <= n; ++i)
            sum[i] = sum[i - 1] + (a[i] <= b[i - 1]);
        for (int i = n, j = n; i; --i)
        {
            while (sum[j] - sum[i] < j - i)
                --j;
            ans[i] = b[j] - a[i];
        }
        for (int i = 1; i <= n; ++i)
            std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}