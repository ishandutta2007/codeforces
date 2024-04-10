// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, ans;
std::string c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> c;
        ans = INT_MAX;
        for (int i = 0; i != n; ++i)
        {
            int cnt[3] = {0, 0, 0};
            ++cnt[c[i] - 'a'];
            for (int j = i + 1; j != n && j - i <= 20; ++j)
            {
                ++cnt[c[j] - 'a'];
                if (cnt[0] > cnt[1] && cnt[0] > cnt[2])
                    ans = std::min(ans, j - i + 1);
            }
        }
        std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;
    }
    return 0;
}