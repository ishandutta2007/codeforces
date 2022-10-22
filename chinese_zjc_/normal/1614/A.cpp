// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, l, r, k, a;
std::vector<int> s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        s.clear();
        int ans = 0;
        std::cin >> n >> l >> r >> k;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a;
            if (l <= a && a <= r)
                s.push_back(a);
        }
        std::sort(s.begin(), s.end());
        for (auto i : s)
            if (i <= k)
                ++ans, k -= i;
        std::cout << ans << std::endl;
    }
    return 0;
}