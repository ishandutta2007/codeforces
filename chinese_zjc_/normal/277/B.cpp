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
int n, m, y, cnt;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    if (m == 3 && n > 4)
        return std::cout << -1 << std::endl, 0;
    for (int i = 0; i != m; ++i)
        std::cout << i << ' ' << (y = y + cnt++) << std::endl;
    if (m < n)
        std::cout << 10000 << ' ' << y << std::endl;
    for (int i = 1; i < n - m; ++i)
        std::cout << 10000 + i << ' ' << (y = y - --cnt) << std::endl;
    return 0;
}