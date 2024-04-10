// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, tota, totb, totc;
char a[100005];
int cnt[1 << 18][3], ab[1 << 18], bc[1 << 18], abc[1 << 18];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    cnt[now][0] = cnt[lson][0] + cnt[rson][0];
    cnt[now][1] = cnt[lson][1] + cnt[rson][1];
    cnt[now][2] = cnt[lson][2] + cnt[rson][2];
    ab[now] = std::min(ab[lson] + cnt[rson][1], cnt[lson][0] + ab[rson]);
    bc[now] = std::min(bc[lson] + cnt[rson][2], cnt[lson][1] + bc[rson]);
    abc[now] = std::min(std::min(abc[lson] + cnt[rson][2], cnt[lson][0] + abc[rson]), ab[lson] + bc[rson]);
}
void modify(int pos, char val, int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        cnt[now][0] = cnt[now][1] = cnt[now][2] = 0;
        cnt[now][val - 'a'] = 1;
        return;
    }
    if (pos <= lmid)
        modify(pos, val, lson, l, lmid);
    else
        modify(pos, val, rson, rmid, r);
    pushup(now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        modify(i, a[i]);
    }
    for (int i = 1; i <= q; ++i)
    {
        static int x;
        static char y;
        std::cin >> x >> y;
        modify(x, y);
        std::cout << abc[1] << std::endl;
    }
    return 0;
}