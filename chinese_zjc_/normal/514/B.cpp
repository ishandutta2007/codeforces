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
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, x, y;
bool X, Y;
struct node
{
    int x, y;
} a[1005];
set<pair<int, int>> g;
int gcd(int A, int B)
{
    return B ? gcd(B, A % B) : A;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        a[i].x -= x;
        a[i].y -= y;
        if (a[i].x == 0 && a[i].y == 0)
        {
            --i;
            --n;
            continue;
        }
        if (a[i].x == 0)
        {
            X = true;
            --i;
            --n;
            continue;
        }
        if (a[i].y == 0)
        {
            Y = true;
            --i;
            --n;
            continue;
        }
        g.insert({a[i].x / gcd(a[i].x, a[i].y), a[i].y / gcd(a[i].x, a[i].y)});
    }
    cout << max(1ll, (int)g.size() + X + Y) << endl;
    return 0;
}