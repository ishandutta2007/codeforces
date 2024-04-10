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
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int v, n, ans[100005], cnt;
struct node
{
    int x, t, a, b;
    friend bool operator<(const node &A, const node &B) { return A.a == B.a ? A.b < B.b : A.a > B.a; }
} d[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> d[i].x >> d[i].t;
    std::cin >> v;
    for (int i = 1; i <= n; ++i)
    {
        d[i].t *= v;
        d[i].a = d[i].x - d[i].t;
        d[i].b = d[i].x + d[i].t;
    }
    std::sort(d + 1, d + 1 + n);
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i].a > 0 || d[i].b < 0)
            continue;
        int x = std::upper_bound(ans + 1, ans + 1 + cnt, d[i].b) - ans;
        cnt = std::max(cnt, x);
        ans[x] = d[i].b;
    }
    std::cout << cnt << ' ';
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = std::upper_bound(ans + 1, ans + 1 + cnt, d[i].b) - ans;
        cnt = std::max(cnt, x);
        ans[x] = d[i].b;
    }
    std::cout << cnt << std::endl;
    return 0;
}