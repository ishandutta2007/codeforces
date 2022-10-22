// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
int T, q, s[2][26];
bool check()
{
    int l = 0, r = 25;
    while (!s[0][l])
        ++l;
    while (!s[1][r])
        --r;
    return l == r ? !std::accumulate(s[0] + l + 1, s[0] + 26, 0ll) &&
                        (s[0][l] < s[1][r] || (s[0][l] == s[1][r] &&
                                               std::accumulate(s[1], s[1] + r, 0ll)))
                  : l < r;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> q;
        std::memset(s, 0, sizeof(s));
        s[0][0] = s[1][0] = 1;
        while (q--)
        {
            static int d, k;
            static std::string f;
            std::cin >> d >> k >> f;
            int tim[26];
            std::memset(tim, 0, sizeof(tim));
            for (auto i : f)
                ++tim[i - 'a'];
            --d;
            for (int i = 0; i != 26; ++i)
                s[d][i] += k * tim[i];
            std::cout << (check() ? "YES" : "NO") << std::endl;
        }
    }
    return 0;
}