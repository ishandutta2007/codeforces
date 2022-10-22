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
int n, u, e[100005];
double ans = -1;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> u;
    for (int i = 1; i <= n; ++i)
    {
        cin >> e[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int j = i + 1, k = upper_bound(e + 1, e + 1 + n, e[i] + u) - 1 - e;
        if (i < j && j < k && k <= n)
            ans = max(ans, (e[k] - e[j]) * 1.0l / (e[k] - e[i]));
    }
    if (ans < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}