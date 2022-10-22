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
int n, m, a[15][15], T, f, Min, sum;
bool clear;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        clear = false;
        f = 0;
        Min = INF;
        sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 0)
                {
                    clear = true;
                }
                if (a[i][j] < 0)
                {
                    ++f;
                }
                Min = min(Min, llabs(a[i][j]));
                sum += llabs(a[i][j]);
            }
        }
        if (clear || !(f & 1))
        {
            cout << sum << endl;
        }
        else
        {
            cout << sum - Min - Min << endl;
        }
    }
    return 0;
}