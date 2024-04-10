// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, cnt, v[1005][1005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i < n; i *= k)
    {
        ++cnt;
        for (int j = 0; j < n; j += i)
            for (int l = 0; l < n; l += i)
                if (j != l)
                    for (int o = 0; o < i && j + o < n; ++o)
                        for (int p = 0; p < i && l + p < n; ++p)
                            v[j + o][l + p] = cnt;
    }
    std::cout << cnt << std::endl;
    for (int i = 0; i != n; ++i)
        for (int j = i + 1; j != n; ++j)
            std::cout << v[i][j] << ' ';
    std::cout << std::endl;
    return 0;
}