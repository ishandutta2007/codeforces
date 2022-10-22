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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, in[100005], ans[100005], cnt, out[100005];
std::vector<int> from[100005];
std::priority_queue<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        from[b].push_back(a);
        ++out[a];
    }
    cnt = n;
    for (int i = 1; i <= n; ++i)
        if (!out[i])
            que.push(i);
    while (!que.empty())
    {
        int now = que.top();
        que.pop();
        ans[now] = cnt--;
        for (auto i : from[now])
            if (!--out[i])
                que.push(i);
    }
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];
    return 0;
}