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
int n, a[205], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n + n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n * 2; ++i)
    {
        if (a[i] != a[i + 1])
        {
            for (int j = i + 1; j <= n * 2; ++j)
            {
                if (a[j] == a[i])
                {
                    --j;
                    while (j > i)
                    {
                        swap(a[j], a[j + 1]);
                        ++ans;
                        --j;
                    }
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}