// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long T, s, n, k;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> s >> n >> k;
        if (s == k)
            std::cout << "YES" << std::endl;
        else if (s < k)
            std::cout << "NO" << std::endl;
        else
        {
            ++n;
            long long max = s / (k * 2) * k + std::min(s % (k * 2), k) + 1 - (s % (k * 2) >= k);
            std::cout << (n <= max ? "NO" : "YES") << std::endl;
        }
    }
    return 0;
}