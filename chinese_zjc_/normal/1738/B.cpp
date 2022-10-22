// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k, s[100005], a[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        std::fill(s + 1, s + 1 + n, 0);
        std::fill(a + 1, a + 1 + n, 0);
        for (int i = n - k + 1; i <= n; ++i)
            std::cin >> s[i], a[i] = s[i] - s[i - 1];
        if (k == 1)
            std::cout << "Yes" << std::endl;
        else if (k == n)
            std::cout << (std::is_sorted(a + 1, a + 1 + n) ? "Yes" : "No") << std::endl;
        else
            std::cout << (std::is_sorted(a + n - k + 2, a + 1 + n) &&
                                  1ll * a[n - k + 2] * (n - k + 1) >= s[n - k + 1]
                              ? "Yes"
                              : "No")
                      << std::endl;
    }
    return 0;
}