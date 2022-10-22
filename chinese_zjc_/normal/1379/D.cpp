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
int n, h, m, k, l = -INF, r;
struct node
{
    int x, p;
    friend bool operator<(const node &A, const node &B) { return A.x < B.x; }
} a[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> h >> m >> k;
    m >>= 1;
    for (int i = 0; i != n; ++i)
        std::cin >> h >> a[i].x, a[i].p = i + 1, a[i].x %= m;
    std::sort(a, a + n);
    std::copy(a, a + n, a + n);
    for (int i = n, j = 0; i != 2 * n; ++i)
    {
        a[i].x += m;
        while (a[i].x - a[j].x >= k)
            ++j;
        if (r - l > i - j)
        {
            r = i;
            l = j;
        }
    }
    std::cout << r - l << ' ' << a[r].x - m << std::endl;
    for (int i = l; i != r; ++i)
        std::cout << a[i].p << ' ';
    std::cout << std::endl;
    return 0;
}