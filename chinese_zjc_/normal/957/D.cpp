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
int n, has, ans, a[100005], least[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = n; i; --i)
    {
        least[i] = max(a[i] + 1, least[i + 1] - 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        least[i] = max(least[i], least[i - 1]);
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += least[i] - a[i] - 1;
    }
    cout << ans << endl;
    return 0;
}