// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long n;
int T, a, b;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> a >> b;
        std::cout << std::min(n * a, n / 2 * b + (n & 1) * a) << std::endl;
    }
    return 0;
}