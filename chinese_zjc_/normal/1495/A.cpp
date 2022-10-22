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
std::vector<int> p, m;
int T, n;
double ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        p.clear();
        m.clear();
        ans = 0;
        for (int i = 1; i <= 2 * n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            if (x == 0)
            {
                p.push_back(llabs(y));
            }
            if (y == 0)
            {
                m.push_back(llabs(x));
            }
        }
        std::sort(p.begin(), p.end());
        std::sort(m.begin(), m.end());
        for (int i = 0; i < n; ++i)
        {
            ans += sqrt(p[i] * p[i] + m[i] * m[i]);
        }
        std::cout << std::fixed << std::setprecision(18) << ans << std::endl;
    }
    return 0;
}