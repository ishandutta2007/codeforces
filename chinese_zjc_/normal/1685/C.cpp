// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, pre[200005], l, r;
char c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n << 1; ++i)
            std::cin >> c, pre[i + 1] = pre[i] + (c == '(' ? +1 : -1);
        if (*std::min_element(pre, pre + 1 + n + n) >= 0)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        for (int i = 0; i <= n << 1; ++i)
            if (pre[i] < 0)
            {
                l = i;
                break;
            }
        for (int i = 0; i <= n << 1; ++i)
            if (pre[i] < 0)
                r = i;
        l = std::max_element(pre, pre + l) - pre;
        r = std::max_element(pre + r, pre + 1 + n + n) - pre;
        bool flag = true;
        for (int i = l; i != r; ++i)
            flag &= pre[l] + pre[r] - pre[i] >= 0;
        if (flag)
        {
            std::cout << 1 << std::endl
                      << l + 1 << ' ' << r << std::endl;
        }
        else
        {
            int pos = std::max_element(pre, pre + 1 + n + n) - pre;
            std::cout << 2 << std::endl
                      << 1 << ' ' << pos << std::endl
                      << pos + 1 << ' ' << (n << 1) << std::endl;
        }
    }
    return 0;
}