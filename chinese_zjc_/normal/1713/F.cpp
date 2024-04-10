// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[1 << 19];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    for (int i = 1; i != 1 << 19; i <<= 1)
        for (int j = 0; j != n; ++j)
            if (j & i)
                a[j] ^= a[j ^ i];
    for (int i = 1; i != 1 << 19; i <<= 1)
        for (int j = 0; j != n; ++j)
            if (j & i)
                a[j ^ i] ^= a[j];
    for (int i = n; i--;)
        std::cout << a[i] << " \n"[i == 0];
    return 0;
}