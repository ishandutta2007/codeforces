// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
char s[5005];
int ans, n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (s + 1);
    n = std::strlen(s + 1);
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = 0;
        for (int j = i; j <= n; ++j)
        {
            switch (s[j])
            {
            case '(':
                ++l;
                ++r;
                break;
            case ')':
                --l;
                --r;
                break;
            case '?':
                --l;
                ++r;
            }
            l = std::max(0, l);
            if (l > r)
                break;
            if (((j ^ i) & 1) && l == 0)
                ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}