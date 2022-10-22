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
int n, t[300005];
std::vector<std::pair<int, int>> sta;
struct ANS
{
    int a, b, l;
};
struct node
{
    int x, p;
} s[300005];
std::vector<ANS> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i].x, s[i].p = i;
    std::sort(s + 1, s + 1 + n, [&](const node &A, const node &B)
              { return A.x < B.x; });
    for (int i = 1; i <= n; ++i)
        std::cin >> t[i];
    std::sort(t + 1, t + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        int v = t[i] - s[i].x;
        if (v < 0)
        {
            v = -v;
            while (!sta.empty())
            {
                if (sta.back().second > v)
                {
                    ans.push_back({sta.back().first, s[i].p, v});
                    sta.back().second -= v;
                    v = 0;
                    break;
                }
                else if (sta.back().second < v)
                {
                    ans.push_back({sta.back().first, s[i].p, sta.back().second});
                    v -= sta.back().second;
                    sta.pop_back();
                }
                else
                {
                    ans.push_back({sta.back().first, s[i].p, v});
                    sta.pop_back();
                    v = 0;
                    break;
                }
            }
            if (v)
                return std::cout << "NO" << std::endl, 0;
        }
        if (v > 0)
            sta.push_back({s[i].p, v});
    }
    if (!sta.empty())
        return std::cout << "NO" << std::endl, 0;
    std::cout << "YES" << std::endl
              << ans.size() << std::endl;
    for (auto i : ans)
        std::cout << i.a << ' ' << i.b << ' ' << i.l << std::endl;
    return 0;
}