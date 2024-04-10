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
int n, a[505][505], fa[1005], ans[1005], cnt;
std::vector<int> son[1005];
void init()
{
    static int rk[505];
    for (int i = 1; i <= n; ++i)
        rk[i] = i;
    std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
              { return a[1][A] < a[1][B]; });
    for (int i = 2, lst = 1; i <= n; ++i)
    {
        ans[lst = fa[lst] = ++cnt] = a[1][rk[i]];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    cnt = n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        ans[i] = a[i][i];
    // init();
    for (int i = 1; i <= n; ++i)
    {
        static int rk[505];
        for (int j = 1; j <= n; ++j)
            rk[j] = j;
        std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
                  { return a[i][A] < a[i][B]; });
        for (int j = 2, lst = i; j <= n; ++j)
        {
            if (rk[j] < i)
            {
                int k = rk[j];
                while (a[i][rk[j]] > ans[k])
                    k = fa[k];
                fa[lst] = k;
                break;
            }
            if (a[i][rk[j]] == a[i][rk[j + 1]])
                continue;
            ans[lst = fa[lst] = ++cnt] = a[i][rk[j]];
        }
    }
    std::cout << cnt << std::endl;
    for (int i = 1; i <= cnt; ++i)
        std::cout << ans[i] << " \n"[i == cnt];
    std::cout << std::find(fa + 1, fa + 1 + cnt, 0) - fa << std::endl;
    for (int i = 1; i <= cnt; ++i)
        if (fa[i])
            std::cout << i << ' ' << fa[i] << std::endl;
    return 0;
}