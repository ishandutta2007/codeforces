// This code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
std::deque<int> a;
bool check(std::deque<int> x)
{
    while (x.size() > std::size_t(1) && x.front() == x.back())
        x.pop_front(), x.pop_back();
    return x.size() <= std::size_t(1);
}
std::deque<int> erase(const std::deque<int> &x, const int &v)
{
    std::deque<int> res;
    for (auto i : x)
        if (i != v)
            res.push_back(i);
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        a.assign(n, 0);
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        while (a.size() > std::size_t(1) && a.front() == a.back())
            a.pop_front(), a.pop_back();
        if (a.size() <= std::size_t(1) || check(erase(a, a.front())) || check(erase(a, a.back())))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}