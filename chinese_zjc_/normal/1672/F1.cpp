// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> v[200005];
int T, n, cnt[200005], a[200005], b[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            v[i].clear();
        std::fill(cnt + 1, cnt + 1 + n, 0);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            v[cnt[a[i]]++].push_back(i);
        }
        for (int i = 0; i != n; ++i)
        {
            if (v[i].empty())
                break;
            std::sort(v[i].begin(), v[i].end(), [&](const int &x, const int &y)
                      { return a[x] < a[y]; });
            for (std::size_t j = 1; j != v[i].size(); ++j)
                b[v[i][j - 1]] = a[v[i][j]];
            b[v[i].back()] = a[v[i].front()];
        }
        for (int i = 1; i <= n; ++i)
            std::cout << b[i] << " \n"[i == n];
    }
    return 0;
}