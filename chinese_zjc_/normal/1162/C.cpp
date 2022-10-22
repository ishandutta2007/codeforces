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
int n, k, p[100005], fcan[100005], bcan[100005], ans;
vector<int> ask[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> p[i];
        ask[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ask[i].empty())
        {
            fcan[i] = bcan[i] = k;
            continue;
        }
        fcan[i] = ask[i].front() - 1;
        bcan[i] = k - ask[i].back();
    }
    bcan[0] = bcan[n + 1] = -INF;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (fcan[i] + bcan[i + j] >= k)
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}