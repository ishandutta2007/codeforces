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
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, ans, fa[1000005], odd[1000005], siz[1000005];
bool x[1000005];
bool d[1000005];
int find(int now)
{
    return fa[now] == now ? now : fa[now] = find(fa[now]);
}
vector<int> g;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        cin >> a >> b;
        d[a] ^= true;
        d[b] ^= true;
        x[a] = true;
        x[b] = true;
        if (a != b)
            fa[find(a)] = find(b);
    }
    for (int i = 1; i <= n; ++i)
    {
        ++siz[find(i)];
        if (d[i])
            ++odd[find(i)];
    }
    for (int i = 1; i <= n; ++i)
        if (find(i) == i && (find(1) == i || odd[i] || x[i]))
            g.push_back(odd[i]);
    sort(g.begin(), g.end());
    if (g.size() == 1)
    {
        cout << g.front() / 2 << endl;
    }
    else
    {
        int ans = 0;
        for_each(g.begin(), g.end(), [&](int &x) { x = max(0ll, x - 2); ans += x / 2 + 1; });
        cout << ans << endl;
    }
    return 0;
}