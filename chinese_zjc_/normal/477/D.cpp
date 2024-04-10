// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string n;
const int MOD = 1000000007;
int m, h[5005][5005], tim[5005][5005], way[5005][5005];
bool check(int x, int y)
{
    int tmp = h[x][y];
    return x + tmp >= y || n[x + tmp] < n[y + tmp];
}
signed main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    m = n.size();
    memset(h, 0x3f, sizeof(h));
    for (int i = m; i--;)
        for (int j = m; j--;)
            h[i][j] = n[i] == n[j] ? h[i + 1][j + 1] + 1 : 0;
    memset(tim, 0x3f, sizeof(tim));
    way[0][0] = 1;
    tim[0][0] = 0;
    for (int i = 0; i <= m; ++i)
        if (n[i] == '1')
        {
            int k = 0, sum = 0, min = INT_MAX;
            for (int j = i; ++j <= m;)
            {
                while (i - k >= 0 && (k < j - i || (k == j - i && check(i - k, i))))
                {
                    // std::cout << n.substr(i - k, k) << ' ' << n.substr(i, j - i) << std::endl;
                    sum = (sum + way[i][k]) % MOD;
                    min = std::min(min, tim[i][k]);
                    ++k;
                }
                way[j][j - i] = sum;
                tim[j][j - i] = min + 1;
            }
        }
    // for (int i = 0; i <= m; ++i)
    //     for (int j = 0; j <= m; ++j)
    //         std::cout << way[i][j] << " \n"[j == m];
    int ans = 0, v = 0;
    for (int i = 0; i <= m; ++i)
        ans = (ans + way[m][i]) % MOD;
    std::cout << ans << std::endl;
    ans = -1;
    for (int i = 1, base = 1; i <= m && (ans == -1 || i <= std::log2(m)); ++i, base = base * 2 % MOD)
    {
        v = (v + (n[m - i] == '1') * base) % MOD;
        if (tim[m][i] <= m && (ans == -1 || v + tim[m][i] < ans))
            ans = (v + tim[m][i]) % MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}