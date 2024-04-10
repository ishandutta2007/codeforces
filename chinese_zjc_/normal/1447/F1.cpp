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
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int n, a[200005], Max, b[200005], sum[200005], l[400005], ans;
vector<int> g[200005];
struct L
{
    int v, p;
    bool operator<(const L &__Val) const
    {
        return v < __Val.v;
    }
} appear[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ++appear[a[i]].v;
        appear[i].p = i;
        g[a[i]].push_back(i);
    }
    sort(appear + 1, appear + 1 + n);
    for (auto i : g[appear[n].p])
    {
        b[i] = 1;
    }
    for (int i = n - 1; i > max(n - 450, 0ll); --i)
    {
        for (auto j : g[appear[i].p])
        {
            b[j] = -1;
        }
        memset(l, -1, sizeof(l));
        l[0] = 0;
        for (int j = 1; j <= n; ++j)
        {
            sum[j] = sum[j - 1] + b[j];
            if (~l[sum[j]])
            {
                ans = max(ans, j - l[sum[j]]);
            }
            else
            {
                l[sum[j]] = j;
            }
        }
        for (auto j : g[appear[i].p])
        {
            b[j] = 0;
        }
    }
    if (n - 450 > 0)
    {
        while (clock() < 1800)
        {
            int i = Rand() % (n - 450) + 1;
            for (auto j : g[appear[i].p])
            {
                b[j] = -1;
            }
            memset(l, -1, sizeof(l));
            l[0] = 0;
            for (int j = 1; j <= n; ++j)
            {
                sum[j] = sum[j - 1] + b[j];
                if (~l[sum[j]])
                {
                    ans = max(ans, j - l[sum[j]]);
                }
                else
                {
                    l[sum[j]] = j;
                }
            }
            for (auto j : g[appear[i].p])
            {
                b[j] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}