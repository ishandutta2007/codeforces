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
int n, m, a[300005], b[300005], suma[300005], sumb[300005], ans;
map<int, bool> appear;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        suma[i] = suma[i - 1] + a[i];
        appear[suma[i]] = true;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
        sumb[i] = sumb[i - 1] + b[i];
        ans += appear[sumb[i]];
    }
    if (suma[n] != sumb[m])
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}