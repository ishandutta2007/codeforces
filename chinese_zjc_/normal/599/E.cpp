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
#define in(a, b) ((b) & (1 << (a)))
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, k, a, b, c, dp[13][1 << 13];
struct lca
{
    int a, b, c;
} q[105];
struct edge
{
    int a, b;
} e[105];
int dfs(int root, int now)
{
    if (~dp[root][now])
    {
        return dp[root][now];
    }
    if (1 << root == now)
    {
        return dp[root][now] = 1;
    }
    int f = -1;
    for (int i = 0; i < n; ++i)
    {
        if (in(i, now ^ (1 << root)))
        {
            f = i;
            break;
        }
    }
    if (!~f)
    {
        return dp[root][now] = 0;
    }
    dp[root][now] = 0;
    for (int i = now; i; i = (i - 1) & now)
    {
        if (in(root, i))
        {
            continue;
        }
        if (!in(f, i))
        {
            continue;
        }
        bool flag = false;
        for (int j = 1; j <= k && !flag; ++j)
        {
            if (in(q[j].c, i))
            {
                if (!(in(q[j].a, i) && in(q[j].b, i)))
                {
                    flag = true;
                }
            }
            if (in(q[j].a, i) && in(q[j].b, i))
            {
                if (!in(q[j].c, i))
                {
                    flag = true;
                }
            }
        }
        int cnt = -1;
        for (int j = 1; j <= m && !flag; ++j)
        {
            if (e[j].a == root)
            {
                if (in(e[j].b, i))
                {
                    if (~cnt)
                    {
                        flag = true;
                    }
                    else
                    {
                        cnt = e[j].b;
                    }
                }
            }
            else if (e[j].b == root)
            {
                if (in(e[j].a, i))
                {
                    if (~cnt)
                    {
                        flag = true;
                    }
                    else
                    {
                        cnt = e[j].a;
                    }
                }
            }
            else if ((in(e[j].a, i) != 0) ^ (in(e[j].b, i) != 0))
            {
                flag = true;
            }
        }
        if (flag)
        {
            continue;
        }
        else if (~cnt)
        {
            dp[root][now] += dfs(cnt, i) * dfs(root, now ^ i);
        }
        else
        {
            for (int j = 0; j < n; ++j)
            {
                if (in(j, i))
                {
                    dp[root][now] += dfs(j, i) * dfs(root, now ^ i);
                }
            }
        }
    }
    // cout << root << ' ' << bitset<6>(now) << ' ' << dp[root][now] << endl;
    return dp[root][now];
}
signed main()
{
    // freopen("data.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        cin >> e[i].a >> e[i].b;
        --e[i].a;
        --e[i].b;
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> q[i].a >> q[i].b >> q[i].c;
        --q[i].a;
        --q[i].b;
        --q[i].c;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, (1 << n) - 1) << endl;
    return 0;
}