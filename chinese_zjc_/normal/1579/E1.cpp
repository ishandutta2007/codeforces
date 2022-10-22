// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::deque<int> ans;
int T, n, a[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans.clear();
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        ans.push_back(a[1]);
        for (int i = 2; i <= n; ++i)
            if (a[i] > ans.front())
                ans.push_back(a[i]);
            else
                ans.push_front(a[i]);
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}