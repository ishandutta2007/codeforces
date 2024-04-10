// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int m, n, a[200005], b[200005], ra[200005], rb[200005], ans[200005];
long long c[200005];
void add(int l, int r, int x)
{
    if (l != r && (r - l) % n == 0)
    {
        c[0] += x;
        c[n] -= x;
        return;
    }
    l = (l + n) % n;
    r = (r + n) % n;
    if (l <= r)
    {
        c[l] += x;
        c[r] -= x;
    }
    else
    {
        c[l] += x;
        c[n] -= x;
        c[0] += x;
        c[r] -= x;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i], a[i] %= m;
    std::iota(ra, ra + n, 0);
    std::sort(ra, ra + n, [&](const int &A, const int &B)
              { return a[A] < a[B]; });
    for (int i = 0; i != n; ++i)
        std::cin >> b[i], b[i] %= m;
    std::iota(rb, rb + n, 0);
    std::sort(rb, rb + n, [&](const int &A, const int &B)
              { return b[A] < b[B]; });
    auto cmpbl = [&](const int &A, const int &B)
    { return b[A] < B; };
    auto cmpbu = [&](const int &A, const int &B)
    { return A < b[B]; };
    for (int i = 0, l, r; i != n; ++i)
    {
        l = 0;
        r = std::lower_bound(rb, rb + n, a[ra[i]] - m / 2, cmpbl) - rb;
        add(l - i, r - i, -a[ra[i]] + m);
        l = r;
        r = std::lower_bound(rb, rb + n, a[ra[i]], cmpbl) - rb;
        add(l - i, r - i, +a[ra[i]]);
        l = r;
        r = std::upper_bound(rb, rb + n, a[ra[i]] + m / 2, cmpbu) - rb;
        add(l - i, r - i, -a[ra[i]]);
        l = r;
        r = n;
        add(l - i, r - i, +a[ra[i]] + m);
    }
    auto cmpal = [&](const int &A, const int &B)
    { return a[A] < B; };
    auto cmpau = [&](const int &A, const int &B)
    { return A < a[B]; };
    for (int i = 0, l, r; i != n; ++i)
    {
        l = 0;
        r = std::lower_bound(ra, ra + n, b[rb[i]] - m / 2, cmpal) - ra;
        add(i - r + 1, i - l + 1, -b[rb[i]]);
        l = r;
        r = std::upper_bound(ra, ra + n, b[rb[i]], cmpau) - ra;
        add(i - r + 1, i - l + 1, +b[rb[i]]);
        l = r;
        r = std::upper_bound(ra, ra + n, b[rb[i]] + m / 2, cmpau) - ra;
        add(i - r + 1, i - l + 1, -b[rb[i]]);
        l = r;
        r = n;
        add(i - r + 1, i - l + 1, +b[rb[i]]);
    }
    for (int i = 1; i <= n; ++i)
        c[i] += c[i - 1];
    int x = std::min_element(c, c + n) - c;
    std::cout << c[x] << std::endl;
    for (int i = 0; i != n; ++i)
        ans[ra[i]] = rb[(i + x) % n];
    for (int i = 0; i != n; ++i)
        std::cout << ans[i] + 1 << " \n"[i + 1 == n];
    return 0;
}