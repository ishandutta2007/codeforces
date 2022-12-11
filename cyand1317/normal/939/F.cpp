#include <cstdio>
#include <algorithm>
#include <utility>

static const int INF = 0x3fffffff;
static const int MAXN = 1e5 + 4;
static const int MAXK = 104;

static int n, k;
static std::pair<int, int> p[MAXK];

class sgt {
// Range minimum update, single value query
public:
    static const int MAXN = ::MAXN * 2;
    struct node { int l, r, lch, rch, tag, min; } t[MAXN];
    int sz;

    inline int build(int L, int R) {
        int idx = sz++;
        t[idx].l = L, t[idx].r = R;
        t[idx].tag = t[idx].min = INF;
        if (L == R) {
            t[idx].lch = t[idx].rch = -1;
        } else {
            int M = (L + R) >> 1;
            t[idx].lch = build(L, M);
            t[idx].rch = build(M + 1, R);
        }
        return idx;
    }
    inline void rebuild(int N) { sz = 0; build(0, N - 1); }

private:
    inline void apply(int idx, int val) {
        t[idx].tag = std::min(t[idx].tag, val);
        t[idx].min = std::min(t[idx].min, val);
    }
    inline void push(int idx) {
        if (t[idx].tag != INF && t[idx].lch != -1) {
            apply(t[idx].lch, t[idx].tag);
            apply(t[idx].rch, t[idx].tag);
            t[idx].tag = INF;
        }
    }
    inline void update(int idx) {
        if (t[idx].lch != -1) {
            push(idx);
            t[idx].min = std::min(t[t[idx].lch].min, t[t[idx].rch].min);
        }
    }

    int QL, QR, QV;

public:
    inline void modify(int idx) {
        push(idx);
        if (t[idx].l >= QL && t[idx].r <= QR) { apply(idx, QV); return; }
        if (t[t[idx].lch].r >= QL) modify(t[idx].lch);
        if (t[t[idx].rch].l <= QR) modify(t[idx].rch);
        update(idx);
    }
    inline void modify(int L, int R, int V) { if (L <= R) { QL = L, QR = R, QV = V; modify(0); } }

    inline int query(int P) {
        int idx = 0;
        while (t[idx].lch != -1) {
            push(idx);
            idx = (t[t[idx].lch].r >= P) ? t[idx].lch : t[idx].rch;
        }
        return t[idx].min;
    }
} f[2][2];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) scanf("%d%d", &p[i].first, &p[i].second);
    p[k++] = std::make_pair(n * 2, n * 2);

    int cur = 0;
    f[cur][0].rebuild(n + 1);
    f[cur][1].rebuild(n + 1);
    f[cur][1].modify(0, 0, 0);
    for (int i = 0; i < k; ++i) {
        cur ^= 1;
        f[cur][0].rebuild(n + 1);
        f[cur][1].rebuild(n + 1);
        int space = p[i].first - (i == 0 ? 0 : p[i - 1].second);
        int dur = p[i].second - p[i].first;
        for (int s = 0; s <= 1; ++s)
            for (int j = 0, t; j <= n; ++j) if ((t = f[cur ^ 1][s].query(j)) < INF) {
                int l, r;
                // (1) No flip
                l = j + (space + dur) * s, r = j + (space + dur) * s;
                f[cur][s].modify(std::min(l, n + 1), std::min(r, n), t);
                // (2) Flip once
                l = j + (space + dur) * s, r = j + space * s + dur * !s;
                if (l > r) std::swap(l, r);
                f[cur][s ^ 1].modify(std::min(l, n + 1), std::min(r, n), t + 1);
                // (3) Flip twice
                f[cur][s].modify(std::min(l, n + 1), std::min(r, n), t + 2);
            }
    }

    int ans = std::min(f[cur][0].query(n), f[cur][1].query(n));
    if (ans >= INF) puts("Hungry");
    else printf("Full\n%d\n", ans);

    return 0;
}