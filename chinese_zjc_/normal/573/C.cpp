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
int n, c[100005];
bool died[100005];
std::vector<int> son[100005];
void dfs(int now)
{
    died[now] = true;
    for (auto i : son[now])
        if (!died[i] && son[i].size() <= 2)
            dfs(i);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i != n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (son[i].size() == 1)
            dfs(i);
    for (int i = 1; i <= n; ++i)
        for (auto j : son[i])
            if (died[j])
                ++c[i];
    for (int i = 1; i <= n; ++i)
        c[i] = std::min(c[i], 2ll);
    for (int i = 1; i <= n; ++i)
        if (!died[i])
        {
            int cnt = 0;
            for (auto j : son[i])
                if (!died[j] && son[j].size() - c[j] > 1)
                    ++cnt;
            if (cnt > 2)
                return std::cout << "No" << std::endl, 0;
        }
    std::cout << "Yes" << std::endl;
    return 0;
}