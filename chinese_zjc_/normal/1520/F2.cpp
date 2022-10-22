// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int sum[1 << 19], n, t, k;
int query(int l, int r)
{
    std::cout << "? " << l << ' ' << r << std::endl;
    int res;
    std::cin >> res;
    return r - l + 1 - res;
}
void answer(int pos) { std::cout << "! " << pos << std::endl; }
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
bool work(int now = 1, int l = 1, int r = n)
{
    if (!~sum[now])
        sum[now] = query(l, r);
    if (sum[now] <= k)
    {
        k -= sum[now];
        return false;
    }
    if (l == r)
    {
        answer(l);
        for (int i = now; i; i >>= 1)
            --sum[i];
        return true;
    }
    if (!work(lson, l, lmid))
    {
        sum[rson] = sum[now] - sum[lson];
        work(rson, rmid, r);
    }
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> t;
    memset(sum, -1, sizeof(sum));
    while (t--)
    {
        std::cin >> k;
        --k;
        work();
    }
    return 0;
}