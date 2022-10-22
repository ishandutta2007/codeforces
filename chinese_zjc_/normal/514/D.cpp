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
int n, m, k, a[6][100005], l, r, st[6][20][100005], lg[100005], ansl, ansr;
int lowbit(int now)
{
    return now & -now;
}
int Max(int now, int l, int r)
{
    return max(st[now][lg[r - l + 1]][l], st[now][lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]);
}
bool check(int l, int r)
{
    int res = 0;
    for (int i = 1; i <= m; ++i)
    {
        res += Max(i, l, r);
    }
    return res <= k;
}
void print(int l, int r)
{
    for (int i = 1; i <= m; ++i)
    {
        cout << Max(i, l, r) << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[j][i];
            st[j][0][i] = a[j][i];
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; 1 << j <= n; ++j)
        {
            for (int k = 1; k + (1 << j) - 1 <= n; ++k)
            {
                st[i][j][k] = max(st[i][j - 1][k], st[i][j - 1][k + (1 << j >> 1)]);
            }
            // cout << endl;
        }
        // cout << endl;
    }
    for (int i = 2; i <= n; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i) == i);
        // cout << lg[i] << ' ';
    }
    // cout << endl;
    l = r = 1;
    while (l <= n)
    {
        while (r <= n)
        {
            r = max(l, r);
            if (check(l, r))
            {
                if (r - l + 1 >= ansr - ansl + 1)
                {
                    ansl = l;
                    ansr = r;
                }
                ++r;
            }
            else
            {
                --r;
                break;
            }
        }
        ++l;
    }
    print(ansl, ansr);
    return 0;
}