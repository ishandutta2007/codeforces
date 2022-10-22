// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, a[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = n; i; --i)
            a[i] = (i - n) & 1 ? i + 1 : i - 1;
        if (a[1] == 0)
            a[1] = 1;
        for (int i = 1; i <= n; ++i)
            std::cout << a[i] << " \n"[i == n];
    }
    return 0;
}