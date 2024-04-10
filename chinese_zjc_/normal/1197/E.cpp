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
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, biggest, ans, mindis = INF;
struct node
{
    int dis, way;
    vector<int> to;
};
map<int, node> b;
struct segment
{
    int l, r;
} a[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].r >> a[i].l;
        b[a[i].l].to.push_back(a[i].r);
        b[a[i].l].dis = b[a[i].r].dis = INF;
        biggest = max(biggest, a[i].l);
    }
    b[0].way = 1;
    for (auto now = b.begin(); now != b.end(); ++now)
    {
        for (auto i : now->second.to)
        {
            if (b[i].dis > now->second.dis)
            {
                b[i].dis = now->second.dis;
                b[i].way = 0;
            }
            if (b[i].dis == now->second.dis)
            {
                b[i].way += now->second.way;
            }
        }
        auto nxt = now;
        ++nxt;
        if (nxt != b.end())
        {
            if (nxt->second.dis > nxt->first - now->first + now->second.dis)
            {
                nxt->second.dis = nxt->first - now->first + now->second.dis;
                nxt->second.way = 0;
            }
            if (nxt->second.dis == nxt->first - now->first + now->second.dis)
            {
                (nxt->second.way += now->second.way) %= MOD;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].r <= biggest)
        {
            continue;
        }
        if (mindis > b[a[i].r].dis)
        {
            mindis = b[a[i].r].dis;
            ans = 0;
        }
        if (mindis == b[a[i].r].dis)
        {
            ans = (ans + b[a[i].r].way) % MOD;
            b[a[i].r].way = 0;
        }
    }
    cout << ans << endl;
    return 0;
}