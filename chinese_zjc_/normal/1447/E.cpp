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
int n, a[200005];
int solve(int l, int r, int pos)
{
    if (l == r)
    {
        return 0;
    }
    int L = l, R = r + 1;
    while (L < R)
    {
        int mid = (L + R) >> 1;
        if (a[mid] & (1 << pos))
        {
            R = mid;
        }
        else
        {
            L = mid + 1;
        }
    }
    if (L <= l || r < R)
    {
        return solve(l, r, pos - 1);
    }
    return min(solve(l, L - 1, pos - 1) + (r - R), solve(L, r, pos - 1) + (L - l - 1));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    cout << solve(1, n, 30) << endl;
    return 0;
}