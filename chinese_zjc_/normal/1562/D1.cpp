// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, q, s[300005];
char c[300005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> c[i];
            s[i] = s[i - 1] + ((c[i] >> 1 ^ i) & 1 ? +1 : -1);
        }
        for (int i = 1, l, r; i <= q; ++i)
        {
            std::cin >> l >> r;
            if (s[r] - s[l - 1])
                if ((l ^ r) & 1)
                    std::cout << 2 << '\n';
                else
                    std::cout << 1 << '\n';
            else
                std::cout << 0 << '\n';
        }
    }
    return 0;
}