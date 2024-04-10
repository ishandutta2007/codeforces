// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
char s[300005];
long long ans;
std::vector<int> app[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> s[i];
        app[s[i] == 'A'].push_back(i);
    }
    ans = n * (n - 1ll) / 2;
    for (int k = 0; k != 2; ++k)
        if (!app[k].empty())
        {
            for (int i = 1; i < int(app[k].size()); ++i)
                ans -= 2 * (app[k][i] - app[k][i - 1] - 1);
            ans -= (app[k].front() - 1) + (n - app[k].back());
        }
    for (int i = 1; i < n; ++i)
        if (s[i] != s[i + 1])
            ++ans;
    std::cout << ans << std::endl;
    return 0;
}