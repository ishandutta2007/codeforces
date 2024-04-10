// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[2025];
std::vector<int> ans;
void work(int x)
{
    std::reverse(a + 1, a + 1 + x);
    ans.push_back(x);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        ans.clear();
        while (n > 1)
        {
            int pos1 = std::find(a + 1, a + 1 + n, n) - a;
            if (~pos1 & 1)
            {
                std::cout << -1 << std::endl;
                goto nextcase;
            }
            work(pos1);
            int pos2 = std::find(a + 1, a + 1 + n, n - 1) - a;
            if (pos2 & 1)
            {
                std::cout << -1 << std::endl;
                goto nextcase;
            }
            work(pos2 - 1);
            work(pos2 + 1);
            work(3);
            work(n);
            n -= 2;
        }
        std::cout << ans.size() << std::endl;
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
    nextcase:;
    }
    return 0;
}