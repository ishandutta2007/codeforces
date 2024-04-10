// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long T, A, B, C;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> A >> B >> C;
        std::cout << (std::max({A, B, C}) - 1 <= A + B + C - std::max({A, B, C}) ? "Yes" : "No") << std::endl;
    }
    return 0;
}