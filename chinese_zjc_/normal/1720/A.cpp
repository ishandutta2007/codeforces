// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long a, b, c, d;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> a >> b >> c >> d;
        a *= d;
        b *= c;
        if (a == b)
            std::cout << 0 << std::endl;
        else if (a == 0 || b == 0 || a % b == 0 || b % a == 0)
            std::cout << 1 << std::endl;
        else
            std::cout << 2 << std::endl;
    }
    return 0;
}