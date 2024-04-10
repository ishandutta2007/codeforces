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
#include <random>
#include <chrono>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 10000019;
int n, m, k, val[200005], x[10][10], together, ans;
std::vector<std::pair<int, int>> to[200005];
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
void dfs(int now, int sum)
{
    if (now > k)
        return void(sum == together ? ++ans : 0);
    for (int i = 1; i <= now; ++i)
        dfs(now + 1, sum * x[now][i] % MOD);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        val[i] = Rand() % MOD;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y, z;
        std::cin >> x >> y >> z;
        to[x].push_back(std::make_pair(z, y));
    }
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= i; ++j)
            x[i][j] = 1;
    together = 1;
    for (int i = 1; i <= n; ++i)
        together = together * val[i] % MOD;
    for (int i = 1; i <= n; ++i)
    {
        std::sort(to[i].begin(), to[i].end());
        for (int j = 0; j != (int)to[i].size(); ++j)
            x[to[i].size()][j + 1] = (x[to[i].size()][j + 1] * val[to[i][j].second]) % MOD;
    }
    dfs(1, 1);
    std::cout << ans << std::endl;
    return 0;
}