#include <cstdio>
#include <algorithm>
#include <utility>

typedef long long int64;
static const int MAXN = 100005;
static const int BSZ = 512;
static const int BCT = 400;
static const int MAXVAL = 2e6 + 3;

int n, m, k;
int p[MAXN], ai;
struct query {
    int id, l, r, bid;
    int64 ans;
} q[MAXN];
inline bool query_cmp_rearrange(const query &lhs, const query &rhs) {
    return (lhs.bid == rhs.bid) ? (lhs.r < rhs.r) : (lhs.bid < rhs.bid);
}
inline bool query_cmp_recover(const query &lhs, const query &rhs) {
    return lhs.id < rhs.id;
}

int64 ans = 0;
int ct[MAXVAL] = { 0 };
inline void update(int pos, int mul = +1) {
    ans -= (k == 0 ? (int64)ct[p[pos]] * (ct[p[pos]] - 1) / 2 : (int64)ct[p[pos]] * ct[p[pos] ^ k]);
    ct[p[pos]] += mul;
    ans += (k == 0 ? (int64)ct[p[pos]] * (ct[p[pos]] - 1) / 2 : (int64)ct[p[pos]] * ct[p[pos] ^ k]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    p[0] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ai);
        p[i + 1] = p[i] ^ ai;
    }
    for (int i = 0; i < m; ++i) {
        q[i].id = i;
        scanf("%d%d", &q[i].l, &q[i].r); --q[i].l;
        q[i].bid = q[i].l / BSZ;
    }
    std::sort(q, q + m, query_cmp_rearrange);

    int l = 1, r = 0;   // Current range: [l, r]
    for (int i = 0; i < m; ++i) {
        for (; r < q[i].r; ++r) update(r + 1, +1);
        for (; r > q[i].r; --r) update(r, -1);
        for (; l < q[i].l; ++l) update(l, -1);
        for (; l > q[i].l; --l) update(l - 1, +1);
        q[i].ans = ans;
    }

    std::sort(q, q + m, query_cmp_recover);
    for (int i = 0; i < m; ++i) printf("%I64d\n", q[i].ans);

    return 0;
}