// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, m, a[200005], b[200005], l[200005], r[200005];
long long s[200005];
std::vector<int> g[200005];
std::set<int> bad;
std::queue<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];
        for (int i = 1; i <= n; ++i)
            s[i] = s[i - 1] + a[i] - b[i];
        for (int i = 1; i <= m; ++i)
        {
            std::cin >> l[i] >> r[i];
            --l[i];
            g[l[i]].push_back(i);
            g[r[i]].push_back(i);
        }
        for (int i = 0; i <= n; ++i)
            if (s[i] == 0)
                que.push(i);
            else
                bad.insert(i);
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (int i : g[now])
                if (!bad.count(l[i]) && !bad.count(r[i]))
                    for (std::set<int>::iterator j = bad.upper_bound(l[i]); j != bad.end() && *j < r[i]; bad.erase(j++))
                        que.push(*j);
        }
        std::cout << (bad.empty() ? "YES" : "NO") << std::endl;
        for (int i = 0; i <= n; ++i)
            g[i].clear();
        bad.clear();
    }
    return 0;
}