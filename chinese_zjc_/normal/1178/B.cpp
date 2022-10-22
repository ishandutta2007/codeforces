// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int l, r;
long long ans;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    for (int i = 1; i != int(s.size()); ++i)
        if (s[i] == 'v' && s[i - 1] == 'v')
            ++r;
    for (int i = 0; i != int(s.size()); ++i)
        if (s[i] == 'o')
            ans += 1ll * l * r;
        else if (i && s[i] == 'v' && s[i - 1] == 'v')
            ++l, --r;
    std::cout << ans << std::endl;
    return 0;
}