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
int from[105][3][3], a[105][3], n, T;
void print(int A, int B, int C)
{
    if (A > n)
    {
        return;
    }
    cout << a[A][B] << ' ';
    print(A + 1, from[A][B][C], C);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> a[j][i];
            }
        }
        memset(from, -1, sizeof(from));
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (a[n][i] != a[1][j])
                {
                    from[n][i][j] = j;
                }
            }
        }
        for (int i = n - 1; i; --i)
        {
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    for (int l = 0; l < 3; ++l)
                    {
                        if (a[i][j] != a[i + 1][l] && from[i + 1][l][k] != -1)
                        {
                            from[i][j][k] = l;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            if (from[1][i][i] != -1)
            {
                print(1, i, i);
                cout << endl;
                break;
            }
        }
    }
    return 0;
}