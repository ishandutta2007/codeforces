// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
long long a[5005], ans = LLONG_MAX;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        long long lst = 0, res = 0;
        for (int j = i + 1; j <= n; ++j)
        {
            long long t = lst / a[j] + 1;
            res += t;
            lst = t * a[j];
        }
        lst = 0;
        for (int j = i - 1; j >= 1; --j)
        {
            long long t = lst / a[j] + 1;
            res += t;
            lst = t * a[j];
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << std::endl;
    return 0;
}