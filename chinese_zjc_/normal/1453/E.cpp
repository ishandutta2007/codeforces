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
std::vector<int> son[200005];
int T, n, l, r, fa[200005];
void init(int now)
{
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        init(son[now][i]);
    }
}
int dfs(int now, int k)
{
    if (son[now].empty())
        return 0;
    std::vector<int> s;
    for (int i = 0; i != (int)son[now].size(); ++i)
        s.push_back(dfs(son[now][i], k) + 1);
    std::sort(s.begin(), s.end());
    // std::cout << now << ":";
    // for (auto i : s)
    //     std::cout << " " << i;
    // std::cout << std::endl;
    int l = 0, r = s.size() - 1;
    for (int i = 1; i != (int)son[now].size(); ++i)
        if (s[r] + 1 <= k)
            --r;
        else if (s[l] + 1 <= k)
            ++l;
        else
            return INF;
    return s[l];
}
bool check(int now)
{
    return dfs(1, now) <= now;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            fa[i] = 0, son[i].clear();
        for (int i = 1; i < n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            son[x].push_back(y);
            son[y].push_back(x);
        }
        init(1);
        l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}