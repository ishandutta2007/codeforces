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
int n, m, T, a[100005], lspeed, rspeed, nxtl, nxtr;
double l, r, runtime;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        l = 0;
        r = m;
        lspeed = 1;
        rspeed = 1;
        nxtl = 1;
        nxtr = n;
        runtime = 0;
        while (nxtl <= nxtr)
        {
            double nxttime = min((a[nxtl] - l) / lspeed, (r - a[nxtr]) / rspeed);
            l += nxttime * lspeed;
            r -= nxttime * rspeed;
            runtime += nxttime;
            if (abs(l - a[nxtl]) < eps)
            {
                ++lspeed;
                ++nxtl;
            }
            if (abs(r - a[nxtr]) < eps)
            {
                ++rspeed;
                --nxtr;
            }
        }
        cout << fixed << setprecision(20) << runtime + ((r - l) / (lspeed + rspeed)) << endl;
    }
    return 0;
}