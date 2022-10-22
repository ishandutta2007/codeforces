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
int n, m, ans, mu[500005], sum[500005], a[200005], max;
bool vis[500005];
std::vector<int> p;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    max = *std::max_element(a + 1, a + 1 + n);
    mu[1] = 1;
    for (int i = 2; i <= max; ++i)
    {
        if (!vis[i])
        {
            p.push_back(i);
            mu[i] = -mu[1];
        }
        for (auto j : p)
        {
            if (i * j > max)
                break;
            if (i % j == 0)
            {
                vis[i * j] = true;
                mu[i * j] = 0;
                break;
            }
            vis[i * j] = true;
            mu[i * j] = -mu[i];
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= m; ++i)
    {
        static int x;
        std::cin >> x;
        for (int j = 1; j * j <= a[x]; ++j)
        {
            if (a[x] % j == 0)
            {
                if (vis[x])
                {
                    --sum[j];
                    ans -= sum[j] * mu[j];
                }
                else
                {
                    ans += sum[j] * mu[j];
                    ++sum[j];
                }
                if (j * j != a[x])
                {
                    if (vis[x])
                    {
                        --sum[a[x] / j];
                        ans -= sum[a[x] / j] * mu[a[x] / j];
                    }
                    else
                    {
                        ans += sum[a[x] / j] * mu[a[x] / j];
                        ++sum[a[x] / j];
                    }
                }
            }
        }
        vis[x] ^= true;
        std::cout << ans << std::endl;
    }
    return 0;
}