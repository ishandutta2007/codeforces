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
const int INF = 1e17;
int n, v[100005], fa[100005], k[100005];
std::vector<int> son[100005];
int dfs(int now)
{
    int res = v[now];
    for (auto i : son[now])
    {
        res += dfs(i);
        if (1.0l * res * k[now] < -INF)
            std::cout << "NO" << std::endl, exit(0);
    }
    return res < 0 ? res * k[now] : res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i <= n; ++i)
    {
        static int tmp;
        std::cin >> tmp;
        v[i] -= tmp;
    }
    for (int i = 2; i <= n; ++i)
    {
        std::cin >> fa[i] >> k[i];
        son[fa[i]].push_back(i);
    }
    k[1] = 1;
    std::cout << (dfs(1) >= 0 ? "YES" : "NO") << std::endl;
    // for (int i = 1; i <= n; ++i)
    //     std::cout << dfs(i) << std::endl;
    return 0;
}