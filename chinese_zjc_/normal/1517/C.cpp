//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, a[505], ans[505][505];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int x = i, y = i, l = a[i];
        while (l)
        {
            --l;
            ans[x][y] = a[i];
            if (!l)
                break;
            if (y > 1 && !ans[x][y - 1])
                --y;
            else if (x < n && !ans[x + 1][y])
                ++x;
            else
                return -1;
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            if (!ans[i][j])
                return std::cout << -1 << std::endl, 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            std::cout << ans[i][j] << " \n"[j == i];
    return 0;
}