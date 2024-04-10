// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, app[26][26], cnt;
char a[200005], b[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        for (int i = n; i--;)
            std::cin >> b[i], app[a[i] - 'a'][b[i] - 'a'] ^= true, a[i] != b[i] ? app[b[i] - 'a'][a[i] - 'a'] ^= true : 0;
        for (int i = 0; i != 26; ++i)
            for (int j = 0; j != 26; ++j)
                cnt += app[i][j];
        std::cout << (cnt <= 1 ? "YES" : "NO") << std::endl;
        std::memset(app, 0, sizeof(app));
        cnt = 0;
    }
    return 0;
}