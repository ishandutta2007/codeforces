// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, cnt;
std::vector<std::pair<int, int>> to;
bool check(int now)
{
    for (int i = 2; i * i <= now; ++i)
        if (now % i == 0)
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        to.push_back({i, (i + 1) % n});
    while (!check(to.size()))
    {
        to.push_back({cnt, cnt + 2});
        ++cnt;
        if (cnt % 4 == 2)
            cnt += 2;
    }
    std::cout << to.size() << std::endl;
    for (auto i : to)
        std::cout << i.first + 1 << ' ' << i.second + 1 << std::endl;
    return 0;
}