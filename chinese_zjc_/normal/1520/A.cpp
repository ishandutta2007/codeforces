// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s;
int T, n;
bool vis[26];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> s;
        s = ' ' + s;
        std::memset(vis, false, sizeof(vis));
        bool ans = true;
        for (int i = 1; i <= n; ++i)
            if (vis[s[i] - 'A'] && s[i - 1] != s[i])
                ans = false;
            else
                vis[s[i] - 'A'] = true;
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}