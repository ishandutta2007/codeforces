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
int n, a[200005], from[200005][10];
bool dp[200005][10];
void print(int pos, int c)
{
    if (pos > 1)
    {
        print(pos - 1, from[pos][c]);
    }
    cout << c << ' ';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 5; ++i)
    {
        dp[1][i] = true;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            if (a[i] == a[i - 1])
            {
                for (int k = 1; k <= 5; ++k)
                {
                    if (j != k && dp[i - 1][k])
                    {
                        dp[i][j] = true;
                        from[i][j] = k;
                    }
                }
            }
            if (a[i] < a[i - 1])
            {
                for (int k = 1; k <= 5; ++k)
                {
                    if (j < k && dp[i - 1][k])
                    {
                        dp[i][j] = true;
                        from[i][j] = k;
                    }
                }
            }
            if (a[i] > a[i - 1])
            {
                for (int k = 1; k <= 5; ++k)
                {
                    if (j > k && dp[i - 1][k])
                    {
                        dp[i][j] = true;
                        from[i][j] = k;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 5; ++i)
    {
        if (dp[n][i])
        {
            print(n, i);
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}