//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int T, n, ansX[3], ansO[3];
pair<int, int> best;
char a[305][305];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            ansX[i] = 0;
            ansO[i] = 0;
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= n; ++k)
                {
                    if (a[j][k] == 'X' && (j + k) % 3 == i)
                    {
                        ++ansX[i];
                    }
                    if (a[j][k] == 'O' && (j + k) % 3 == i)
                    {
                        ++ansO[i];
                    }
                }
            }
        }
        best = {0, 1};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (ansX[i] + ansO[j] < ansX[best.first] + ansO[best.second])
                {
                    best = {i, j};
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == 'X' && (i + j) % 3 == best.first)
                {
                    a[i][j] = 'O';
                }
                if (a[i][j] == 'O' && (i + j) % 3 == best.second)
                {
                    a[i][j] = 'X';
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}