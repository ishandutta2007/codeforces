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
int n, f[100005];
bool s[100005], h[100005];
int go(int now)
{
    h[now] = true;
    return h[f[now]] ? now : go(f[now]);
}
std::vector<std::pair<int, int>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> f[i], s[f[i]] = true;
    for (int i = 1; i <= n; ++i)
        if (!s[i])
            que.push_back({i, go(i)});
    for (int i = 1; i <= n; ++i)
        if (!h[i])
            que.push_back({i, go(i)});
    if (std::count(s + 1, s + 1 + n, true) == n && que.size() == 1)
        return std::cout << 0 << std::endl, 0;
    std::cout << que.size() << std::endl;
    for (int i = 0; i != (int)que.size(); ++i)
        std::cout << que[i].second << ' ' << que[(i + 1) % que.size()].first << std::endl;
    return 0;
}