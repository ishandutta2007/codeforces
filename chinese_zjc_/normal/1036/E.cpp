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
#define x first
#define y second
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
struct segment
{
    pair<int, int> p[2];
    int xst, yst, xdif, ydif, len;
} a[1005];
int n, ans, nmsl[1005];
map<pair<int, int>, int> g;
pair<int, int> solve(int a1, int b1, int c1, int a2, int b2, int c2)
{
    // cout << setw(5) << a1 << setw(5) << b1 << setw(5) << c1 << endl
    //      << setw(5) << a2 << setw(5) << b2 << setw(5) << c2 << endl;
    pair<int, int> res = {-1, -1};
    int b3 = b1 * a2 - b2 * a1, c3 = c1 * a2 - c2 * a1;
    if (!b3 || c3 % b3)
    {
        return res;
    }
    res.y = c3 / b3;
    if (!a1 || (c1 - b1 * res.y) % a1)
    {
        if (!a2 || (c2 - b2 * res.y) % a2)
        {
            return res;
        }
        res.x = (c2 - b2 * res.y) / a2;
    }
    else
    {
        res.x = (c1 - b1 * res.y) / a1;
    }
    // cout << res.x << ' ' << res.y << endl;
    return res;
}
pair<bool, pair<int, int>> get(const segment &A, const segment &B)
{
    pair<int, int> tmp = solve(A.xdif, -B.xdif, B.xst - A.xst,
                               A.ydif, -B.ydif, B.yst - A.yst);
    if (0 <= tmp.x && tmp.x <= A.len && 0 <= tmp.y && tmp.y <= B.len)
    {
        pair<int, int> res = {A.xst + A.xdif * tmp.x, B.yst + B.ydif * tmp.y};
        return {true, res};
    }
    else
    {
        return {false, tmp};
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].p[0].x >> a[i].p[0].y >> a[i].p[1].x >> a[i].p[1].y;
        ans += (a[i].len = llabs(__gcd(a[i].p[0].x - a[i].p[1].x, a[i].p[0].y - a[i].p[1].y))) + 1;
        a[i].xst = a[i].p[0].x;
        a[i].yst = a[i].p[0].y;
        a[i].xdif = (a[i].p[1].x - a[i].p[0].x) / a[i].len;
        a[i].ydif = (a[i].p[1].y - a[i].p[0].y) / a[i].len;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            // cout << i << ' ' << j << endl;
            pair<bool, pair<int, int>> tmp = get(a[i], a[j]);
            // cout << tmp.second.x << ' ' << tmp.second.y << endl;
            if (tmp.first)
            {
                // cout << i << " " << j << endl;
                ++g[tmp.second];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        nmsl[i] = i * (i - 1) / 2;
    }
    for (auto i : g)
    {
        ans -= lower_bound(nmsl + 1, nmsl + 1 + n, i.second) - nmsl - 1;
    }
    cout << ans << endl;
    return 0;
}