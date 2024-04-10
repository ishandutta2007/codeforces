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
int n, k, a, t[1005], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        ++t[a];
    }
    for (int i = 1; i <= (n + 1) >> 1; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (t[j] > 1)
            {
                t[j] -= 2;
                ans += 2;
                goto nxt;
            }
        }
        for (int j = 1; j <= k; ++j)
        {
            if (t[j] == 1)
            {
                t[j] -= 1;
                ans += 1;
                goto nxt;
            }
        }
    nxt:
        continue;
    }
    cout << ans << endl;
    return 0;
}