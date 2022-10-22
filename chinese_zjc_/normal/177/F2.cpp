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
int n, k, t, d[20][20], cnt, lim;
void dfs(int now, int cho, int val)
{
    if (cnt >= t)
        return;
    if (now == n)
        return void(++cnt);
    for (int i = 0; i != n; ++i)
        if ((~cho & 1 << i) && d[now][i] && val + d[now][i] <= lim)
            dfs(now + 1, cho | 1 << i, val + d[now][i]);
    dfs(now + 1, cho, val);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> t;
    for (int i = 0; i != k; ++i)
    {
        static int a, b, c;
        std::cin >> a >> b >> c;
        d[--a][--b] = c;
    }
    int l = 0, r = 20000;
    while (l < r)
    {
        lim = (l + r) >> 1;
        cnt = 0;
        dfs(0, 0, 0);
        if (cnt >= t)
            r = lim;
        else
            l = lim + 1;
    }
    std::cout << l << std::endl;
    return 0;
}