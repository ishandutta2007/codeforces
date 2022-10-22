// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, a[100005], ans;
std::map<int, int> dp[100005];
std::vector<int> lb[100005], rb[100005];
int dfs(int l, int r)
{
    std::pair<std::map<int, int>::iterator, bool> t = dp[r].insert({l, 0});
    if (!t.second)
        return t.first->second;
    int &v = t.first->second;
    for (int i : lb[l])
        if (l + i <= r)
            v = std::max(v, 1 + dfs(l + i, r));
    for (int i : rb[r])
        if (l <= r - i)
            v = std::max(v, dfs(l, r - i) + 1);
    return v;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    while (n--)
    {
        std::cin >> a[++m];
        if (a[m - 1] == a[m])
            lb[m - 1] = rb[m] = {1};
        for (int len : rb[m - 1])
            if (a[m - len * 2 - 1] == a[m])
                rb[m].push_back(len + 1), lb[m - len * 2 - 1].push_back(len + 1);
        int l = 0;
        for (int len : rb[m])
            if (std::binary_search(rb[m - len].begin(), rb[m - len].end(), len))
                l = len;
        if (l)
            for (l *= 2, ++ans; l--; --m)
            {
                for (int len : rb[m])
                    lb[m - len * 2 + 1].pop_back();
                dp[m].clear();
                rb[m].clear();
            }
        else
            dfs(1, m);
        std::cout << dp[m][1] + ans * 2 << " \n"[!~n];
    }
    return 0;
}