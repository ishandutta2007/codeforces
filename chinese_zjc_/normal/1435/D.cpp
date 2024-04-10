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
struct query
{
    char type;
    int name;
} q[200005];
struct L
{
    int l, r, appear;
} limit[100005];
int n, has, tim, kill[100005], up[100005], ans[100005], fa[100005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n << 1; ++i)
    {
        cin >> q[i].type;
        if (q[i].type == '-')
        {
            cin >> q[i].name;
        }
    }
    for (int i = 1; i <= n << 1; ++i)
    {
        if (q[i].type == '+')
        {
            ++has;
            ++tim;
            up[tim] = i;
        }
        if (q[i].type == '-')
        {
            --has;
            if (has < 0)
            {
                cout << "NO" << endl;
                return 0;
            }
            kill[tim - has] = q[i].name;
            limit[q[i].name].r = tim;
            limit[q[i].name].appear = i;
        }
    }
    up[n + 1] = INF;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int t = lower_bound(up + 1, up + 1 + n, limit[i].appear) - 1 - up;
        t = find(t);
        if (t == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
        ans[t] = i;
        --fa[t];
    }
    priority_queue<int, vector<int>, greater<int>> que;
    tim = 0;
    for (int i = 1; i <= n << 1; ++i)
    {
        if (q[i].type == '+')
        {
            que.push(ans[++tim]);
        }
        else
        {
            if (que.top() != q[i].name)
            {
                cout << "NO" << endl;
                return 0;
            }
            que.pop();
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}