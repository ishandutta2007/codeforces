// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, k, a[100005], b[100005];
bool check(int x)
{
    int lim = (x + 1) >> 1, tim = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] < lim)
            b[i] = 1000000000, ++tim;
        else
            b[i] = a[i];
    int t = 2;
    for (int i = 1; i < n; ++i)
        t = std::min(t, (b[i] < x) + (b[i + 1] < x));
    return tim + t <= k;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        int l = 0, r = 1000000000;
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