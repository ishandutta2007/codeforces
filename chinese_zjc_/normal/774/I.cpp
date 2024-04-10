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
int dis[2505], n;
std::vector<int> to[2505];
std::string s[55], t;
std::queue<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i];
    std::cin >> t;
    std::fill(dis + 1, dis + 1 + t.size(), -1);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j != (int)t.size(); ++j)
        {
            int l = j;
            for (int k = 0; k != (int)s[i].size(); ++k)
                if (t[l] == s[i][k])
                    ++l;
            if (j != l)
                to[j].push_back(l);
        }
    que.push(0);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (auto i : to[now])
            if (!~dis[i])
                dis[i] = dis[now] + 1, que.push(i);
    }
    std::cout << dis[t.size()] << std::endl;
    return 0;
}