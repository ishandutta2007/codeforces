// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::set<std::vector<int>> bad;
std::vector<int> s[10];
int n, m;
struct node
{
    int val;
    std::vector<int> way;
    node(int x) : val(x), way() {}
    friend bool operator<(const node &A, const node &B) { return A.val < B.val; }
} now(0);
std::pair<node, bool> dfs(int pos)
{
    if (pos == n)
    {
        if (bad.count(now.way))
            return {-1, false};
        else
            return {now, true};
    }
    node max(-1);
    for (int i = s[pos].size(); i; --i)
    {
        now.way.push_back(i);
        now.val += s[pos][i - 1];
        std::pair<node, bool> res = dfs(pos + 1);
        now.way.pop_back();
        now.val -= s[pos][i - 1];
        max = std::max(max, res.first);
        if (res.second)
            return {max, i == int(s[pos].size())};
    }
    return {max, false};
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0, c; i != n; ++i)
    {
        std::cin >> c;
        s[i].resize(c);
        for (int j = 0; j != c; ++j)
            std::cin >> s[i][j];
    }
    std::cin >> m;
    for (int i = 0; i != m; ++i)
    {
        static std::vector<int> tmp(n);
        for (int j = 0; j != n; ++j)
            std::cin >> tmp[j];
        bad.insert(tmp);
    }
    std::vector<int> res = dfs(0).first.way;
    for (int i = 0; i != n; ++i)
        std::cout << res[i] << " \n"[i + 1 == n];
    return 0;
}