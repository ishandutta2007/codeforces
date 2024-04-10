// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T;
long long l, r;
long long calc(long long v)
{
    long long lim = std::max(0, int(sqrt(v)) - 10);
    long long A = lim, B = lim, C = lim;
    while (A * A <= v)
        ++A;
    while (B * (B + 1) <= v)
        ++B;
    while (C * (C + 2) <= v)
        ++C;
    return A + B + C;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> l >> r;
        std::cout << calc(r) - calc(l - 1) << std::endl;
    }
    return 0;
}