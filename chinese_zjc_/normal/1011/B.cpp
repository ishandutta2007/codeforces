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
int n, m, a[105], has[105], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
        ++has[a[i]];
    }
    for (int i = 1; i <= 105; ++i)
    {
        memcpy(a, has, sizeof(has));
        int l = 0;
        for (int j = 1; j <= 100; ++j)
        {
            while (a[j] >= i)
            {
                a[j] -= i;
                ++l;
            }
        }
        if (l >= n)
        {
            continue;
        }
        cout << i - 1 << endl;
        return 0;
    }
    return 0;
}