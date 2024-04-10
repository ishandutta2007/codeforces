// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m;
long long solve(int a, int b)
{
    if (a % 3 == 0)
        return a / 3 * b;
    if (b % 3 == 0)
        return b / 3 * a;
    if (a >= 3)
        return a / 3 * b + solve(a % 3, b);
    if (b >= 3)
        return b / 3 * a + solve(a, b % 3);
    return a == 2 && b == 2 ? 2 : 1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        std::cout << solve(n, m) << std::endl;
    }
    return 0;
}