// This Code was made by Chinese_zjc_.
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
// #define debug
const int INF = INT_MAX >> 1;
int n, m, N;
char a[200005];
struct node
{
    int rad, lau, lcha, rcha, ad, au, cha, ans;
} t[1 << 19];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    t[now].rad = std::max(t[lson].rad + t[rson].ad, t[rson].rad);
    t[now].lau = std::max(t[lson].lau, t[lson].au + t[rson].lau);
    t[now].lcha = std::max(t[lson].lcha, std::max(t[lson].cha + t[rson].lau, t[lson].ad + t[rson].lcha));
    t[now].rcha = std::max(t[rson].rcha, std::max(t[lson].rad + t[rson].cha, t[lson].rcha + t[rson].au));
    t[now].ad = t[lson].ad + t[rson].ad;
    t[now].au = t[lson].au + t[rson].au;
    t[now].cha = std::max(t[lson].cha + t[rson].au, t[lson].ad + t[rson].cha);
    t[now].ans = std::max(std::max(t[lson].ans, t[rson].ans),
                          std::max(t[lson].rcha + t[rson].lau, t[lson].rad + t[rson].lcha));
}
void build(int now = 1, int l = 1, int r = N)
{
    if (l == r)
    {
        t[now].rad = a[l] == ')';
        t[now].lau = a[l] == '(';
        t[now].lcha = 1;
        t[now].rcha = 1;
        t[now].ad = a[l] == ')' ? +1 : -1;
        t[now].au = a[l] == '(' ? +1 : -1;
        t[now].cha = 1;
        t[now].ans = 1;
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void update(int pos, int now = 1, int l = 1, int r = N)
{
    if (l == r)
    {
        t[now].rad = a[l] == ')';
        t[now].lau = a[l] == '(';
        t[now].lcha = 1;
        t[now].rcha = 1;
        t[now].ad = a[l] == ')' ? +1 : -1;
        t[now].au = a[l] == '(' ? +1 : -1;
        t[now].cha = 1;
        t[now].ans = 1;
        return;
    }
    if (pos <= lmid)
        update(pos, lson, l, lmid);
    if (pos >= rmid)
        update(pos, rson, rmid, r);
    pushup(now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    N = (n - 1) * 2;
    for (int i = 1; i <= N; ++i)
        std::cin >> a[i];
    build();
    std::cout << t[1].ans << std::endl;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        std::swap(a[x], a[y]);
        update(x);
        update(y);
        std::cout << t[1].ans << std::endl;
    }
    return 0;
}