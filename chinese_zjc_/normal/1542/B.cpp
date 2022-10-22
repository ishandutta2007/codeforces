// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a, b;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> a >> b;
        bool ans = false;
        if (a == 1)
            ans = (n - 1) % b == 0;
        else
            for (long long i = 1; i <= n; i *= a)
                ans |= (n - i) % b == 0;
        std::cout << (ans ? "Yes" : "No") << std::endl;
    }
    return 0;
}