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
int n, a, b, k, h, sx, sy, ex, ey;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> h >> a >> b >> k;
    while (k--)
    {
        cin >> sx >> sy >> ex >> ey;
        if (sx == ex)
        {
            cout << llabs(sy - ey) << endl;
        }
        else if (a <= sy && sy <= b)
        {
            cout << llabs(sx - ex) + llabs(sy - ey) << endl;
        }
        else
        {
            cout << min(llabs(sy - a) + llabs(ey - a) + llabs(ex - sx),
                        llabs(sy - b) + llabs(ey - b) + llabs(ex - sx))
                 << endl;
        }
    }

    return 0;
}