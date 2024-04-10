// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const long long INF = LLONG_MAX >> 32;
int n, a[150005], b[150005], ans[150005], sum[150005];
void cmin(int &A, const int &B) { A = std::min(A, B); }
void add(int pos, int val)
{
    while (pos <= n)
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
struct Segment_Tree_Beats
{
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    struct node
    {
        int sum, max, num1, sec, num2;
    } t[1 << 19];
    int lazymin[1 << 19], lazyadd[1 << 19];
    void pushup(int now)
    {
        t[now].sum = t[lson].sum + t[rson].sum;
        if (t[lson].max < t[rson].max)
        {
            t[now].max = t[rson].max;
            t[now].num1 = t[rson].num1;
            t[now].sec = std::max(t[lson].max, t[rson].sec);
            t[now].num2 = t[lson].num2 + t[rson].num2;
        }
        else if (t[lson].max > t[rson].max)
        {
            t[now].max = t[lson].max;
            t[now].num1 = t[lson].num1;
            t[now].sec = std::max(t[lson].sec, t[rson].max);
            t[now].num2 = t[lson].num2 + t[rson].num2;
        }
        else
        {
            t[now].max = t[lson].max;
            t[now].num1 = t[lson].num1 + t[rson].num1;
            t[now].sec = std::max(t[lson].sec, t[rson].sec);
            t[now].num2 = t[lson].num2 + t[rson].num2;
        }
    }
    void pushdown(int now, int l, int r)
    {
        if (lazyadd[now])
        {
            t[lson].sum += t[lson].num2 * lazyadd[now];
            t[rson].sum += t[rson].num2 * lazyadd[now];
            if (t[lson].num1)
                t[lson].max += lazyadd[now];
            if (t[rson].num1)
                t[rson].max += lazyadd[now];
            if (t[lson].num2 - t[lson].num1)
                t[lson].sec += lazyadd[now];
            if (t[rson].num2 - t[rson].num1)
                t[rson].sec += lazyadd[now];
            lazyadd[lson] += lazyadd[now];
            lazyadd[rson] += lazyadd[now];
            lazymin[lson] += lazyadd[now];
            lazymin[rson] += lazyadd[now];
            lazyadd[now] = 0;
        }
        if (lazymin[now] < INF)
        {
            min(l, r, lazymin[now], lson, l, lmid);
            min(l, r, lazymin[now], rson, rmid, r);
            lazymin[now] = INF;
        }
    }
    void build(int now = 1, int l = 1, int r = n)
    {
        lazymin[now] = INF;
        if (l == r)
        {
            t[now].sum = 0;
            t[now].max = 0;
            t[now].num1 = 0;
            t[now].sec = -INF;
            t[now].num2 = 0;
            return;
        }
        build(lson, l, lmid);
        build(rson, rmid, r);
        pushup(now);
    }
    void min(int L, int R, int val, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return;
        if (!(L <= l && r <= R) || val <= t[now].sec)
            return pushdown(now, l, r), min(L, R, val, lson, l, lmid), min(L, R, val, rson, rmid, r), pushup(now);
        if (val < t[now].max)
            return t[now].sum -= (t[now].max - val) * t[now].num1, t[now].max = val, cmin(lazymin[now], val);
    }
    void add(int L, int R, int val, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
        {
            t[now].sum += t[now].num2 * val;
            if (t[now].num1)
                t[now].max += val;
            if (t[now].num2 - t[now].num1)
                t[now].sec += val;
            lazyadd[now] += val;
            lazymin[now] += val;
            return;
        }
        pushdown(now, l, r);
        add(L, R, val, lson, l, lmid);
        add(L, R, val, rson, rmid, r);
    }
    void fill(int pos, int val, int now = 1, int l = 1, int r = n)
    {
        if (l == r)
            return t[now].sum = t[now].max = val, t[now].sec = -INF, void(t[now].num2 = t[now].num1 = 1);
        pushdown(now, l, r);
        pos <= lmid ? fill(pos, val, lson, l, lmid) : fill(pos, val, rson, rmid, r);
        pushup(now);
    }
    int sum(int L = 1, int R = n, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return 0;
        if (L <= l && r <= R)
            return t[now].sum;
        pushdown(now, l, r);
        return sum(L, R, lson, l, lmid) + sum(L, R, rson, rmid, r);
    }
    int cnt(int L = 1, int R = n, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return 0;
        if (L <= l && r <= R)
            return t[now].num2;
        pushdown(now, l, r);
        return cnt(L, R, lson, l, lmid) + cnt(L, R, rson, rmid, r);
    }
#undef lson
#undef rson
#undef lmid
#undef rmid
} T;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        b[a[i]] = i;
    T.build();
    for (int i = 1; i <= n; ++i)
    {
        T.add(b[i], n, 1);
        T.min(1, b[i], T.cnt(1, b[i]));
        T.fill(b[i], i);
        ans[i] += T.sum();
        // for (int j = 1; j <= n; ++j)
        //     std::cout << T.sum(j, j) << " \n"[j == n];
        // std::cout << std::flush;
    }
    std::reverse(a + 1, a + 1 + n);
    // for (int i = 1; i <= n; ++i)
    //     std::cout << a[i] << " \n"[i == n];
    for (int i = 1; i <= n; ++i)
        b[a[i]] = i;
    T.build();
    for (int i = 1; i <= n; ++i)
    {
        T.add(b[i], n, 1);
        T.min(1, b[i], T.cnt(1, b[i]));
        T.fill(b[i], i);
        ans[i] += T.sum();
        // for (int j = 1; j <= n; ++j)
        //     std::cout << T.sum(j, j) << " \n"[j == n];
        // std::cout << std::flush;
    }
    for (int i = 1; i <= n; ++i)
        std::cout << (ans[i] -= i * i) << std::endl;
    return 0;
}