// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, cnt;
bool all;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        cnt = 0;
        all = true;
        for (int i = 1; i <= n; ++i)
        {
            static std::string s;
            std::cin >> s;
            cnt += std::count(s.begin(), s.end(), '1');
            all &= !(s.size() & 1);
        }
        std::cout << n - (all && cnt & 1) << std::endl;
    }
    return 0;
}