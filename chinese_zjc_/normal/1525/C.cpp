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
int n, m, T, x[300005], ans[300005], to[300005];
char c[300005];
std::vector<std::pair<int, int>> sta[2];
struct node
{
    int x;
    char c;
    int p;
    bool operator<(const node &val) const { return x < val.x; }
} a[300005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        memset(ans, -1, sizeof(ans));
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i].x;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i].c;
        for (int i = 1; i <= n; ++i)
            a[i].p = i;
        std::sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; ++i)
        {
            x[i] = a[i].x;
            c[i] = a[i].c;
            to[a[i].p] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            bool s = x[i] & 1;
            if (c[i] == 'L')
            {
                if (sta[s].empty())
                {
                    sta[s].push_back(std::make_pair(i, -x[i]));
                }
                else
                {
                    ans[sta[s].back().first] = ans[i] = (x[i] - sta[s].back().second) / 2;
                    sta[s].pop_back();
                }
            }
            if (c[i] == 'R')
            {
                sta[s].push_back(std::make_pair(i, x[i]));
            }
        }
        for (int i = 0; i != 2; ++i)
        {
            while (sta[i].size())
            {
                std::pair<int, int> now = sta[i].back();
                sta[i].pop_back();
                if (sta[i].size())
                {
                    std::pair<int, int> t = sta[i].back();
                    sta[i].pop_back();
                    ans[now.first] = ans[t.first] = ((m + m - now.second) - t.second) / 2;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            std::cout << ans[to[i]] << " \n"[i == n];
    }
    return 0;
}