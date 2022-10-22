// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, k, fa[200005];
long long ans, s[200005];
std::vector<int> son[200005];
long long dfs(int now, int k)
{
    ans += k * s[now];
    if (son[now].empty())
        return s[now];
    int per = k / son[now].size();
    std::vector<long long> v;
    for (auto i : son[now])
        v.push_back(dfs(i, per));
    std::sort(v.begin(), v.end());
    k %= son[now].size();
    while (k--)
    {
        ans += v.back();
        v.pop_back();
    }
    return v.back() + s[now];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 2; i <= n; ++i)
            std::cin >> fa[i], son[fa[i]].push_back(i);
        for (int i = 1; i <= n; ++i)
            std::cin >> s[i];
        ans = 0;
        dfs(1, k);
        std::cout << ans << std::endl;
        for (int i = 1; i <= n; ++i)
            son[i].clear();
    }
    return 0;
}