// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int query(std::vector<int> x)
{
    std::cout << '?';
    for (auto i : x)
        std::cout << ' ' << i;
    std::cout << std::endl;
    int t;
    std::cin >> t;
    return t;
}
void answer(std::vector<int> x)
{
    std::cout << '!';
    for (auto i : x)
        std::cout << ' ' << i;
    std::cout << std::endl;
    exit(0);
}
int ans[105], n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = -n + 1; i <= -1; ++i)
    {
        std::vector<int> tmp(n, 1);
        tmp[n - 1] = 1 - i;
        ans[query(tmp)] = -i;
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        std::vector<int> tmp(n, n);
        tmp[n - 1] = n - i;
        ans[query(tmp)] = -i;
    }
    int add = *std::min_element(ans + 1, ans + 1 + n);
    for (int i = 1; i <= n; ++i)
        ans[i] += 1 - add;
    answer(std::vector<int>(ans + 1, ans + 1 + n));
    return 0;
}