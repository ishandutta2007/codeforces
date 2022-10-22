// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, lst[200005];
bool a[200005];
std::vector<int> endpos;
std::vector<std::array<std::array<int, 2>, 2>> pre;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        static char c;
        std::cin >> c;
        a[i] = (c == '1') ^ (i & 1);
    }
    pre.push_back({0, 0});
    for (int i = 1; i <= n; ++i)
        if (a[i] != a[i + 1] || i == n)
        {
            endpos.push_back(i);
            pre.push_back(pre.back());
            ++pre.back()[i & 1][endpos.size() & 1];
        }
    for (int i = 1; i <= q; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        int L = std::lower_bound(endpos.begin(), endpos.end(), l) - endpos.begin(),
            R = std::lower_bound(endpos.begin(), endpos.end(), r) - endpos.begin();
        int ans = std::min(pre[R][0][0] - pre[L][0][0], pre[R][0][1] - pre[L][0][1]) +
                  std::min(pre[R][1][0] - pre[L][1][0], pre[R][1][1] - pre[L][1][1]);
        std::cout << R - L + 1 - ans << std::endl;
    }
    return 0;
}