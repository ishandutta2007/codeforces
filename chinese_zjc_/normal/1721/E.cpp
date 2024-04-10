// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s;
int n, m, q, to[1000015][26], kmp[1000015];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    n = s.size();
    to[0][s[0] - 'a'] = 1;
    for (int i = 1, j = 0; i != n; ++i)
    {
        for (int k = 0; k != 26; ++k)
            to[i][k] = k == s[i] - 'a' ? i + 1 : to[j][k];
        kmp[i + 1] = j = to[j][s[i] - 'a'];
    }
    std::cin >> q;
    for (int g = 0; g != q; ++g)
    {
        static std::string t;
        std::cin >> t;
        m = t.size();
        s += t;
        for (int i = n, j = kmp[n]; i != n + m; ++i)
        {
            for (int k = 0; k != 26; ++k)
                to[i][k] = k == s[i] - 'a' ? i + 1 : to[j][k];
            std::cout << (kmp[i + 1] = j = to[j][s[i] - 'a']) << " \n"[i + 1 == n + m];
        }
        s.erase(n);
    }
    return 0;
}