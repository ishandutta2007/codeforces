// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, cnt, root, del;
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
struct node
{
    int lson, rson, sum;
} g[40000005];
void pushup(int now) { g[now].sum = g[g[now].lson].sum + g[g[now].rson].sum; }
void set(int pos, int &now = root, int l = -400000, int r = 1000400002)
{
    if (!now)
        now = ++cnt;
    if (l == r)
    {
        g[now].sum = 1;
        return;
    }
    pos <= lmid ? set(pos, g[now].lson, l, lmid) : set(pos, g[now].rson, rmid, r);
    pushup(now);
}
int search(int val, int &now = root, int l = -400000, int r = 1000400002)
{
    if (!now)
    {
        // assert(l + val - 1 <= r);
        return l + val - 1;
    }
    if (val <= lmid - l + 1 - g[g[now].lson].sum)
        return search(val, g[now].lson, l, lmid);
    else
        return search(val - (lmid - l + 1 - g[g[now].lson].sum), g[now].rson, rmid, r);
}
int query(int pos, int &now = root, int l = -400000, int r = 1000400002)
{
    if (pos < l)
        return 0;
    if (r <= pos)
        return r - l + 1 - g[now].sum;
    return query(pos, g[now].lson, l, lmid) + query(pos, g[now].rson, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    del = -400001;
    for (int i = 1, ans = 0, x, t, k; i <= n; ++i)
    {
        std::cin >> t >> k;
        if (t - del <= 0)
            del -= 2;
        else
        {
            set(search(t - del));
            set(search(t - del));
        }
        ++del;
        while (k--)
        {
            std::cin >> x;
            x = (x + ans) % 1000000001;
            std::cout << (ans = del + query(x)) << std::endl;
        }
        // for (int j = 0; j <= 10; ++j)
        //     std::cout << del + query(j) <<l " \n"[j == 10];
    }
    return 0;
}