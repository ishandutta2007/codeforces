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
int n, a[200005];
bool can[5000005];
std::pair<int, int> c[5000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int sum = a[i] + a[j];
            if (can[sum])
            {
                if (c[sum].first != i && c[sum].first != j && c[sum].second != i && c[sum].second != j)
                {
                    std::cout << "YES" << std::endl
                              << c[sum].first << ' ' << c[sum].second << ' ' << i << ' ' << j << std::endl;
                    return 0;
                }
            }
            else
            {
                c[sum] = {i, j};
                can[sum] = true;
            }
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}