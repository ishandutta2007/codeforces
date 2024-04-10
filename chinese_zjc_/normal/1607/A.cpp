// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, ans;
std::string a, b;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> a >> b;
        ans = 0;
        for (int i = 1; i != (int)b.size(); ++i)
            ans += std::abs(int(a.find(b[i - 1])) - int(a.find(b[i])));
        std::cout << ans << std::endl;
    }
    return 0;
}