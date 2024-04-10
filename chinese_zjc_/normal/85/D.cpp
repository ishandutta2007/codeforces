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
#define mid ((l + r) >> 1)
#define lson (now << 1)
#define rson (lson | 1)
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
std::vector<int> app;
int n, x[100005];
std::string s[100005];
struct node
{
    int sum[5], cnt, move;
} t[1 << 18];
void pmove(int now, int v)
{
    int tmp[5];
    std::swap(tmp, t[now].sum);
    for (int i = 0; i != 5; ++i)
        t[now].sum[(i + v) % 5] = tmp[i];
}
void pushup(int now)
{
    for (int i = 0; i != 5; ++i)
        t[now].sum[i] = t[lson].sum[i] + t[rson].sum[i];
    t[now].cnt = t[lson].cnt + t[rson].cnt;
}
void pushdown(int now)
{
    if (t[now].move)
    {
        // std::cout << "???" << std::endl;
        pmove(lson, t[now].move);
        pmove(rson, t[now].move);
        t[lson].move += t[now].move;
        t[rson].move += t[now].move;
        t[now].move = 0;
    }
}
void add(int pos, int mod, int val, int now = 1, int l = 0, int r = app.size())
{
    if (r - l == 1)
    {
        t[now].cnt += val;
        t[now].sum[mod] += val * app[l];
        // std::cout << pos << ' ' << mod << ' ' << app[l] << std::endl;
        return;
    }
    pushdown(now);
    if (pos < mid)
        add(pos, mod, val, lson, l, mid);
    else
        add(pos, mod, val, rson, mid, r);
    pushup(now);
}
int sum(int L, int R, int x, int now = 1, int l = 0, int r = app.size())
{
    if (R <= l || r <= L)
        return 0;
    if (L <= l && r <= R)
        return ~x ? t[now].sum[x] : t[now].cnt;
    pushdown(now);
    return sum(L, R, x, lson, l, mid) + sum(L, R, x, rson, mid, r);
}
void move(int L, int R, int v, int now = 1, int l = 0, int r = app.size())
{
    if (R <= l || r <= L)
        return;
    if (L <= l && r <= R)
    {
        t[now].move += v;
        pmove(now, v);
        return;
    }
    pushdown(now);
    move(L, R, v, lson, l, mid);
    move(L, R, v, rson, mid, r);
    pushup(now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> s[i];
        if (s[i] != "sum")
            std::cin >> x[i];
    }
    for (int i = 0; i != n; ++i)
        if (s[i] == "add")
            app.push_back(x[i]);
    std::sort(app.begin(), app.end());
    app.erase(std::unique(app.begin(), app.end()), app.end());
    for (int i = 0; i != n; ++i)
        if (s[i] == "add")
        {
            int pos = std::lower_bound(app.begin(), app.end(), x[i]) - app.begin();
            move(pos, app.size(), 1);
            add(pos, sum(0, pos, -1) % 5, +1);
        }
        else if (s[i] == "del")
        {
            int pos = std::lower_bound(app.begin(), app.end(), x[i]) - app.begin();
            add(pos, sum(0, pos, -1) % 5, -1);
            move(pos, app.size(), 4);
        }
        else if (s[i] == "sum")
        {
            // std::cout << sum(0, app.size(), 0) << std::endl;
            // std::cout << sum(0, app.size(), 1) << std::endl;
            std::cout << sum(0, app.size(), 2) << std::endl;
            // std::cout << sum(0, app.size(), 3) << std::endl;
            // std::cout << sum(0, app.size(), 4) << std::endl;
        }
    return 0;
}