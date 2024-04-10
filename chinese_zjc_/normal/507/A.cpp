// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, a[105];
std::vector<int> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    while (true)
    {
        int pos = std::min_element(a + 1, a + 1 + n) - a;
        if (a[pos] <= k)
            ans.push_back(pos), k -= a[pos], a[pos] = INT_MAX;
        else
            break;
    }
    std::cout << ans.size() << std::endl;
    for (auto i : ans)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}