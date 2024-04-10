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
std::vector<int> del, to[100005];
bool died[100005];
int has[100005], n, m, k, ans1, tim;
std::priority_queue<std::pair<double, int>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
    {
        static int x;
        std::cin >> x;
        died[x] = true;
    }
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (died[i])
            for (auto j : to[i])
                ++has[j];
    for (int i = 1; i <= n; ++i)
        if (!died[i])
            que.push({has[i] * 1.0 / to[i].size(), i});
    for (int i = 0; i != n - k; ++i)
    {
        while (died[que.top().second])
            que.pop();
        int now = que.top().second;
        que.pop();
        del.push_back(now);
        died[now] = true;
        // std::cout << has[now] * to[del[tim]].size() << ' ' << has[del[tim]] * to[now].size() << std::endl;
        if (has[now] * 1.0 / to[now].size() < has[del[tim]] * 1.0 / to[del[tim]].size())
            tim = i;
        for (auto j : to[now])
            if (!died[j])
                ++has[j], que.push({has[j] * 1.0 / to[j].size(), j});
        // std::cout << has[6] * 1.0 / to[6].size() << ' ' << has[10] * 1.0 / to[10].size() << std::endl;
    }
    std::cout << n - k - tim << std::endl;
    for (int i = tim; i != n - k; ++i)
        std::cout << del[i] << " \n"[i + 1 == n - k];
    // for (auto i : del)
    //     std::cout << i << ' ';
    // std::cout << std::endl;
    return 0;
}