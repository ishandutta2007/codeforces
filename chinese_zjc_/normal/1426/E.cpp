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
int n, a[2][3], b[2][3], Min, Max, tmp;
bool allzero()
{
    for (int i = 0; i < 3; ++i)
    {
        if (b[0][i])
        {
            return false;
        }
    }
    return true;
}
void dfs(int now)
{
    if (allzero())
    {
        Min = min(now, Min);
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 2; j <= 3; ++j)
        {
            if (b[0][i] && b[1][(i + j) % 3])
            {
                int tmp = min(b[0][i], b[1][(i + j) % 3]);
                b[0][i] -= tmp;
                b[1][(i + j) % 3] -= tmp;
                dfs(now);
                b[0][i] += tmp;
                b[1][(i + j) % 3] += tmp;
            }
        }
        if (b[0][i] && b[1][(i + 1) % 3])
        {
            int tmp = min(b[0][i], b[1][(i + 1) % 3]);
            b[0][i] -= tmp;
            b[1][(i + 1) % 3] -= tmp;
            dfs(now + tmp);
            b[0][i] += tmp;
            b[1][(i + 1) % 3] += tmp;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> a[i][j];
        }
    }
    memcpy(b, a, sizeof b);
    Min = n;
    dfs(0);
    memcpy(b, a, sizeof b);
    for (int i = 0; i < 3; ++i)
    {
        tmp = min(b[0][i], b[1][(i + 1) % 3]);
        Max += tmp;
        b[0][i] -= tmp;
        b[1][(i + 1) % 3] -= tmp;
    }
    cout << Min << ' ' << Max << endl;
    return 0;
}