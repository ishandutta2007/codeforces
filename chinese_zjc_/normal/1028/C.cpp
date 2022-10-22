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
int n;
struct matrix
{
    int sx, sy, ex, ey;
    friend matrix operator+(const matrix &A, const matrix &B)
    {
        matrix res;
        res.sx = std::max(A.sx, B.sx);
        res.sy = std::max(A.sy, B.sy);
        res.ex = std::min(A.ex, B.ex);
        res.ey = std::min(A.ey, B.ey);
        return res;
    }
} a[150005], pre[150005], suf[150005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].sx >> a[i].sy >> a[i].ex >> a[i].ey;
    suf[n + 1].sx = pre[0].sx = -INF;
    suf[n + 1].sy = pre[0].sy = -INF;
    suf[n + 1].ex = pre[0].ex = +INF;
    suf[n + 1].ey = pre[0].ey = +INF;
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + a[i];
    for (int i = n; i >= 1; --i)
        suf[i] = suf[i + 1] + a[i];
    for (int i = 1; i <= n; ++i)
    {
        matrix res = pre[i - 1] + suf[i + 1];
        if (res.sx <= res.ex && res.sy <= res.ey)
            std::cout << res.sx << ' ' << res.sy << std::endl, exit(0);
    }
    return 0;
}