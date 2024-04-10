// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, a[100005], b[100005], rk[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], b[i] = a[i] - a[i - 1];
        std::iota(rk + 1, rk + 1 + n, 1);
        std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
                  { return b[A] > b[B]; });
        for (int i = 1; i <= n; ++i)
            std::cout << rk[i] << " \n"[i == n];
    }
    return 0;
}