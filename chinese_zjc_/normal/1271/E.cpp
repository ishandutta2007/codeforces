// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long n, k, ans;
long long calc(long long x)
{
    long long res = 0;
    for (int i = 0; x << i <= n; ++i)
        res += std::min(n + 1, (x << i) + (1ll << i)) - (x << i);
    if (~x & 1)
    {
        ++x;
        for (int i = 0; x << i <= n; ++i)
            res += std::min(n + 1, (x << i) + (1ll << i)) - (x << i);
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 60; i--;)
        if (calc(ans | 1ll << i) >= k)
            ans |= 1ll << i;
    std::cout << ans << std::endl;
    return 0;
}