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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int a[200005], sum[200005], n, q, x, y;
int lowbit(int now)
{
    return now & -now;
}
void add(int pos, int v)
{
    while (pos <= n)
    {
        sum[pos] += v;
        pos += lowbit(pos);
    }
}
int query(int now)
{
    int res = 0;
    while (now)
    {
        res += sum[now];
        now ^= lowbit(now);
    }
    return res;
}
int findnext(int now)
{
    int l = now + 1, r = n + 1, v = query(now);
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (query(mid) < v << 1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        add(i, a[i]);
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> x >> y;
        add(x, -a[x]);
        a[x] = y;
        add(x, a[x]);
        int now = 1;
        bool flag = false;
        if (a[1] == 0)
        {
            cout << 1 << endl;
            continue;
        }
        while (now <= n)
        {
            now = findnext(now);
            if (now <= n && query(now) == a[now] << 1)
            {
                cout << now << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}