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
int n, m, fa[400005], depth[400005], fe[400005];
std::vector<std::pair<int, int> /**/> son[400005];
std::vector<std::pair<int, int> /**/> ans;
std::map<std::pair<int, int>, int> map;
std::pair<int, int> work(int A, int B, int C, int D)
{
    std::pair<int, int> ans = std::make_pair(A * D, C * B);
    int gcd = std::__gcd(ans.first, ans.second);
    return std::make_pair(ans.first / gcd, ans.second / gcd);
}
void dfs(int now)
{
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (depth[son[now][i].first])
            continue;
        fa[son[now][i].first] = now;
        fe[son[now][i].first] = son[now][i].second;
        depth[son[now][i].first] = depth[now] + 1;
        dfs(son[now][i].first);
    }
}
bool work(int now)
{
    int tmp = 0;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (depth[son[now][i].first] >= depth[now] + 1 && fe[son[now][i].first] != son[now][i].second)
        {
            if (tmp)
            {
                ans.push_back(std::make_pair(tmp, son[now][i].second));
                tmp = 0;
            }
            else
            {
                tmp = son[now][i].second;
            }
        }
        if (fe[son[now][i].first] == son[now][i].second)
        {
            if (work(son[now][i].first))
            {
                if (tmp)
                {
                    ans.push_back(std::make_pair(tmp, son[now][i].second));
                    tmp = 0;
                }
                else
                {
                    tmp = son[now][i].second;
                }
            }
        }
    }
    if (tmp && fe[now])
    {
        ans.push_back(std::make_pair(tmp, fe[now]));
        return false;
    }
    else
    {
        return true;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int A = map.insert(std::make_pair(work(a + b, b, c, d), map.size() + 1)).first->second;
        int B = map.insert(std::make_pair(work(a, b, c + d, d), map.size() + 1)).first->second;
        son[A].push_back(std::make_pair(B, i));
        son[B].push_back(std::make_pair(A, i));
    }
    m = map.size();
    for (int i = 1; i <= m; ++i)
        if (!fa[i])
        {
            depth[i] = 1;
            dfs(i);
            work(i);
        }
    std::cout << ans.size() << std::endl;
    for (int i = 0; i != (int)ans.size(); ++i)
        std::cout << ans[i].first << ' ' << ans[i].second << std::endl;
    return 0;
}