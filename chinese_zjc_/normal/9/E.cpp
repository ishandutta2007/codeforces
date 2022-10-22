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
std::multiset<std::pair<int, int>> ans, l;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    if (n == 1 && m == 1)
        return std::cout << "YES" << std::endl
                         << 0 << std::endl,
               0;
    for (int i = 1; i <= n; ++i)
        l.insert({i, i});
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        std::set<std::pair<int, int>>::iterator j = l.begin(), k = l.begin();
        while (j != l.end() && j->first != x && j->second != x)
            ++j;
        while (k != l.end() && k->first != y && k->second != y)
            ++k;
        if (x != y && j == k && l.size() == 1)
            return std::cout << "YES" << std::endl
                             << 0 << std::endl,
                   0;
        if (j == l.end() || k == l.end() || j == k)
            return std::cout << "NO" << std::endl, 0;
        std::pair<int, int> res(j->first ^ j->second ^ x, k->first ^ k->second ^ y);
        if (res.first > res.second)
            std::swap(res.first, res.second);
        l.insert(res);
        l.erase(j);
        l.erase(k);
    }
    while (l.size() > 1)
    {
        std::pair<int, int> A(l.begin()->first, (++l.begin())->first), B(l.begin()->second, (++l.begin())->second);
        ans.insert(A);
        l.erase(l.begin());
        l.erase(l.begin());
        if (B.first > B.second)
            std::swap(B.first, B.second);
        l.insert(B);
    }
    ans.insert(*l.begin());
    std::cout << "YES" << std::endl
              << ans.size() << std::endl;
    for (auto i : ans)
        std::cout << i.first << ' ' << i.second << std::endl;
    return 0;
}