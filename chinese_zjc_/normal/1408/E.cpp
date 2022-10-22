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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[200005], b[200005], A[200005], fa[400005], v, cnt, ans;
struct edge
{
    int f, t, v;
} e[400005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
bool cmp(const edge &A, const edge &B)
{
    return A.v > B.v;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
        for (int j = 1; j <= A[i]; ++j)
        {
            cin >> v;
            e[++cnt] = {i, n + v, a[i] + b[v]};
            ans += a[i] + b[v];
        }
    }
    sort(e + 1, e + 1 + cnt, cmp);
    for (int i = 1; i <= n + m; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= cnt; ++i)
    {
        if (find(e[i].f) != find(e[i].t))
        {
            ans -= e[i].v;
            fa[find(e[i].f)] = find(e[i].t);
        }
    }
    cout << ans << endl;
    return 0;
}