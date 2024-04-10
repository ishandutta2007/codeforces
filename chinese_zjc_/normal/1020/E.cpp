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
vector<int> to[1000005];
int n, m, a, b;
bool in[1000005], vis[1000005];
vector<int> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        to[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = in[i] = true;
            for (auto j : to[i])
            {
                vis[j] = true;
            }
        }
    }
    for (int i = n; i; --i)
    {
        if (in[i])
        {
            for (auto j : to[i])
            {
                in[j] = false;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (in[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}