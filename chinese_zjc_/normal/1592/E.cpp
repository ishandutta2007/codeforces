// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[1 << 20], ans, fst[1 << 20];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 0; i != 20; ++i)
    {
        memset(fst, -1, sizeof(fst));
        fst[0] = 0;
        for (int j = 1, k = 0, st = 0; j <= n; ++j)
            if (a[j] >> i & 1)
            {
                k ^= a[j] >> i;
                if (fst[k] < st)
                    fst[k] = j;
                else
                    ans = std::max(ans, j - fst[k]);
            }
            else
                st = fst[k = 0] = j;
    }
    std::cout << ans << std::endl;
    return 0;
}