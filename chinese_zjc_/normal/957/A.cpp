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
int n;
char a[10005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    a[0] = '?';
    a[n + 1] = '?';
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '?')
        {
            if (a[i - 1] != '?' && a[i + 1] != '?' && a[i - 1] != a[i + 1])
            {
                a[i] = 'C' ^ 'M' ^ 'Y' ^ a[i - 1] ^ a[i + 1];
            }
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != '?' && a[i] == a[i + 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '?')
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}