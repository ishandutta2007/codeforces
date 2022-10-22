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
int n, m;
std::map<int, int> ac, bc;
std::priority_queue<std::pair<int, int>> que;
void get(int x)
{
    std::map<int, int>::iterator i = bc.lower_bound(m - x);
    if (i == bc.begin())
        que.push({bc.rbegin()->first + x - m, x});
    else
        que.push({(--i)->first + x, x});
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        ++ac[x % m];
    }
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        ++bc[x % m];
    }
    for (auto i : ac)
        get(i.first);
    while (!que.empty())
    {
        std::pair<int, int> now = que.top();
        que.pop();
        if (bc.find((now.first - now.second + m) % m) == bc.end())
            get(now.second);
        else
        {
            std::cout << now.first << ' ';
            if (!--bc[(now.first - now.second + m) % m])
                bc.erase((now.first - now.second + m) % m);
            if (--ac[now.second])
                get(now.second);
            else
                ac.erase(now.second);
        }
        // for (auto j : ac)
        //     std::cout << j.first << ' ' << j.second << std::endl;
        // for (auto j : bc)
        //     std::cout << j.first << ' ' << j.second << std::endl;
    }
    return 0;
}