// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int a[300005], b[300005], n;
bool vis[600005], visid[300005];
std::vector<int> to[600005];
std::vector<std::vector<int>> ans;
void dfs(int now, int fa)
{
    ans.back().push_back(now);
    if (!vis[now])
    {
        vis[now] = true;
        for (auto i : to[now])
            if (!visid[i])
                visid[i] = true, dfs(now ^ a[i] ^ b[i], i), ans.back().push_back(now);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i] >> b[i];
        to[a[i]].push_back(i);
        to[b[i]].push_back(i);
    }
    for (int i = 1; i <= 2 * n; ++i)
        if (!vis[i])
            ans.emplace_back(), dfs(i, 0), ans.back().pop_back();
    for (auto i : ans)
        if (i.size() == 2)
            return std::cout << -1 << std::endl, 0;
    std::cout << n << ' ' << 2 << std::endl;
    for (auto i : ans)
        if (i.size() >> 1 & 1)
        {
            std::cout << i[0] << ' ' << i[1] << std::endl;
            for (std::size_t j = 1; j << 2 < i.size(); ++j)
                std::cout << i[i.size() - (j << 1) + 1] << ' ' << i[j << 1] << std::endl
                          << i[i.size() - (j << 1)] << ' ' << i[j << 1 | 1] << std::endl;
        }
        else if (!i.empty())
        {
            std::cout << i[0] << ' ' << i[1] << std::endl;
            for (std::size_t j = 1; j << 2 < i.size(); ++j)
                std::cout << i[i.size() - (j << 1) + 1] << ' ' << i[j << 1] << std::endl
                          << i[i.size() - (j << 1)] << ' ' << i[j << 1 | 1] << std::endl;
            std::cout << i[i.size() >> 1 | 1] << ' ' << i[i.size() >> 1] << std::endl;
        }
    for (auto i : ans)
        if (i.size() >> 1 & 1)
        {
            std::cout << "LR" << std::endl;
            for (std::size_t j = 1; j << 2 < i.size(); ++j)
                std::cout << "UU" << std::endl
                          << "DD" << std::endl;
        }
        else if (!i.empty())
        {
            std::cout << "LR" << std::endl;
            for (std::size_t j = 1; j << 2 < i.size(); ++j)
                std::cout << "UU" << std::endl
                          << "DD" << std::endl;
            std::cout << "LR" << std::endl;
        }
    for (auto i : ans)
        if (i.size() >> 1 & 1)
        {
            for (std::size_t j = 1; j << 2 < i.size(); ++j)
                std::cout << "UU" << std::endl
                          << "DD" << std::endl;
            std::cout << "LR" << std::endl;
        }
        else if (!i.empty())
        {
            for (std::size_t j = 0; j << 2 < i.size(); ++j)
                std::cout << "UU" << std::endl
                          << "DD" << std::endl;
        }
    return 0;
}