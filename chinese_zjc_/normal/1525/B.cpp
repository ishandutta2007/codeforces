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
int n, T, a[100005];
bool check()
{
    for (int i = 1; i <= n; ++i)
        if (a[i] != i)
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        if (check())
        {
            std::cout << 0 << std::endl;
            continue;
        }
        if (a[1] == 1 || a[n] == n)
        {
            std::cout << 1 << std::endl;
            continue;
        }
        if (a[1] == n && a[n] == 1)
        {
            std::cout << 3 << std::endl;
            continue;
        }
        std::cout << 2 << std::endl;
        continue;
    }
    return 0;
}