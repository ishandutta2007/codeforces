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
int n, m, a[2005];
bool vis[2005];
std::vector<int> to[105];
std::stack<int> stack;
bool dfs(int now, int tim, bool big)
{
    if (tim == m && big)
        return true;
    std::sort(to[now].begin(), to[now].end(), [&](const int &A, const int &B)
              { return (a[A] ^ a[A - 1] ^ now) < (a[B] ^ a[B - 1] ^ now); });
    for (auto i : to[now])
    {
        int nxt = a[i] ^ a[i - 1] ^ now;
        if (!vis[i] && (big || nxt >= a[tim + 1]))
        {
            vis[i] = true;
            if (dfs(nxt, tim + 1, big || nxt > a[tim + 1]))
                return stack.push(nxt), true;
            vis[i] = false;
        }
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i <= m; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
        to[a[i - 1]].push_back(i), to[a[i]].push_back(i);
    if (!dfs(a[0], 0, false))
        return std::cout << "No solution" << std::endl, 0;
    else
        for (std::cout << a[0]; !stack.empty(); stack.pop())
            std::cout << ' ' << stack.top();
    return 0;
}