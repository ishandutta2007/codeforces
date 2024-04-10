// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[505], b[505], d[505][505];
bool ans;
std::vector<std::pair<int, int>> g;
void work(int l, int r)
{
    std::reverse(a + l, a + r + 1);
    g.push_back({l, r});
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];
        for (int i = 1; i < n; ++i)
            ++d[std::min(a[i], a[i + 1])][std::max(a[i], a[i + 1])];
        for (int i = 1; i < n; ++i)
            --d[std::min(b[i], b[i + 1])][std::max(b[i], b[i + 1])];
        ans = a[1] != b[1] || a[n] != b[n];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                ans |= d[i][j];
        std::cout << (ans ? "NO" : "YES") << std::endl;
        if (!ans)
        {
            g.clear();
            for (int i = 1; i <= n; ++i)
                if (a[i] != b[i])
                {
                    for (int j = i; j <= n; ++j)
                        if (a[j] == b[i] && a[j - 1] == a[i - 1])
                        {
                            bool flag = true;
                            for (int k = j - 1; flag && k >= i - 1; --k)
                                for (int l = j; flag && l <= n; ++l)
                                    if (a[k] == a[l])
                                    {
                                        work(k, l);
                                        flag = false;
                                    }
                            break;
                        }
                    for (int j = i; j < n; ++j)
                        if (a[j] == b[i] && a[j + 1] == a[i - 1])
                            work(i - 1, j + 1);
                }
            std::cout << g.size() << std::endl;
            for (auto i : g)
                std::cout << i.first << ' ' << i.second << std::endl;
        }
    }
    return 0;
}