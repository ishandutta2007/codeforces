// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[100005], b[100005], lst[20005];
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(lst, -1, sizeof(lst));
    std::cin >> T;
    while (T--)
    {
        for (int i = 0; i != n; ++i)
            lst[a[i] + 10000] = -1;
        std::cin >> n;
        std::fill(b, b + n, 0);
        for (int i = 0; i != n; ++i)
        {
            std::cin >> a[i];
            if (~lst[a[i] + 10000])
            {
                b[lst[a[i] + 10000]] = -1;
                lst[a[i] + 10000] = -1;
                b[i] = 1;
            }
            else if (~lst[-a[i] + 10000])
            {
                b[lst[-a[i] + 10000]] = 1;
                lst[-a[i] + 10000] = -1;
                b[i] = 1;
            }
            else
                lst[a[i] + 10000] = i;
        }
        for (int i = 1; i != n; ++i)
            if (!b[i])
            {
                b[0] += a[i];
                b[i] -= a[0];
            }
        while (!b[0] || !b[1])
        {
            b[0] += a[1];
            b[1] -= a[0];
        }
        for (int i = 0; i != n; ++i)
            std::cout << b[i] << " \n"[i + 1 == n];
    }
    return 0;
}