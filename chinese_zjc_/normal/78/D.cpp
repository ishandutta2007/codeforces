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
const double sqrt3 = sqrt(3);
int n, ans;
double dis(double x, double y) { return sqrt(x * x + y * y); }
double get1(int x, int y) { return std::max(dis((x + 0.5) * sqrt3, y * 3 + 0.5),
                                            dis((x + 0.0) * sqrt3, y * 3 + 1.0)); }
double get2(int x, int y) { return std::max(dis((x - 0.0) * sqrt3, y * 3 - 1.0),
                                            dis((x - 0.5) * sqrt3, y * 3 - 0.5)); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = n, j = 0; i >= 0; --i)
    {
        j = std::max(0ll, j);
        while (get1(i, j) <= n)
            ++j;
        while (j >= 0 && get1(i, j) > n)
            --j;
        if (j >= 0)
            ans += (j * 2 + 1) * (i ? 2 : 1);
    }
    for (int i = n, j = 0; i >= 1; --i)
    {
        j = std::max(0ll, j);
        while (get2(i, j) <= n)
            ++j;
        while (j >= 0 && get2(i, j) > n)
            --j;
        if (j >= 0)
            ans += j * 4;
    }
    std::cout << ans << std::endl;
    return 0;
}