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
string a;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> a;
    for (int i = 0; i < (int)a.length(); ++i)
    {
        a[i] = min(a[i], (char)('9' - a[i] + '0'));
    }
    if (a[0] == '0')
    {
        a[0] = '9';
    }
    cout << a << endl;
    return 0;
}