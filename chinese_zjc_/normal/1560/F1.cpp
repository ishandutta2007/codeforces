// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string n, ans;
int T, k;
bool dfs(int now, int use, bool lim)
{
    if (__builtin_popcount(use) > k)
        return false;
    if (now == int(n.size()))
        return std::cout << ans << std::endl, true;
    for (int i = lim ? n[now] - '0' : 0; i <= 9; ++i)
    {
        ans.push_back(i + '0');
        if (dfs(now + 1, use | 1 << i, lim && i == n[now] - '0'))
        {
            ans.pop_back();
            return true;
        }
        ans.pop_back();
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        if (!dfs(0, 0, true))
            std::cout << '1' << std::string(n.size(), '0' + (k == 1)) << std::endl;
    }
    return 0;
}