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
int n, m;
class person
{
public:
    int x, y;
} a[2005];
class light
{
public:
    int x, y;
} b[2005];
set<pair<int, int>> ans;
bool in(int A, int B)
{
    return a[A].x <= b[B].x && a[A].y <= b[B].y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i].x >> b[i].y;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (in(i, j))
            {
                ans.insert({b[j].x - a[i].x, b[j].y - a[i].y});
            }
        }
    }
    if (ans.empty())
    {
        cout << 0 << endl;
        return 0;
    }
    for (set<pair<int, int>>::iterator i = ++ans.begin(); i != ans.end(); ++i)
    {
        set<pair<int, int>>::iterator lst = i;
        --lst;
        while (i != ans.begin() && lst->first <= i->first && lst->second <= i->second)
        {
            ans.erase(lst--);
        }
    }
    int res = min(ans.begin()->second + 1, ans.rbegin()->first + 1);
    for (set<pair<int, int>>::iterator i = ++ans.begin(); i != ans.end(); ++i)
    {
        set<pair<int, int>>::iterator lst = i;
        --lst;
        res = min(res, lst->first + 1 + i->second + 1);
    }
    cout << res << endl;
    return 0;
}