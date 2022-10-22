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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
int n, m, k, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        if ((n - i * 4) <= 0 || (m - i * 4) <= 0)
        {
            break;
        }
        if ((n - i * 4) == 1)
        {
            ans += (m - i * 4);
            break;
        }
        if ((m - i * 4) == 1)
        {
            ans += (n - i * 4);
            break;
        }
        ans += (n - i * 4 - 1) * 2 + (m - i * 4 - 1) * 2;
    }
    cout << ans << endl;
    return 0;
}