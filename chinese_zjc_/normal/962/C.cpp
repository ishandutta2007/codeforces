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
string n, s;
set<int> good;
int ans = INF;
int lowbit(int now)
{
    return now & -now;
}
int num(int now)
{
    return now ? num(now ^ lowbit(now)) + 1 : 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i * i <= 2000000000; ++i)
    {
        good.insert(i * i);
    }
    cin >> n;
    for (int i = 1; i < 1 << n.length(); ++i)
    {
        s = "";
        for (int j = 0; j < n.length(); ++j)
        {
            if (i & (1 << j))
            {
                s += n[j];
            }
        }
        if (s.front() == '0')
        {
            continue;
        }
        if (good.find(atoi(s.c_str())) != good.end())
        {
            ans = min(ans, n.length() - num(i));
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}