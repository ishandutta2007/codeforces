// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long n, k, now, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        ans = 0;
        now = 1;
        while (now < k && now < n)
        {
            now += now;
            ++ans;
        }
        std::cout << ans + (now < n ? (n - now - 1) / k + 1 : 0) << std::endl;
    }
    return 0;
}