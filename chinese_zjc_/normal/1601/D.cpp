// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<std::pair<int, int>> c;
int n, d, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> d;
    for (int i = 0, s, a; i != n; ++i)
    {
        std::cin >> s >> a;
        if (s < d)
            continue;
        c.emplace_back(s, a);
    }
    std::sort(c.begin(), c.end(), [&](const std::pair<int, int> &A, const std::pair<int, int> &B)
              {
                  int a = std::max(A.first, A.second), b = std::max(B.first, B.second);
                  return a == b ? A.first < B.first : a < b;
              });
    for (auto i : c)
        if (d <= i.first)
        {
            d = std::max(d, i.second);
            ++ans;
        }
    std::cout << ans << std::endl;
    return 0;
}