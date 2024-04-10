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
int n, x, y, cnt, tmp, id, lst[300005], q, sum[300005], ans[100005];
struct frac
{
    int a, b;
    frac(int A, int B)
    {
        int gcd = llabs(__gcd(A, B));
        a = A / gcd;
        b = B / gcd;
    }
    bool operator<(const frac &__Val) const
    {
        return a == __Val.a ? b < __Val.b : a < __Val.a;
    }
};
struct point
{
    int x, y;
};
struct L
{
    int l, r;
    vector<point> p;
} p[100005];
frac get(point A, point B)
{
    return {A.y - B.y, A.x - B.x};
}
map<frac, int> appear;
struct query
{
    int l, r, p;
    bool operator<(const query &__Val) const
    {
        return r == __Val.r ? l < __Val.l : r < __Val.r;
    }
} b[100005];
int lowbit(int now)
{
    return now & -now;
}
void add(int pos, int val)
{
    if (!pos)
    {
        return;
    }
    while (pos <= cnt)
    {
        sum[pos] += val;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        for (int j = 0; j < tmp; ++j)
        {
            cin >> x >> y;
            p[i].p.push_back({x, y});
        }
        p[i].l = cnt + 1;
        p[i].r = (cnt += tmp);
        for (int j = 0; j < tmp; ++j)
        {
            frac nxt = {p[i].p[j].x - p[i].p[(j + 1) % tmp].x, p[i].p[j].y - p[i].p[(j + 1) % tmp].y};
            lst[p[i].l + j] = appear[nxt];
            appear[nxt] = p[i].l + j;
        }
    }
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> b[i].l >> b[i].r;
        b[i].l = p[b[i].l].l;
        b[i].r = p[b[i].r].r;
        b[i].p = i;
    }
    sort(b + 1, b + 1 + q);
    for (int i = 1, tmp = 0; i <= q; ++i)
    {
        while (tmp <= b[i].r)
        {
            add(tmp, 1);
            add(lst[tmp], -1);
            ++tmp;
        }
        ans[b[i].p] = query(b[i].r) - query(b[i].l - 1);
    }
    for (int i = 1; i <= q; ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}