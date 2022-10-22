// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[11];
unsigned long long k, ans, pow10[20];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        ans = 0;
        ++k;
        pow10[0] = 1;
        for (int i = 1; i != 20; ++i)
            pow10[i] = pow10[i - 1] * 10;
        a[n] = 19;
        for (int i = 0; k && i != n; ++i)
        {
            int cnt = std::min(pow10[a[i + 1] - a[i]] - 1, k);
            k -= cnt;
            ans += cnt * pow10[a[i]];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}