// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
// #define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int T, n, a[100005], v[100005], app[100005], max, cnt;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::fill(v + 1, v + 1 + n, 0);
        std::fill(app + 1, app + 1 + n, 0);
        cnt = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], ++app[a[i]];
        ++v[a[1]];
        ++v[a[n]];
        for (int i = 1; i != n; ++i)
            if (a[i] == a[i + 1])
                ++v[a[i]], ++v[a[i]], ++cnt;
        max = *std::max_element(v + 1, v + 1 + n);
        if (*std::max_element(app + 1, app + 1 + n) > (n + 1) / 2)
            std::cout << -1 << std::endl;
        else
            std::cout << cnt + std::max(0, max - cnt - 2) << std::endl;
    }
    return 0;
}