// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::set<std::pair<int, int>> good;
int q, step, n, m;
std::vector<std::pair<int, int>> que;
void merge(const std::vector<std::pair<int, int>> &A, const std::vector<std::pair<int, int>> &B,
           std::vector<std::pair<int, int>> &C)
{
    C.clear();
    std::vector<std::pair<int, int>>::const_iterator a = A.begin(), b = B.begin();
    while (a != A.end() && b != B.end())
    {
        if (a->first < b->first)
        {
            while (!C.empty() && C.back().second <= a->second)
                C.pop_back();
            if (C.empty() || C.back() < *a)
                C.push_back(*a++);
            else
                ++a;
        }
        else
        {
            while (!C.empty() && C.back().second <= b->second)
                C.pop_back();
            if (C.empty() || C.back() < *b)
                C.push_back(*b++);
            else
                ++b;
        }
    }
    while (a != A.end())
    {
        while (!C.empty() && C.back().second <= a->second)
            C.pop_back();
        if (C.empty() || C.back() < *a)
            C.push_back(*a++);
        else
            ++a;
    }
    while (b != B.end())
    {
        while (!C.empty() && C.back().second <= b->second)
            C.pop_back();
        if (C.empty() || C.back() < *b)
            C.push_back(*b++);
        else
            ++b;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (int i = 1, a, b; i <= q; ++i)
        std::cin >> a >> b, good.insert({a, b});
    que.push_back({1, 1});
    while (!que.empty())
    {
        std::vector<std::pair<int, int>> g[2];
        if (que.front() == std::make_pair(n, m))
            return std::cout << step << std::endl, 0;
        for (auto i : que)
        {
            int v = i.first + i.second + good.count(i);
            g[0].push_back({std::min(v, n), i.second});
            g[1].push_back({i.first, std::min(v, m)});
        }
        merge(g[0], g[1], que);
        ++step;
    }
    return 0;
}