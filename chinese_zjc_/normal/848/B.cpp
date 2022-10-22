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
int n, w, h;
struct dancer
{
    int p, t, g;
    std::pair<int, int> ans;
} d[100005];
std::map<int, int> has;
std::map<int, std::vector<int> /**/> s;
bool cmp1(const int &A, const int &B)
{
    return (d[A].g ? -d[A].p : d[A].p) < (d[B].g ? -d[B].p : d[B].p);
}
bool cmp2(const std::pair<int, int> &A, const std::pair<int, int> &B)
{
    return A.first == B.first ? A.second > B.second : A.first < B.first;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> w >> h;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> d[i].g >> d[i].p >> d[i].t;
        --d[i].g;
        has[d[i].p - d[i].t] |= 1 << d[i].g;
        s[d[i].p - d[i].t].push_back(i);
        d[i].ans = d[i].g ? std::make_pair(w, d[i].p) : std::make_pair(d[i].p, h);
    }
    for (auto i : has)
    {
        if (i.second == 3)
        {
            std::vector<int> &now = s[i.first];
            std::sort(now.begin(), now.end(), cmp1);
            std::vector<std::pair<int, int> /**/> ans;
            for (auto j : now)
                ans.push_back(d[j].ans);
            std::sort(ans.begin(), ans.end(), cmp2);
            for (int j = 0; j != (int)ans.size(); ++j)
                d[now[j]].ans = ans[j];
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cout << d[i].ans.first << ' ' << d[i].ans.second << std::endl;
    return 0;
}