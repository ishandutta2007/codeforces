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
// #include<windows.h>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, k, len, ans;
struct point
{
    int x, y, c;
    int line, column;
} p[2005];
vector<int> line, column, color[2005];
struct node
{
    int Max, Maxsecond, val, sum;
    int lazy = INF;
    constexpr const node operator+(const node &__Val) const
    {
        return {max(Max, __Val.Max),
                Max == __Val.Max ? max(Maxsecond, __Val.Maxsecond)
                                 : max(max(Maxsecond, __Val.Maxsecond), min(Max, __Val.Max)),
                Max == __Val.Max ? val + __Val.val : Max > __Val.Max ? val : __Val.val,
                (sum + __Val.sum) % MOD};
    }
} tree[1 << 12 | 5];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid mid
#define rmid (mid + 1)
int a[2005];
void push_up(int);
void push_down(int);
void DFS(int);
void push_up(int now)
{
    tree[now] = tree[lson] + tree[rson];
}
void push_down(int now)
{
    if (tree[now].lazy == INF)
    {
        return;
    }
    tree[lson].lazy = min(tree[now].lazy, tree[lson].lazy);
    tree[rson].lazy = min(tree[now].lazy, tree[rson].lazy);
    tree[now].lazy = INF;
    DFS(lson);
    DFS(rson);
}
void DFS(int now)
{
#ifdef debug
    cout << "DFSing " << now << ' ' << tree[now].Max << ' ' << tree[now].Maxsecond << ' ' << tree[now].lazy << endl;
#endif
    if (tree[now].Max <= tree[now].lazy)
    {
        return;
    }
    if (tree[now].Maxsecond < tree[now].lazy)
    {
        (tree[now].sum -= (tree[now].Max - tree[now].lazy) % MOD * tree[now].val % MOD - MOD) %= MOD;
        tree[now].Max = tree[now].lazy;
        return;
    }
    push_down(now);
    push_up(now);
}
void build(int now = 1, int l = 1, int r = line.size() - 2)
{
    if (l == r)
    {
        tree[now] = {line[a[l]], -INF, line[l + 1] - line[l], (line[l + 1] - line[l]) * line[a[l]] % MOD};
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, lmid);
    build(rson, rmid, r);
    push_up(now);
}
int query(int L = 1, int R = line.size() - 2, int now = 1, int l = 1, int r = line.size() - 2)
{
    if (r < L || R < l)
    {
        return 0;
    }
    if (L <= l && r <= R)
    {
        return tree[now].sum % MOD;
    }
    push_down(now);
    int mid = (l + r) >> 1;
    return (query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r)) % MOD;
}
void Min(int val, int L = 1, int R = line.size() - 2, int now = 1, int l = 1, int r = line.size() - 2)
{
    if (r < L || R < l)
    {
        return;
    }
    if (L <= l && r <= R)
    // if (l == r)
    {
#ifdef debug
        cout << "DFS " << l << ' ' << r << endl;
#endif
        tree[now].lazy = min(val, tree[now].lazy);
        DFS(now);
        return;
    }
    int mid = (l + r) >> 1;
    push_down(now);
    Min(val, L, R, lson, l, lmid);
    Min(val, L, R, rson, rmid, r);
    push_up(now);
}
int tmp[2005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
template <class T>
void print(const T &A)
{
    cout << "Print";
    for (auto i : A)
    {
        cout << ' ' << i;
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k >> len;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].x >> p[i].y >> p[i].c;
        ++p[i].x;
        ++p[i].y;
        line.push_back(p[i].x);
        column.push_back(p[i].y);
    }
    line.push_back(0);
    column.push_back(0);
    line.push_back(len + 1);
    column.push_back(len + 1);
    sort(line.begin(), line.end());
    sort(column.begin(), column.end());
    line.erase(unique(line.begin(), line.end()), line.end());
    column.erase(unique(column.begin(), column.end()), column.end());
    for (int i = 1; i <= n; ++i)
    {
        p[i].line = find(line.begin(), line.end(), p[i].x) - line.begin();
        p[i].column = find(column.begin(), column.end(), p[i].y) - column.begin();
    }
    for (int Llimit = 1; Llimit <= column.size() - 2; ++Llimit)
    {
        for (int i = 1; i <= k; ++i)
        {
            color[i].clear();
            color[i].push_back(0);
            color[i].push_back(n + 1);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (p[i].column >= Llimit)
            {
                color[p[i].c].push_back(i);
            }
            else
            {
                swap(p[i], p[n]);
                --n;
                --i;
            }
        }
        p[n + 1].line = line.size() - 1;
#ifdef debug
        for (int i = 1; i <= n; ++i)
        {
            cout << __LINE__ << ":" << p[i].x << ' ' << p[i].y << ' ' << p[i].c << endl;
        }
#endif
        for (int i = 1; i <= k; ++i)
        {
            sort(color[i].begin(), color[i].end(), [&](const int &A, const int &B) { return p[A].line < p[B].line; });
#ifdef debug
            print(color[i]);
#endif
        }
        memset(tmp, 0, sizeof(tmp));
        while (!que.empty())
        {
            que.pop();
        }
        for (int i = 1; i <= k; ++i)
        {
            que.push({tmp[i], i});
        }
        vector<int> order;
        for (int i = 1; i <= n; ++i)
        {
            order.push_back(i);
        }
        sort(order.begin(), order.end(), [&](const int &A, const int &B) { return p[A].line < p[B].line; });
        vector<int>::iterator now = order.begin();
        for (int i = 1; i <= line.size() - 2; ++i)
        {
            while (now != order.end() && p[*now].line <= i)
            {
                que.push({tmp[p[*now].c] = p[*now].line, p[*now].c});
                ++now;
            }
            while (!que.empty() && tmp[que.top().second] != que.top().first)
            {
                que.pop();
            }
            a[i] = que.top().first;
        }
        build();
#ifdef debug
        for (int i = 1; i <= 2 * line.size(); ++i)
        {
            cout << tree[i].val << ' ';
        }
        cout << endl;
#endif
        sort(order.begin(), order.end(), [&](const int &A, const int &B) { return p[A].column > p[B].column; });
        now = order.begin();
        for (int Rlimit = column.size() - 2; Rlimit >= Llimit; --Rlimit)
        {
#ifdef debug
            for (int i = 1; i <= line.size() - 2; ++i)
            {
                cout << query(i, i) << ' ';
            }
            cout << endl;
#endif
            (ans += query() *
                    (column[Rlimit + 1] - column[Rlimit]) % MOD *
                    (column[Llimit] - column[Llimit - 1]) % MOD) %= MOD;
#ifdef debug
            cout << ans << endl;
#endif
            while (now != order.end() && p[*now].column >= Rlimit)
            {
                vector<int>::iterator it = find(color[p[*now].c].begin(), color[p[*now].c].end(), *now);
                Min(p[*(it - 1)].x, p[*it].line, p[*(it + 1)].line - 1);
#ifdef debug
                cout << __LINE__ << ' ' << *now << ':' << p[*(it - 1)].x << ' ' << p[*it].line << ' ' << p[*(it + 1)].line - 1 << endl;
#endif
                color[p[*now].c].erase(it);
                ++now;
            }
        }
    }
    cout << ans << endl;
    return 0;
}