// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, dp[500005];
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 1; i <= 100; ++i)
    {
        bool has[16];
        std::memset(has, false, sizeof(has));
        for (int j = 0; j <= i - 2; ++j)
            has[dp[j] ^ dp[i - 2 - j]] = true;
        while (has[dp[i]])
            ++dp[i];
    }
    for (int i = 101; i <= 500000; ++i)
        dp[i] = dp[i - 34];
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::cin >> s;
        int t = std::count(s.begin(), s.end(), 'R') - std::count(s.begin(), s.end(), 'B');
        if (t > 0)
            std::cout << "Alice" << std::endl;
        else if (t < 0)
            std::cout << "Bob" << std::endl;
        else
        {
            int lst = 0, ans = 0;
            for (int i = 1; i != n; ++i)
                if (s[i - 1] == s[i])
                    ans ^= dp[i - lst], lst = i;
            ans ^= dp[n - lst];
            std::cout << (ans ? "Alice" : "Bob") << std::endl;
        }
    }
    return 0;
}