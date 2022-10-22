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
int a, b, c, sx, sy, ex, ey;
double ans;
struct point
{
    double x, y;
} s, e;
double sqr(double x)
{
    return x * x;
}
double dist(point A, point B)
{
    return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}
point Y(double X)
{
    return {X, -(c + a * X) / b};
}
point X(double Y)
{
    return {-(c + b * Y) / a, Y};
}
signed main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(100);
    cin >> a >> b >> c;
    cin >> sx >> sy >> ex >> ey;
    if (a == 0 || b == 0)
    {
        cout << llabs(sx - ex) + llabs(sy - ey) << endl;
        return 0;
    }
    ans = llabs(sx - ex) + llabs(sy - ey);
    s = {sx, sy};
    e = {ex, ey};
    ans = min(ans, dist(s, Y(sx)) + dist(Y(sx), Y(ex)) + dist(Y(ex), e));
    ans = min(ans, dist(s, Y(sx)) + dist(Y(sx), X(ey)) + dist(X(ey), e));
    ans = min(ans, dist(s, X(sy)) + dist(X(sy), Y(ex)) + dist(Y(ex), e));
    ans = min(ans, dist(s, X(sy)) + dist(X(sy), X(ey)) + dist(X(ey), e));
    cout << ans << endl;
    return 0;
}