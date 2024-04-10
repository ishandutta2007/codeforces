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
int Max[55], n, m, h, l, r, v, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> h >> m;
    for (int i = 1; i <= n; ++i)
    {
        Max[i] = h;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> l >> r >> v;
        for (int j = l; j <= r; ++j)
        {
            Max[j] = min(Max[j], v);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += Max[i] * Max[i];
    }
    cout << ans << endl;
    return 0;
}