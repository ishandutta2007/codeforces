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
int n, m, dis[100005], a[100005], b[100005], w[100005], p[32], ans;
std::vector<std::pair<int, int>> to[100005];
void insert(int x)
{
    for (int i = 30; i >= 0; --i)
        if (x >> i & 1)
        {
            if (!p[i])
            {
                for (int j = i + 1; j <= 30; ++j)
                    if (p[j] >> i & 1)
                        p[j] ^= x;
                for (int j = i - 1; j >= 0; --j)
                    if (x >> j & 1)
                        x ^= p[j];
                p[i] = x;
                return;
            }
            else
                x ^= p[i];
        }
}
void dfs(int now)
{
    for (auto i : to[now])
        if (!~dis[i.first])
        {
            dis[i.first] = dis[now] ^ i.second;
            dfs(i.first);
        }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 2; i <= n; ++i)
        dis[i] = -1;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i] >> w[i];
        to[a[i]].push_back(std::make_pair(b[i], w[i]));
        to[b[i]].push_back(std::make_pair(a[i], w[i]));
    }
    dfs(1);
    for (int i = 1; i <= m; ++i)
        insert(w[i] ^ dis[a[i]] ^ dis[b[i]]);
    ans = dis[n];
    for (int i = 30; i >= 0; --i)
        if (ans >> i & 1)
            ans ^= p[i];
    std::cout << ans << std::endl;
    return 0;
}