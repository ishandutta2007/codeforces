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
int n, a[100005], fa[100005], depth[100005], res, maxdepth, cnt, ans;
std::vector<int> son[100005];
std::map<int, int> app;
void init(int now)
{
    for (auto i : son[now])
    {
        maxdepth = std::max(maxdepth, depth[i] = depth[now] + 1);
        init(i);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 2; i <= n; ++i)
    {
        std::cin >> fa[i];
        son[fa[i]].push_back(i);
    }
    init(1);
    for (int i = 1; i <= n; ++i)
        if ((depth[i] & 1) == (maxdepth & 1))
            res ^= a[i], ++cnt;
        else
            ++app[a[i]];
    if (res == 0)
        ans += cnt * (cnt - 1) / 2 + (n - cnt) * (n - cnt - 1) / 2;
    // std::cout << res << std::endl;
    for (int i = 1; i <= n; ++i)
        if ((depth[i] & 1) == (maxdepth & 1))
            ans += app[res ^ a[i]];
    std::cout << ans << std::endl;
    return 0;
}