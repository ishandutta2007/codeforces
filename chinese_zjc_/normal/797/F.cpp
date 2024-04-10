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
#include <cctype>
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
int n, m, sum[5005], x[5005], dp[2][5005];
int l, r;
bool now = true, lst = false;
struct hole
{
    int x, v;
    bool operator<(const hole &__Val) const
    {
        return x < __Val.x;
    }
} h[5005];
struct queues
{
    int v, p;
} que[5005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }
    sort(x + 1, x + 1 + n);
    for (int i = 1; i <= m; ++i)
    {
        cin >> h[i].x >> h[i].v;
    }
    sort(h + 1, h + 1 + m);
    fill(dp[lst] + 1, dp[lst] + 1 + n, INF);
    for (int i = 1; i <= m; ++i, swap(now, lst))
    {
        for (int j = 1; j <= n; ++j)
        {
            sum[j] = sum[j - 1] + llabs(x[j] - h[i].x);
        }
        que[l = r = 1] = {dp[lst][0], 0};
        for (int j = 1; j <= n; ++j)
        {
            // dp[now][j] = INF;
            // for (int k = max(0ll, j - h[i].v); k <= j; ++k)
            // {
            //     dp[now][j] = min(dp[now][j], dp[lst][k] + sum[j] - sum[k]);
            // }
            if (que[l].p < j - h[i].v)
            {
                ++l;
            }
            queues nxt = {dp[lst][j] - sum[j], j};
            while (l <= r && que[r].v >= nxt.v)
            {
                --r;
            }
            que[++r] = nxt;
            dp[now][j] = que[l].v + sum[j];
        }
    }
    cout << (dp[lst][n] == INF ? -1 : dp[lst][n]) << endl;
    return 0;
}