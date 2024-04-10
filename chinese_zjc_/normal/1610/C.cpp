// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], b[200005];
bool check(int ans)
{
    int now = 0, lim = n;
    for (int i = 1; i <= n; ++i)
        if (now <= b[i] && now + 1 + std::min(lim - 1, a[i]) >= ans)
            ++now, lim = std::min(lim - 1, a[i]);
    return now >= ans;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i] >> b[i];
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}