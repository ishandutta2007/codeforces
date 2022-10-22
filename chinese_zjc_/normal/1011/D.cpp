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
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, l, r;
int query(int num)
{
    cout << num << endl;
    int v;
    cin >> v;
    if (v == 0)
    {
        exit(0);
    }
    return v;
}
int f[35], cnt; //-1 is cheat
signed main()
{
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        f[i] = query(1);
    }
    l = 1;
    r = m;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (query(mid) * f[cnt++ % n] == 1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    query(l);
    return 0;
}