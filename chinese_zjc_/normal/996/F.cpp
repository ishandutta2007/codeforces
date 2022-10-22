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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, r, a, b, f[1 << 18], ans;
double s;
signed main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(6);
    cin >> n >> r;
    s = 1 << n;
    for (int i = 0; i < 1 << n; ++i)
    {
        cin >> f[i];
        ans += f[i];
    }
    cout << ans / s << endl;
    for (int i = 1; i <= r; ++i)
    {
        cin >> a >> b;
        ans -= f[a];
        f[a] = b;
        ans += f[a];
        cout << ans / s << endl;
    }
    return 0;
}