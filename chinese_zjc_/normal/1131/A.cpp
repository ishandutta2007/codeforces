// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int h1, h2, w1, w2;
long long ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> h1 >> w1 >> h2 >> w2;
    std::cout << std::max(h1, h2) * 2 + (w1 + w2) * 2 + 4 << std::endl;
    return 0;
}