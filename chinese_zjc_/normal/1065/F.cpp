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
int n, k, fa[1000005], depth[1000005], low[1000005], canback[1000005], cantback[1000005];
vector<int> son[1000005];
void dfs1(int now)
{
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        depth[son[now][i]] = depth[now] + 1;
        dfs1(son[now][i]);
    }
}
void dfs2(int now)
{
    if (!son[now].size())
    {
        low[now] = now;
    }
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        dfs2(son[now][i]);
        if (depth[low[now]] > depth[low[son[now][i]]])
        {
            low[now] = low[son[now][i]];
        }
    }
}
void dfs3(int now)
{
    if (!son[now].size())
    {
        canback[now] = 1;
    }
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        dfs3(son[now][i]);
        if (depth[low[son[now][i]]] - depth[now] <= k)
        {
            canback[now] += canback[son[now][i]];
        }
    }
}
void dfs4(int now)
{
    cantback[now] = canback[now];
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        dfs4(son[now][i]);
        if (depth[low[son[now][i]]] - depth[now] <= k)
        {
            cantback[now] = max(cantback[now], canback[now] - canback[son[now][i]] + cantback[son[now][i]]);
        }
        else
        {
            cantback[now] = max(cantback[now], canback[now] + cantback[son[now][i]]);
        }
    }
}
signed main()
{
    depth[0] = INF;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 2; i <= n; ++i)
    {
        cin >> fa[i];
        son[fa[i]].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    dfs3(1);
    dfs4(1);
    cout << cantback[1] << endl;
    return 0;
}