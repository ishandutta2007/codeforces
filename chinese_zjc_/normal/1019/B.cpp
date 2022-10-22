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
int a[100005];
queue<int> que;
int &query(int pos)
{
    cout << '?' << ' ' << (pos ? pos : n) << endl;
    cin >> a[pos % n];
    return a[pos % n];
}
void submit(int pos)
{
    cout << '!' << ' ' << (pos ? pos : n) << endl;
    exit(0);
}
int get(int now)
{
    return query(now + n / 2) - query(now);
}
void solve(int l, int r, int L, int R)
{
    if (L == 0)
    {
        submit(l);
    }
    if (R == 0)
    {
        submit(r);
    }
    int mid = (l + r) >> 1;
    int val = get(mid);
    if (llabs(L - 0) + llabs(0 - val) == llabs(L - val))
    {
        solve(l, mid, L, val);
    }
    else
    {
        solve(mid + 1, r, get(mid + 1), R);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    if (n & 2)
    {
        submit(-1);
    }
    solve(0, n / 2 - 1, get(0), get(n / 2 - 1));
    return 0;
}