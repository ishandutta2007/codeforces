#include <cstdio>
#include <vector>
typedef long long int64;
static const int MAXN = 200005;
static const int MAXELEM = 200003;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n;
int a[MAXN], max_elem = 0;
std::vector<int> v[MAXELEM];
int64 h[MAXN];

// Monotonic segment tree used for the 'next' array
struct sgt_node {
    int l, r, lch, rch;
    int min, max, tag;
    int64 sum;
    static int sz;
    static const int TAG_NONE = -23333;
} t[MAXN * 2];
int sgt_node::sz = -1;

inline void sgt_update(int idx)
{
    if (t[idx].lch == -1) return;
    t[idx].max = max(t[t[idx].lch].max, t[t[idx].rch].max);
    t[idx].min = min(t[t[idx].lch].min, t[t[idx].rch].min);
    t[idx].sum = t[t[idx].lch].sum + t[t[idx].rch].sum;
}
inline void sgt_push(int idx)
{
    if (t[idx].tag == sgt_node::TAG_NONE || t[idx].lch == -1) return;
    t[t[idx].lch].tag = t[t[idx].lch].min = t[t[idx].lch].max =
    t[t[idx].rch].tag = t[t[idx].rch].min = t[t[idx].rch].max = t[idx].tag;
    t[t[idx].lch].sum = (int64)(t[t[idx].lch].r - t[t[idx].lch].l + 1) * t[idx].tag;
    t[t[idx].rch].sum = (int64)(t[t[idx].rch].r - t[t[idx].rch].l + 1) * t[idx].tag;
    t[idx].tag = sgt_node::TAG_NONE;
}
int sgt_build(int l, int r)
{
    int idx = ++sgt_node::sz;
    t[idx].l = l; t[idx].r = r;
    t[idx].tag = sgt_node::TAG_NONE;
    if (l == r) {
        t[idx].lch = t[idx].rch = -1;
        t[idx].min = t[idx].max = t[idx].sum = l;
    } else {
        int m = (l + r) >> 1;
        t[idx].lch = sgt_build(l, m);
        t[idx].rch = sgt_build(m + 1, r);
        sgt_update(idx);
    }
    return idx;
}
inline int64 sgt_sum()
{
    return t[0].sum;
}
void sgt_clamp(int l, int r, int val, int idx = 0)
{
    if (t[idx].min >= val) return;
    if (l <= t[idx].l && r >= t[idx].r && t[idx].max <= val) {
        // Full coverage
        t[idx].tag = t[idx].min = t[idx].max = val;
        t[idx].sum = (int64)(t[idx].r - t[idx].l + 1) * val;
    } else {
        sgt_push(idx);
        if (t[idx].lch != -1) {
            if (l <= t[t[idx].lch].r) sgt_clamp(l, r, val, t[idx].lch);
            if (r >= t[t[idx].rch].l) sgt_clamp(l, r, val, t[idx].rch);
        }
        sgt_update(idx);
    }
}

int main()
{
    scanf("%d", &n);
    if (n == 1) { puts("0"); return 0; }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (max_elem < a[i]) max_elem = a[i];
        for (int j = 1; j * j <= a[i]; ++j) if (a[i] % j == 0) {
            v[j].push_back(i);
            if (j * j != a[i]) v[a[i] / j].push_back(i);
        }
    }

    // Initialization is done in sgt_build
    // for (int i = 0; i < n; ++i) next[i] = i;
    sgt_build(0, n - 1);
    for (int i = max_elem; i >= 1; --i) {
        h[i] = (int64)n * n - sgt_sum();
        if (v[i].size() > 1) {
            sgt_clamp(v[i][1] + 1, n, n);
            sgt_clamp(v[i][0] + 1, v[i][1], v[i].back());
            sgt_clamp(0, v[i][0], v[i][v[i].size() - 2]);
        }
    }
    h[0] = 3;
    int64 ans = 0;
    for (int i = 0; i < max_elem; ++i)
        ans += (int64)(i + 1) * (h[i + 1] - h[i]);
    printf("%I64d\n", ans);
    return 0;
}