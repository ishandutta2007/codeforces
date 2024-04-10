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
int LB[100005], RB[100005], LA[100005], RA[100005], n, p[100005], ans, LBMAX[100005], RBMAX[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> p[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        LB[i] = LA[i] = 1;
        if (i > 1 && p[i - 1] > p[i])
        {
            LB[i] = LB[i - 1] + 1;
        }
        if (i > 1 && p[i - 1] < p[i])
        {
            LA[i] = LA[i - 1] + 1;
        }
    }
    for (int i = n; i >= 1; --i)
    {
        RB[i] = RA[i] = 1;
        if (i < n && p[i + 1] > p[i])
        {
            RB[i] = RB[i + 1] + 1;
        }
        if (i < n && p[i + 1] < p[i])
        {
            RA[i] = RA[i + 1] + 1;
        }
    }
    int Max = std::max(*std::max_element(LB + 1, LB + 1 + n), *std::max_element(RB + 1, RB + 1 + n));
    int way = std::count(LB + 1, LB + 1 + n, Max) + std::count(RB + 1, RB + 1 + n, Max);
    for (int i = 1; i <= n; ++i)
    {
        LBMAX[i] = std::max(LBMAX[i - 1], std::max(LB[i], LA[i]));
    }
    for (int i = n; i >= 1; --i)
    {
        RBMAX[i] = std::max(RBMAX[i + 1], std::max(RB[i], RA[i]));
    }
    for (int i = 1; i <= n; ++i)
    {
        if (LA[i] != RA[i])
            continue;
        if (LA[i] <= std::max(LBMAX[i - 1], RBMAX[i + 1]))
            continue;
        if (LA[i] <= std::max(LB[i + 1], RB[i + 1]))
            continue;
        if (RA[i] <= std::max(LB[i - 1], RB[i - 1]))
            continue;
        if (LA[i] % 2 == 0)
            continue;
        ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}