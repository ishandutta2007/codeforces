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
bool dp[100005][4];
int from[100005][4];
int n, a[100005], b[100005];
void print(int pos, int f)
{
    if (pos > 1)
    {
        print(pos - 1, from[pos][f]);
    }
    cout << f << ' ';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 0; i < 4; ++i)
    {
        dp[1][i] = true;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int f = 0; f < 4; ++f)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (dp[i - 1][f] && (f | j) == a[i] && (f & j) == b[i])
                {
                    dp[i][j] = true;
                    from[i][j] = f;
                }
            }
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        if (dp[n][i])
        {
            cout << "YES" << endl;
            print(n, i);
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}