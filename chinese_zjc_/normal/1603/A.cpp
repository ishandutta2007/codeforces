// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[100005];
bool check()
{
    for (long long i = 1, lcm = 1; lcm <= 1000000000 && i <= n; ++i)
    {
        lcm = lcm * (i + 1) / std::__gcd(lcm, i + 1);
        if (a[i] % lcm == 0)
            return false;
    }
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::cout << (check() ? "YES" : "NO") << std::endl;
    }
    return 0;
}