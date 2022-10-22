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
map<int, bool> has;
int sum, n, a[200005], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    has[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        if (has[sum])
        {
            ++ans;
            has.clear();
            sum = a[i];
            has[0] = true;
        }
        has[sum] = true;
    }
    cout << ans << endl;
    return 0;
}