#include <cstdio>
typedef long long int64;
static const int MAXN = 1e5 + 2;
static const int LOGA = 21;
static const int MAXM = 5e4 + 2;

int n, m;
int a[MAXN];

struct sgt {

static const int MAXN = ::MAXN * 2;
int sz;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN], sum[LOGA][MAXN];
bool tag[LOGA][MAXN];

inline void push(int idx) {
    if (lch[idx] == -1) return;
    for (int i = 0; i < LOGA; ++i) if (tag[i][idx]) {
        sum[i][lch[idx]] = r[lch[idx]] - l[lch[idx]] + 1 - sum[i][lch[idx]];
        sum[i][rch[idx]] = r[rch[idx]] - l[rch[idx]] + 1 - sum[i][rch[idx]];
        tag[i][lch[idx]] ^= 1;
        tag[i][rch[idx]] ^= 1;
        tag[i][idx] = false;
    }
}
inline void update(int idx) {
    if (lch[idx] == -1) return;
    for (int i = 0; i < LOGA; ++i)
        sum[i][idx] = sum[i][lch[idx]] + sum[i][rch[idx]];
}

int *BA;
int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R;
    if (L == R) {
        lch[idx] = rch[idx] = -1;
        for (int i = 0; i < LOGA; ++i)
            sum[i][idx] = (BA[L] >> i) & 1;
    } else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
        update(idx);
    }
    for (int i = 0; i < LOGA; ++i) tag[i][idx] = false;
    return idx;
}
inline void build(int n, int *a) {
    sz = 0; BA = a; build(0, n - 1);
}

int QL, QR, QV;
void range_flip(int idx) {
    push(idx);
    if (l[idx] >= QL && r[idx] <= QR) {
        for (int i = 0; i < LOGA; ++i) if (QV & (1 << i)) {
            sum[i][idx] = r[idx] - l[idx] + 1 - sum[i][idx];
            tag[i][idx] ^= 1;
        }
        return;
    }
    if (r[lch[idx]] >= QL) range_flip(lch[idx]);
    if (l[rch[idx]] <= QR) range_flip(rch[idx]);
    update(idx);
}
inline void range_flip(int L, int R, int V) {
    QL = L, QR = R, QV = V; range_flip(0);
}

int64 query_sum(int idx) {
    push(idx);
    int64 ans = 0;
    if (l[idx] >= QL && r[idx] <= QR) {
        for (int i = 0; i < LOGA; ++i) ans += (1LL << i) * sum[i][idx];
        return ans;
    }
    if (r[lch[idx]] >= QL) ans += query_sum(lch[idx]);
    if (l[rch[idx]] <= QR) ans += query_sum(rch[idx]);
    return ans;
}
inline int64 query_sum(int L, int R) {
    QL = L, QR = R; return query_sum(0);
}

} tree;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    tree.build(n, a);

    scanf("%d", &m);
    int ty, l, r, x;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &ty, &l, &r); --l, --r;
        if (ty == 1) {  // Query
            int64 ans = 0;
            ans += tree.query_sum(l, r);
            printf("%I64d\n", ans);
        } else {        // Modification
            scanf("%d", &x);
            tree.range_flip(l, r, x);
        }
    }

    return 0;
}