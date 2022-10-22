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
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[200005], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ans = m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ans = __gcd(ans, a[i]);
    }
    cout << m / ans << endl;
    for (int i = 0; i < m / ans; ++i)
    {
        cout << i * ans << ' ';
    }
    cout << endl;
    return 0;
}