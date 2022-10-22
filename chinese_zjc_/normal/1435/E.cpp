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
int T, a, b, c, d;
// a is the AT
// b is the HP give per second
// c is the time of the HP give
// d is the cooltime of the skill
int l, r;
int A()
{
    int tim = c / d + 1;
    int v = b * d;
    return a * tim - (tim - 1) * tim / 2 * v;
}
int B()
{
    int v = b * d;
    int tim = ceil(a * 1.0 / v);
    return a * tim - (tim - 1) * tim / 2 * v;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c >> d;
        if (a > b * c)
        {
            cout << -1 << endl;
            continue;
        }
        cout << max(A(), B()) << endl;
    }
    return 0;
}