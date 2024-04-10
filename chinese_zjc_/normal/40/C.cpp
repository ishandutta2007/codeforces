//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int ans = 1, n, m, d, dx, dy;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> dx >> m >> dy;
    d = llabs(dx - dy);
    for (int i = 1; i <= n; ++i)
        if (i + d > m)
            ++ans;
    for (int i = 1; i <= m; ++i)
        if (i + d > n)
            ++ans;
    for (int i = 1; i <= n; ++i)
    {
        int b;
        if (d >= i)
        {
            b = std::min(std::min(m, i * 2), std::max(0ll, i - (d - m)));
            if (b >= 1)
                ans -= 1;
            if (b >= i * 2)
                ans -= 1;
            ans += b * 2;
        }
        else
        {
            int lst = i - d - 1;
            b = std::max(std::min(m - lst, i + d - lst), 0ll);
            if (b >= 1)
                ans -= 1;
            if (b >= i + d - lst)
                ans -= 1;
            ans += b * 2;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}