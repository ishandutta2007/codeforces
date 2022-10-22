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
int T, n, k, a[105], cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    a[0] = -1;
    while (T--)
    {
        cin >> n >> k;
        cnt = 0;
        --k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (a[i] != a[i - 1])
            {
                ++cnt;
            }
        }
        --cnt;
        bool flag = false;
        for (int i = 1; i <= n; ++i)
        {
            if (i * k >= cnt)
            {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}