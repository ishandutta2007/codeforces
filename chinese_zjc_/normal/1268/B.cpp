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
int n, a[300005], white, black;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i & 1)
        {
            white += a[i] / 2;
            black += (a[i] + 1) / 2;
        }
        else
        {
            white += (a[i] + 1) / 2;
            black += a[i] / 2;
        }
    }
    cout << min(white, black) << endl;
    return 0;
}