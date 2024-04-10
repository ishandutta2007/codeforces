// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, b[100005], k;
bool vis[100005];
std::vector<int> t[100005], a;
void work(int x)
{
    std::sort(t[x].begin(), t[x].end(), [&](const int &A, const int &B)
              { return t[A].size() < t[B].size(); });
    for (auto i : t[x])
        a.push_back(i);
    if (!t[x].empty())
        work(t[x].back());
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        k = 0;
        a.clear();
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i], t[b[i]].push_back(i);
        work(0);
        work(n + 1);
        for (int i = 0; i != n; ++i)
            if (a[i] < b[a[i]])
                k = std::max(k, a[i]);
        std::cout << k << std::endl;
        for (int i = 0; i != n; ++i)
            std::cout << a[i] << " \n"[i + 1 == n];
        for (int i = 0; i <= n + 1; ++i)
            t[i].clear();
    }
    return 0;
}