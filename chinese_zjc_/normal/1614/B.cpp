// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], rk[200005], ans[200005];
long long tot;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        tot = 0;
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], rk[i] = i;
        std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
                  { return a[A] > a[B]; });
        for (int i = 1; i <= n; ++i)
            tot += 1ll * a[rk[i]] * std::abs(ans[rk[i]] = (i & 1 ? +1 : -1) * ((i + 1) / 2));
        std::cout << tot * 2 << std::endl;
        for (int i = 0; i <= n; ++i)
            std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}