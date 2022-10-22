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
int n, a[2005], b[2005], c[2005], tim, ans;
std::stringstream res;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    for (int i = 1; i <= n; ++i)
        c[std::find(a + 1, a + 1 + n, b[i]) - a] = i;
    for (int i = 1; i <= n; ++i)
    {
        int now = std::find(c + 1, c + 1 + n, i) - c;
        for (int j = now - 1; j >= i; --j)
            if (c[j] >= now)
            {
                res << now << ' ' << j << std::endl;
                ans += llabs(now - j);
                ++tim;
                std::swap(c[now], c[j]);
                now = j;
            }
    }
    std::cout << ans << std::endl
              << tim << std::endl
              << res.str();
    return 0;
}