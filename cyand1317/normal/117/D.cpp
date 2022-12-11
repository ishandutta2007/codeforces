#include <cstdio>
typedef long long int64;

int64 n; int m, mod;
int64 q_l, q_r, u, v;
#define _ % mod
#define __ %= mod

int64 whole(int64 start, int64 end, int64 upper)
{
    if (upper < start) return 0;
    int64 ct = (upper - start) / end + 1;
    upper = start * 2 + (ct - 1) * end;
    if (ct % 2 == 0) ct >>= 1; else upper >>= 1;
    return ct _ * (upper _)_;
}

int64 query(int64 cur_l, int64 cur_r, int64 st_start, int64 st_end)
{
    if (cur_l >= q_l && cur_r <= q_r)
        return (whole(st_start, st_end, v) - whole(st_start, st_end, u - 1) + mod)_;
    int64 mid = (cur_l + cur_r) >> 1, ans = 0;
    if (mid >= q_l) (ans += query(cur_l, mid, st_start, st_end * 2))__;
    if (mid + 1 <= q_r) (ans += query(mid + 1, cur_r, st_start + st_end, st_end * 2))__;
    return ans;
}

int main()
{
    scanf("%I64d%d%d", &n, &m, &mod);
    do {
        scanf("%I64d%I64d%I64d%I64d", &q_l, &q_r, &u, &v);
        if (v > n) v = n;
        if (u > v) puts("0"); else printf("%I64d\n", query(1, n, 1, 1));
    } while (--m);
    return 0;
}