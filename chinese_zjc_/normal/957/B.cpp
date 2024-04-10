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
int n, m;
char a[1005][1005];
vector<int> hang, lie;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '#')
            {
                hang.clear();
                lie.clear();
                for (int k = 1; k <= n; ++k)
                {
                    if (a[k][j] == '#')
                    {
                        hang.push_back(k);
                    }
                }
                for (int k = 1; k <= m; ++k)
                {
                    if (a[i][k] == '#')
                    {
                        lie.push_back(k);
                    }
                }
                for (auto k : hang)
                {
                    for (auto l : lie)
                    {
                        if (a[k][l] == '.')
                        {
                            cout << "No" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}