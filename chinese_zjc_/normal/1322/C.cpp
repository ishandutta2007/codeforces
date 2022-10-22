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
int T, n, m, v[500005];
std::map<std::set<int>, int> sum;
std::set<int> from[500005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        sum.clear();
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            from[i].clear();
        }
        if (n == 1 && m == 1)
        {
            std::cout << v[1] << std::endl;
            for (int i = 1; i <= m; ++i)
                std::cin >> v[1] >> v[1];
            continue;
        }
        for (int i = 1; i <= m; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            from[y].insert(x);
        }
        for (int i = 1; i <= n; ++i)
            if (!from[i].empty())
                sum[from[i]] += v[i];
        int ans = 0;
        for (auto i : sum)
            ans = std::__gcd(i.second, ans);
        std::cout << ans << std::endl;
    }
    return 0;
}