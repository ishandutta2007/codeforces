// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
long long a[200005];
template <class T>
T check(T t)
{
    T res = a[1] * a[n] + t * (a[1] + a[n]);
    for (int i = 2; i < n; ++i)
        res += std::min(a[1] * a[i] + t * (a[1] + a[i]), a[i] * a[n] + t * (a[i] + a[n]));
    return res;
}
void work()
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::sort(a + 1, a + 1 + n);
    long double l1 = check(-1e8), l2 = check(-2e8), r1 = check(+1e8), r2 = check(+2e8);
    if (l1 > 0 && std::abs(l1 - l2) / l1 > 0.5)
        return std::cout << "INF" << std::endl, void();
    if (r1 > 0 && std::abs(r1 - r2) / r1 > 0.5)
        return std::cout << "INF" << std::endl, void();
    long long l = -1e6, r = 1e6;
    for (int i = 1; i <= 40; ++i)
    {
        long long mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        long long res1 = check(mid1), res2 = check(mid2);
        if (res1 > res2)
            r = mid2;
        else
            l = mid1;
    }
    std::cout << std::max({check(l), check(l + 1), check(r)}) << std::endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        work();
    }
    return 0;
}