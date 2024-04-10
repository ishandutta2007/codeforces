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
std::set<int> g;
int n, k, a, m, x, res;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> a >> m;
    g.insert(0);
    g.insert(n + 1);
    res = (n + 1) / (a + 1);
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> x;
        int lst = *--g.upper_bound(x), nxt = *g.upper_bound(x);
        res -= (nxt - lst) / (a + 1);
        g.insert(x);
        res += (nxt - x) / (a + 1) + (x - lst) / (a + 1);
        if (res < k)
        {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}