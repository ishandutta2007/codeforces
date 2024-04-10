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
int n, m, a[755], b[200005];
// struct segmenttree
// {
//     struct node
//     {
//         int min, add;
//     } t[1 << 11];
// #define lson (now << 1)
// #define rson (lson | 1)
// #define lmid ((l + r) >> 1)
// #define rmid (lmid + 1)
//     void pushdown(int now)
//     {
//         if (t[now].add)
//         {
//             t[lson].min += t[now].add;
//             t[rson].min += t[now].add;
//             t[lson].add += t[now].add;
//             t[rson].add += t[now].add;
//             t[now].add = 0;
//         }
//     }
//     void pushup(int now)
//     {
//         t[now].min = std::min(t[lson].min, t[rson].min);
//     }
//     template <class Function>
//     void build(Function F, int now = 1, int l = 1, int r = n)
//     {
//         t[now].add = 0;
//         if (l == r)
//         {
//             t[now].min = F(l);
//             return;
//         }
//         build(F, lson, l, lmid);
//         build(F, rson, rmid, r);
//         pushup(now);
//     }
//     void add(int L, int R, int val, int now = 1, int l = 1, int r = n)
//     {
//         if (R < l || r < L)
//             return;
//         if (L <= l && r <= R)
//         {
//             t[now].min += val;
//             t[now].add += val;
//             return;
//         }
//         pushdown(now);
//         add(L, R, val, lson, l, lmid);
//         add(L, R, val, rson, rmid, r);
//         pushup(now);
//     }
//     int min(int L, int R, int now = 1, int l = 1, int r = n)
//     {
//         if (R < l || r < L)
//             return INF;
//         if (L <= l && r <= R)
//             return t[now].min;
//         pushdown(now);
//         return std::min(min(L, R, lson, l, lmid), min(L, R, rson, rmid, r));
//     }
// #undef lson
// #undef rson
// #undef lmid
// #undef rmid
// } sum, c;
std::vector<int> ans;
int check(int now)
{
    std::priority_queue<int> que;
    int sum = now, cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i], que.push(-a[i]);
        while (sum < 0)
        {
            sum += que.top();
            ++cnt;
            que.pop();
        }
    }
    return cnt;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 0; i <= n; ++i)
    {
        int l = 0, r = INF;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid) <= i)
                r = mid;
            else
                l = mid + 1;
        }
        ans.push_back(l);
    }
    for (int i = 1; i <= m; ++i)
    {
        static int x;
        std::cin >> x;
        std::cout << std::lower_bound(ans.begin(), ans.end(), x, std::greater<int>()) - ans.begin() << std::endl;
    }
    return 0;
}