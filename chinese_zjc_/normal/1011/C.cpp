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
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[1005], b[1005];
double l = 0, r = 2e9;
bool check(double now)
{
    for (int i = 1; i <= n; ++i)
    {
        now -= (m + now) / a[i % n];
        if (now < 0)
        {
            return false;
        }
        now -= (m + now) / b[(i + 1) % n];
        if (now < 0)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i % n];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i % n];
    }
    while (l + eps < r)
    {
        double mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (l > 1.5e9)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << fixed << setprecision(20) << l << endl;
    return 0;
}