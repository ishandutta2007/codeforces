// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a, sum;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        sum = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a, sum += a - 1;
        std::cout << (sum & 1 ? "errorgorn" : "maomao90") << std::endl;
    }
    return 0;
}