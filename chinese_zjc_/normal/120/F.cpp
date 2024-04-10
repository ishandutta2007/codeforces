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
int n, m[105], a, b, d[105], ans, dis[105], now;
vector<int> to[105][105];
queue<int> que;
signed main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> m[i];
        for (int j = 1; j < m[i]; ++j)
        {
            cin >> a >> b;
            to[i][a].push_back(b);
            to[i][b].push_back(a);
        }
        fill(dis + 1, dis + 1 + m[i], -1);
        dis[1] = 0;
        que.push(1);
        while (!que.empty())
        {
            now = que.front();
            que.pop();
            for (int j = 0; j < (int)to[i][now].size(); ++j)
            {
                if (!~dis[to[i][now][j]])
                {
                    dis[to[i][now][j]] = dis[now] + 1;
                    que.push(to[i][now][j]);
                }
            }
        }
        fill(dis + 1, dis + 1 + m[i], -1);
        dis[now] = 0;
        que.push(now);
        while (!que.empty())
        {
            now = que.front();
            que.pop();
            for (int j = 0; j < (int)to[i][now].size(); ++j)
            {
                if (!~dis[to[i][now][j]])
                {
                    dis[to[i][now][j]] = dis[now] + 1;
                    que.push(to[i][now][j]);
                }
            }
        }
        d[i] = dis[now];
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += d[i];
    }
    cout << ans << endl;
    return 0;
}