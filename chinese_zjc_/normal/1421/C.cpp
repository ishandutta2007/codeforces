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
int n, len;
string s;
char L = 'L', R = 'R';
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    cout << 3 << endl;
    cout << R << ' ' << n - 1 << endl;
    n += 1;
    cout << L << ' ' << n - 1 << endl;
    n += n - 2;
    cout << L << ' ' << 2 << endl;
    n += 1;
    return 0;
}