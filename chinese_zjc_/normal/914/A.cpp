// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int sqr(int x) { return x * x; }
bool is(int x) { return sqr(std::sqrt(x)) != x; }
int n, a[1005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::sort(a + 1, a + 1 + n, std::greater<int>());
    std::cout << *std::find_if(a + 1, a + 1 + n, is) << std::endl;
    return 0;
}