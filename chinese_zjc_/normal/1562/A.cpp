// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, l, r, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> l >> r;
        ans = r % l;
        for (int i = r; i >= std::max(r - 5, l); --i)
            if (i / 2 + 1 >= l)
                ans = std::max(ans, i % (i / 2 + 1));
        std::cout << ans << std::endl;
    }
    return 0;
}