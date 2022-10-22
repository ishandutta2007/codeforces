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
double dis[1005][1005], l, r, dp[1005];
int x[1005], b[1005], from[1005], n, len;
void work(double now)
{
    std::fill(dp + 1, dp + 1 + n, INF);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (dp[i] > dp[j] + dis[j][i])
                dp[i] = dp[j] + dis[j][i], from[i] = j;
        dp[i] -= now * b[i];
    }
}
void print(int now)
{
    if (from[now])
        print(from[now]);
    std::cout << now << " \n"[now == n];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> len;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> x[i] >> b[i];
        for (int j = 0; j < i; ++j)
            dis[j][i] = sqrt(llabs(x[i] - x[j] - len));
    }
    l = 0, r = 1e9;
    while (l + eps < r)
    {
        double mid = (l + r) / 2;
        // std::cout << std::fixed << std::setprecision(50) << l << ' ' << r << std::endl;
        work(mid);
        if (dp[n] <= 0)
            r = mid;
        else
            l = mid;
    }
    print(n);
    return 0;
}