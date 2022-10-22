// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, k, t[26];
char c[1005];
std::string ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        ans = "";
        std::memset(t, 0, sizeof(t));
        for (int i = 0; i != n; ++i)
            std::cin >> c[i], ++t[c[i] - 'a'];
        for (int i = 0; i != k; ++i)
        {
            for (int j = 0; j != n / k; ++j)
                if (t[j] <= i)
                {
                    ans += 'a' + j;
                    break;
                }
            if (int(ans.size()) <= i)
                ans += 'a' + n / k;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}