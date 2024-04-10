//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int fa[2][200005], n, a, b, c, siz[2][200005], ans;
int find(int type, int now)
{
    return fa[type][now] == now ? now : fa[type][now] = find(type, fa[type][now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fa[0][i] = fa[1][i] = i;
    }
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b >> c;
        fa[c][find(c, a)] = find(c, b);
    }
    for (int i = 1; i <= n; ++i)
    {
        ++siz[0][find(0, i)];
        ++siz[1][find(1, i)];
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += siz[0][find(0, i)] * siz[1][find(1, i)];
    }
    cout << ans - n << endl;
    return 0;
}