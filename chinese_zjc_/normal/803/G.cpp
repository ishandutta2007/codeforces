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
int rmq[20][100005], min, lg[100005], n, k, q, opt[100005], l[100005], r[100005], x[100005];
std::vector<int> num;
int RMQ(int l, int len)
{
    if (len >= n)
        return min;
    int g = lg[len];
    return std::min(rmq[g][l], rmq[g][(l + len - (1 << g)) % n]);
}
struct node
{
    int min, tag;
} t[1 << 19];
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
void pushup(int now)
{
    t[now].min = std::min(t[lson].min, t[rson].min);
}
void pushdown(int now)
{
    if (t[now].tag)
    {
        t[lson].min = t[rson].min = t[lson].tag = t[rson].tag = t[now].tag;
        t[now].tag = 0;
    }
}
void build(int now = 1, int l = 0, int r = num.size() - 1)
{
    if (r - l == 1)
    {
        t[now].min = RMQ(num[l] % n, num[r] - num[l]);
        return;
    }
    build(lson, l, mid);
    build(rson, mid, r);
    pushup(now);
}
void modify(int L, int R, int val, int now = 1, int l = 0, int r = num.size() - 1)
{
    if (R <= l || r <= L)
        return;
    if (L <= l && r <= R)
    {
        t[now].min = t[now].tag = val;
        return;
    }
    pushdown(now);
    modify(L, R, val, lson, l, mid);
    modify(L, R, val, rson, mid, r);
    pushup(now);
}
int query(int L, int R, int now = 1, int l = 0, int r = num.size() - 1)
{
    if (R <= l || r <= L)
        return INF;
    if (L <= l && r <= R)
        return t[now].min;
    pushdown(now);
    return std::min(query(L, R, lson, l, mid), query(L, R, rson, mid, r));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 0; i != n; ++i)
        std::cin >> rmq[0][i];
    min = *std::min_element(rmq[0], rmq[0] + n);
    for (int i = 1; 1 << i <= n; ++i)
        for (int j = 0; j != n; ++j)
            rmq[i][j] = std::min(rmq[i - 1][j], rmq[i - 1][(j + (1 << i >> 1)) % n]);
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i - 1] + !(i & (i - 1));
    std::cin >> q;
    num.push_back(0);
    num.push_back(n * k);
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> opt[i] >> l[i] >> r[i];
        if (opt[i] == 1)
            std::cin >> x[i];
        --l[i];
        num.push_back(l[i]);
        num.push_back(r[i]);
    }
    std::sort(num.begin(), num.end());
    num.erase(std::unique(num.begin(), num.end()), num.end());
    build();
    // for (auto i : num)
    //     std::cout << i << ' ';
    // std::cout << std::endl;
    for (int i = 1; i <= q; ++i)
    {
        // std::cout << "!!! " << l[i] << ' ' << r[i] << std::endl;
        l[i] = std::lower_bound(num.begin(), num.end(), l[i]) - num.begin();
        r[i] = std::lower_bound(num.begin(), num.end(), r[i]) - num.begin();
        // std::cout << "!!! " << l[i] << ' ' << r[i] << std::endl;
        switch (opt[i])
        {
        case 1:
            modify(l[i], r[i], x[i]);
            break;
        case 2:
            std::cout << query(l[i], r[i]) << std::endl;
            break;
        }
    }
    return 0;
}