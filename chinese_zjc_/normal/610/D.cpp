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
int sum[100005], n, ans;
struct line
{
    int s, t, d;
    bool w;
    line() {}
    line(int s_) : s(s_) {}
    friend bool operator<(const line &A, const line &B) { return A.s < B.s; }
} a[100005];
std::vector<line> b;
std::map<int, std::vector<std::pair<int, int>>> X;
std::vector<line> Y;
std::vector<int> app;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
void add(int pos, int val)
{
    ++pos;
    while (pos <= (int)app.size())
    {
        sum[pos] += val;
        pos += pos & -pos;
    }
}
int query(int pos)
{
    int res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int sx, sy, ex, ey;
        std::cin >> sx >> sy >> ex >> ey;
        a[i].w = sx == ex;
        if (a[i].w)
        {
            a[i].s = std::min(sy, ey);
            a[i].t = std::max(sy, ey);
            a[i].d = sx;
        }
        else
        {
            a[i].s = std::min(sx, ex);
            a[i].t = std::max(sx, ex);
            a[i].d = sy;
        }
    }
    std::sort(a + 1, a + 1 + n, [&](const line &A, const line &B)
              { return A.w == B.w ? A.d == B.d ? A.s < B.s : A.d < B.d : A.w < B.w; });
    for (int i = 1; i <= n; ++i)
        if (!b.empty() && a[i].w == b.back().w && a[i].d == b.back().d && a[i].s <= b.back().t)
            b.back().t = std::max(b.back().t, a[i].t);
        else
            b.push_back(a[i]);
    for (auto i : b)
        if (i.w)
            X[i.d].push_back({i.s, i.t});
        else
            Y.push_back(i);
    for (auto i : Y)
        app.push_back(i.d);
    app.erase(std::unique(app.begin(), app.end()), app.end());
    std::sort(Y.begin(), Y.end());
    for (auto i : X)
    {
        static int lst = -INF;
        for (std::vector<line>::iterator j = std::upper_bound(Y.begin(), Y.end(), lst),
                                         lim = std::upper_bound(Y.begin(), Y.end(), i.first);
             j != lim; ++j)
        {
            int pos = std::lower_bound(app.begin(), app.end(), j->d) - app.begin();
            add(pos, 1);
            que.push({j->t, pos});
        }
        while (!que.empty() && que.top().first < i.first)
            add(que.top().second, -1), que.pop();
        for (auto j : i.second)
            ans -= query(std::upper_bound(app.begin(), app.end(), j.second) - app.begin()) -
                   query(std::lower_bound(app.begin(), app.end(), j.first) - app.begin());
        lst = i.first;
    }
    for (auto i : b)
        // std::cout << i.w << ' ' << i.s << ' ' << i.t << ' ' << i.d << std::endl;
        ans += i.t - i.s + 1;
    std::cout << ans << std::endl;
    return 0;
}