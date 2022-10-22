// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
int T, a[200005], n, q, rk[200005], b[200005], c[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= q; ++i)
            std::cin >> b[i];
        std::iota(rk + 1, rk + 1 + q, 1);
        std::sort(rk + 1, rk + 1 + q, [&](const int &A, const int &B)
                  { return b[A] < b[B]; });
        long long ans = 0;
        for (int i = 1, j = 0; i <= q; ++i)
        {
            while (j < n && a[j + 1] <= b[rk[i]])
                ans += a[++j];
            c[rk[i]] = ans;
        }
        for (int i = 1; i <= q; ++i)
            std::cout << c[i] << " \n"[i == q];
    }
    return 0;
}