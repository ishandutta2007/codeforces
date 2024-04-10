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
int T, n, dfn[300005], idfn[300005], siz[300005], tim, faa[300005], fab[300005], ans;
struct cmp
{
    bool operator()(const int &A, const int &B) const { return idfn[A] < idfn[B]; }
};
std::set<int, cmp> s;
std::vector<int> sona[300005], sonb[300005];
void initb(int now)
{
    siz[now] = 1;
    dfn[idfn[now] = ++tim] = now;
    for (auto i : sonb[now])
        initb(i), siz[now] += siz[i];
}
void dfs(int now)
{
    std::set<int, cmp>::iterator lst = s.insert(now).first;
    int tmp = -1;
    if (lst != s.begin())
    {
        --lst;
        if (idfn[now] < idfn[*lst] + siz[*lst])
        {
            tmp = *lst;
            s.erase(lst);
        }
    }
    if (sona[now].empty())
        ans = std::max(ans, (int)s.size());
    else
        for (auto i : sona[now])
            dfs(i);
    if (~tmp)
        s.insert(tmp);
    s.erase(now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        std::cin >> n;
        sona[1].clear();
        for (int i = 2; i <= n; ++i)
            std::cin >> faa[i], sona[faa[i]].push_back(i), sona[i].clear();
        sonb[1].clear();
        for (int i = 2; i <= n; ++i)
            std::cin >> fab[i], sonb[fab[i]].push_back(i), sonb[i].clear();
        tim = 0;
        initb(1);
        dfs(1);
        std::cout << ans << std::endl;
    }
    return 0;
}