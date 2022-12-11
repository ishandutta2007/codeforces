#include <cstdio>
typedef long long int64;
static const int MAXN = 100008;
static const int HASH_BASE = 2333;
static const int64 HASH_MOD = 100000007;
#define _ % HASH_MOD
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

inline int64 fpow(int64 b, int64 e) {
    int64 ans = 1;
    while (e) { if (e & 1) ans = (ans * b)_; b = (b * b)_; e >>= 1; }
    return ans;
}
inline int64 inv(int64 x) { return fpow(x, HASH_MOD - 2); }
const int64 inv_HASH_BASE_1 = inv(HASH_BASE - 1);
int64 fpow_HASH_BASE[MAXN];
inline void init_fpow_HASH_BASE(int n) {
    fpow_HASH_BASE[0] = 1;
    for (int i = 1; i <= n; ++i)
        fpow_HASH_BASE[i] = (fpow_HASH_BASE[i - 1] * HASH_BASE)_;
}

int n, m, k;
char s[MAXN];

struct sgt_node {
    int l, r, lch, rch;
    int tag;
    int64 sum;
    static int sz;
} t[MAXN * 2];
int sgt_node::sz = -1;

inline void sgt_push(int idx) {
    if (t[idx].tag == -1 || t[idx].lch == -1) return;
    t[t[idx].lch].tag = t[t[idx].rch].tag = t[idx].tag;
    t[t[idx].lch].sum = t[idx].tag * (fpow_HASH_BASE[t[t[idx].lch].r - t[t[idx].lch].l + 1] - 1)_ * inv_HASH_BASE_1 _;
    t[t[idx].rch].sum = t[idx].tag * (fpow_HASH_BASE[t[t[idx].rch].r - t[t[idx].rch].l + 1] - 1)_ * inv_HASH_BASE_1 _;
    t[idx].tag = -1;
}
inline void sgt_update(int idx) {
    if (t[idx].lch == -1) return;
    t[idx].sum = (t[t[idx].lch].sum +
        t[t[idx].rch].sum * fpow_HASH_BASE[t[t[idx].lch].r - t[t[idx].lch].l + 1])_;
}
int sgt_build(int l, int r)
{
    int idx = ++sgt_node::sz;
    t[idx].l = l; t[idx].r = r;
    t[idx].tag = -1;
    if (l == r) {
        t[idx].lch = t[idx].rch = -1;
        t[idx].sum = s[l];
    } else {
        int m = (l + r) >> 1;
        t[idx].lch = sgt_build(l, m);
        t[idx].rch = sgt_build(m + 1, r);
        sgt_update(idx);
    }
    return idx;
}
void sgt_modify(int l, int r, int val, int idx = 0)
{
    if (t[idx].l >= l && t[idx].r <= r) {
        t[idx].tag = val;
        t[idx].sum = val * (fpow(HASH_BASE, t[idx].r - t[idx].l + 1) - 1)_ * inv_HASH_BASE_1 _;
        return;
    }
    sgt_push(idx);
    if (t[t[idx].lch].r >= l) sgt_modify(l, r, val, t[idx].lch);
    if (t[t[idx].rch].l <= r) sgt_modify(l, r, val, t[idx].rch);
    sgt_update(idx);
}
int64 sgt_query(int l, int r, int idx = 0)
{
    if (t[idx].l >= l && t[idx].r <= r) return t[idx].sum;
    sgt_push(idx);
    int ans = 0;
    if (t[t[idx].lch].r >= l) ans = sgt_query(l, r, t[idx].lch);
    if (t[t[idx].rch].l <= r) {
        ans += sgt_query(l, r, t[idx].rch) * fpow_HASH_BASE[max(0, t[t[idx].lch].r - max(l, t[t[idx].lch].l) + 1)]_;
    }
    sgt_update(idx);
    return ans _;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k); m += k; getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar() - '0';
    init_fpow_HASH_BASE(n);
    sgt_build(0, n - 1);

    int op, l, r, arg;
    do {
        scanf("%d%d%d%d", &op, &l, &r, &arg); --l, --r;
        if (op == 1) {
            sgt_modify(l, r, arg);
        } else {
            puts(arg >= r - l + 1 || sgt_query(l, r - arg) == sgt_query(l + arg, r) ? "YES" : "NO");
        }
    } while (--m);

    return 0;
}