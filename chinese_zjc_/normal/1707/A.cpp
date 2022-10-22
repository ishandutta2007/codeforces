// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, q, a[100005], pre[100005];
bool check(int x)
{
    int cur = q;
    for (int i = x; i <= n; ++i)
        if (a[i] > cur)
        {
            if (cur == 0)
                return false;
            --cur;
        }
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + (a[i] <= q);
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid + 1))
                r = mid;
            else
                l = mid + 1;
        }
        for (int i = 1; i <= l; ++i)
            std::cout << (a[i] <= q);
        for (int i = l + 1; i <= n; ++i)
            std::cout << 1;
        std::cout << std::endl;
    }
    return 0;
}