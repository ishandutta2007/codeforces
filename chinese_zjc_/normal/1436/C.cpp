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
const int MOD = 1000000007;
int n, x, pos, big, small;
void solve(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    if (mid == pos)
    {
        solve(mid + 1, r);
        return;
    }
    if (mid < pos)
    {
        ++small;
        solve(mid + 1, r);
    }
    else
    {
        ++big;
        solve(l, mid);
    }
}
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int fact(int now)
{
    return now ? fact(now - 1) * now % MOD : 1;
}
int P(int A, int B)
{
    if (B < 0 || B < A)
    {
        return 0;
    }
    return fact(B) * power(fact(B - A), MOD - 2) % MOD;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> x >> pos;
    solve(0, n);
    cout << fact(n - big - small - 1) * P(big, n - x) % MOD * P(small, x - 1) % MOD << endl;
    return 0;
}