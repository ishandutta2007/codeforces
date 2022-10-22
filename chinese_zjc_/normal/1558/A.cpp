// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> ans;
int T, a, b, l;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans.clear();
        std::cin >> a >> b;
        l = (a + b) / 2;
        for (int k = 0; k <= a + b; ++k)
            if ((l + k - a >= 0 && (l + k - a) % 2 == 0 && (l + k - a) / 2 <= std::min(k, l) && (k - (l + k - a) / 2) <= a + b - l) ||
                (l + k - b >= 0 && (l + k - b) % 2 == 0 && (l + k - b) / 2 <= std::min(k, l) && (k - (l + k - b) / 2) <= a + b - l))
                ans.push_back(k);
        std::cout << ans.size() << std::endl;
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}