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
int n, m, sum[200005], d[100005], h[100005], v1[200005], v2[200005];
template <int *x>
struct ST
{
    int max[19][200005];
    int lg[200005];
    int cmax(int A, int B)
    {
        return x[A] < x[B] ? B : A;
    }
    void init()
    {
        x[0] = -INF;
        for (int i = 1; i <= n + n; ++i)
            max[0][i] = i;
        lg[1] = 0;
        for (int i = 2; i <= n + n; ++i)
            lg[i] = lg[i - 1] + !(i & (i - 1));
        for (int i = 1; 1 << i <= n + n; ++i)
            for (int j = 1; j + (1 << i) - 1 <= n + n; ++j)
                max[i][j] = cmax(max[i - 1][j], max[i - 1][j + (1 << i >> 1)]);
    }
    int query(int l, int r)
    {
        if (l > r)
            return 0;
        int len = lg[r - l + 1];
        return cmax(max[len][l], max[len][r - (1 << len) + 1]);
    }
};
ST<v1> A;
ST<v2> B;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> d[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> h[i];
    for (int i = 1; i <= n; ++i)
        sum[i + 1] = sum[i] + d[i];
    for (int i = n + 1; i < n + n; ++i)
        sum[i + 1] = sum[i] + d[i - n];
    for (int i = 1; i <= n + n; ++i)
        v1[i] = h[i > n ? i - n : i] * 2 - sum[i];
    for (int i = 1; i <= n + n; ++i)
        v2[i] = h[i > n ? i - n : i] * 2 + sum[i];
    A.init();
    B.init();
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        if (x <= y)
        {
            std::swap(x, y);
            x = x + 1;
            y = y + n - 1;
        }
        else
        {
            std::swap(x, y);
            x = x + 1;
            y = y - 1;
        }
        int f = A.query(x, y), t = B.query(x, y);
        // std::cout << x << ' ' << y << std::endl;
        // for (int i = 1; i <= n + n; ++i)
        //     std::cout << v1[i] << " \n"[i == n + n];
        // for (int i = 1; i <= n + n; ++i)
        //     std::cout << v2[i] << " \n"[i == n + n];
        // std::cout << f << " " << t << std::endl;
        if (f == t)
            std::cout << std::max(v2[B.query(f + 1, y)] + v1[f], v2[t] + v1[A.query(x, t - 1)])
                      << std::endl;
        else
            std::cout << v2[t] + v1[f] << std::endl;
    }
    return 0;
}