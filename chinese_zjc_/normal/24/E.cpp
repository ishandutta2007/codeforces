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
const double eps = 1e-10;
const int INF = 0x3fffffffffffffff;
std::pair<int, int> p[500005];
int n;
double ans = INF;
bool check(int l, int r, double t)
{
    double L = +INF, R = -INF;
    for (int i = l; i <= r; ++i)
        if (p[i].second < 0)
            L = std::min(L, p[i].first + p[i].second * t);
        else
            R = std::max(R, p[i].first + p[i].second * t);
    return L <= R;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i].first >> p[i].second;
    for (int i = 1; i <= n; ++i)
    {
        int j = i;
        while (p[j].second > 0)
            ++j;
        while (p[j].second < 0)
            ++j;
        --j;
        double l = 0, r = p[j].first - p[i].first;
        while (l + eps < r)
        {
            double mid = (l + r) / 2;
            if (check(i, j, mid))
                r = mid;
            else
                l = mid;
        }
        if (check(i, j, r))
            ans = std::min(ans, r);
        i = j;
    }
    std::cout << std::fixed << std::setprecision(10) << (ans >= INF ? -1 : ans) << std::endl;
    return 0;
}