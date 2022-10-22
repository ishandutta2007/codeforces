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
int n, ans;
struct vector
{
    int x, y, p;
} a[100005];
int cha(vector A, vector B) { return A.x * B.y - A.y * B.x; }
int dian(vector A, vector B) { return A.x * B.x + A.y * B.y; }
int len2(vector X) { return X.x * X.x + X.y * X.y; }
bool top(vector X) { return X.y > 0 || (X.y == 0 && X.x > 0); }
bool cmp(vector A, vector B)
{
    bool a = top(A), b = top(B);
    if (a ^ b)
        return a > b;
    return cha(A, B) > 0;
}
__int128 sqr(int x) { return x * x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> a[i].x >> a[i].y;
        a[i].p = i + 1;
    }
    std::sort(a, a + n, cmp);
    // for (int i = 0; i != n; ++i)
    //     std::cout << a[i].x << ' ' << a[i].y << std::endl;
    for (int i = 0; i != n; ++i)
    {
        int A = dian(a[i], a[(i + 1) % n]), B = dian(a[ans], a[(ans + 1) % n]);
        if (A == 0 && B < 0)
            ans = i;
        else if ((A < 0) ^ (B < 0))
            if (A > 0)
                ans = i;
            else
                ;
        else if ((A < 0) ^
                 (sqr(A) * len2(a[ans]) * len2(a[(ans + 1) % n]) > sqr(B) * len2(a[i]) * len2(a[(i + 1) % n])))
            ans = i;
        // std::cout << A << std::endl;
    }
    // std::cout << ans << std::endl;
    std::cout << a[ans].p << ' ' << a[(ans + 1) % n].p << std::endl;
    return 0;
}