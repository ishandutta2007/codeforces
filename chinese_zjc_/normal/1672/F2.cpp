// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> v[200005];
int T, n, cnt[200005], a[200005], b[200005], vis[200005];
bool flag;
void find(int now)
{
    vis[now] = 1;
    for (auto i : v[now])
        if (vis[i] == 1)
            flag = false;
        else if (!vis[i])
            find(i);
    vis[now] = 2;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        flag = true;
        for (int i = 1; i <= n; ++i)
            v[i].clear();
        std::fill(cnt + 1, cnt + 1 + n, 0);
        std::fill(vis + 1, vis + 1 + n, 0);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            ++cnt[a[i]];
        }
        int pos = std::max_element(cnt + 1, cnt + 1 + n) - cnt;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i];
            if (a[i] != pos && b[i] != pos)
                v[a[i]].push_back(b[i]);
        }
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
                find(i);
        std::cout << (flag ? "AC" : "WA") << std::endl;
    }
    return 0;
}