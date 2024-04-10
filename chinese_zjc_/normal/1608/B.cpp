// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a, b;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> a >> b;
        if (std::abs(a - b) > 1 || a + b > n - 2)
        {
            std::cout << -1 << std::endl;
            continue;
        }
        std::vector<int> ans;
        int l = 1, r = n;
        if (a > b)
            ans.push_back(l++);
        else
            ans.push_back(r--);
        while (l <= r && (a || b))
            if (ans.back() > r)
                ans.push_back(l++), --b;
            else
                ans.push_back(r--), --a;
        if (l > r && (a || b))
        {
            std::cout << -1 << std::endl;
            continue;
        }
        while (l <= r)
            if (ans.back() > r)
                ans.push_back(r--);
            else
                ans.push_back(l++);
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}