// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::vector<int> ans;
        for (int i = 1, j = i; i <= n; i = j)
        {
            while (j <= n && a[j] == a[i])
                ++j;
            if (j - i == 1)
            {
                ans = {-1};
                break;
            }
            for (int k = i; k != j; ++k)
                ans.push_back(k + 1 == j ? i : k + 1);
        }
        std::fill(a + 1, a + 1 + n, 0);
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}