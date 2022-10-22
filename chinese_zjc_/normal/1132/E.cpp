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
int n, c[10], sum[10], ans;
void dfs(int now, int wei)
{
    if (wei + sum[now] <= ans || wei > n)
        return;
    if (!now)
        return void(ans = wei);
    for (int i = std::min(c[now], (n - wei) / now), tim = 1; i >= 0ll && tim <= 10; --i, ++tim)
        dfs(now - 1, wei + i * now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= 8; ++i)
        std::cin >> c[i], sum[i] = sum[i - 1] + c[i] * i;
    dfs(8, 0);
    std::cout << ans << std::endl;
    return 0;
}