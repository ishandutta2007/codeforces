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
enum lazytag
{
    rev,
    fill,
    clear,
    none
};
lazytag &operator+=(lazytag &A, const lazytag &B)
{
    switch (B)
    {
    case rev:
        switch (A)
        {
        case rev:
            A = none;
            break;
        case fill:
            A = clear;
            break;
        case clear:
            A = fill;
            break;
        case none:
            A = rev;
            break;
        }
        break;
    case fill:
        A = fill;
        break;
    case clear:
        A = clear;
        break;
    case none:
        break;
    }
    return A;
}
struct node
{
    int cnt[2];
    lazytag tag;
    node &operator+=(const lazytag &val)
    {
        switch (val)
        {
        case rev:
            std::swap(cnt[0], cnt[1]);
            break;
        case fill:
            cnt[1] += cnt[0];
            cnt[0] = 0;
            break;
        case clear:
            cnt[0] += cnt[1];
            cnt[1] = 0;
            break;
        case none:
            break;
        }
        tag += val;
        return *this;
    }
} t[1 << 19];
int n, opt[100005], l[100005], r[100005];
std::vector<int> num;
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
void pushup(int now)
{
    t[now].cnt[0] = t[lson].cnt[0] + t[rson].cnt[0];
    t[now].cnt[1] = t[lson].cnt[1] + t[rson].cnt[1];
}
void pushdown(int now)
{
    t[lson] += t[now].tag;
    t[rson] += t[now].tag;
    t[now].tag = none;
}
void build(int now = 1, int l = 0, int r = num.size() - 1)
{
    if (r - l == 1)
    {
        t[now].cnt[0] = 1;
        t[now].cnt[1] = 0;
        return;
    }
    t[now].tag = none;
    build(lson, l, mid);
    build(rson, mid, r);
    pushup(now);
}
void modfiy(int L, int R, lazytag val, int now = 1, int l = 0, int r = num.size() - 1)
{
    if (R <= l || r <= L)
        return;
    if (L <= l && r <= R)
    {
        t[now] += val;
        return;
    }
    pushdown(now);
    modfiy(L, R, val, lson, l, mid);
    modfiy(L, R, val, rson, mid, r);
    pushup(now);
}
int work(int now = 1, int l = 0, int r = num.size() - 1)
{
    if (r - l == 1)
        return l;
    pushdown(now);
    if (t[lson].cnt[0])
        return work(lson, l, mid);
    else
        return work(rson, mid, r);
}
int query(int L, int R, int now = 1, int l = 0, int r = num.size() - 1)
{
    if (R <= l || r <= L)
        return 0;
    if (L <= l && r <= R)
        return t[now].cnt[1];
    pushdown(now);
    return query(L, R, lson, l, mid) + query(L, R, rson, mid, r);
}
#undef lson
#undef rson
#undef mid
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> opt[i] >> l[i] >> r[i];
        ++r[i];
        num.push_back(l[i]);
        num.push_back(r[i]);
    }
    num.push_back(1);
    num.push_back(INF);
    std::sort(num.begin(), num.end());
    num.erase(std::unique(num.begin(), num.end()), num.end());
    build();
    // for (int j = 0; j != (int)num.size() - 1; ++j)
    //     std::cout << query(j, j + 1) << " ";
    // std::cout << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        l[i] = std::lower_bound(num.begin(), num.end(), l[i]) - num.begin();
        r[i] = std::lower_bound(num.begin(), num.end(), r[i]) - num.begin();
        // for (auto i : num)
        //     std::cout << i << ' ';
        // std::cout << std::endl;
        // std::cout << l[i] << ' ' << r[i] << std::endl;
        switch (opt[i])
        {
        case 1:
            modfiy(l[i], r[i], fill);
            break;
        case 2:
            modfiy(l[i], r[i], clear);
            break;
        case 3:
            modfiy(l[i], r[i], rev);
            break;
        }
        std::cout << num[work()] << std::endl;
        // for (int j = 0; j != (int)num.size() - 1; ++j)
        //     std::cout << query(j, j + 1) << " ";
        // std::cout << std::endl;
    }
    return 0;
}