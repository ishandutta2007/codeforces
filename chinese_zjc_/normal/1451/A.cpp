//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int T, n, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 3)
        {
            cout << 2 << endl;
            continue;
        }
        if (n & 1)
        {
            cout << 3 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}