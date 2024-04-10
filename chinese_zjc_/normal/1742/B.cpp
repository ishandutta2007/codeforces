// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T,n,x;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::set<int> s;
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> x, s.insert(x);
        std::cout << (int(s.size()) == n ? "YES" : "NO") << std::endl;
    }
    return 0;
}