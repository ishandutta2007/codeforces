#include <cstdio>
#include <algorithm>
#include <map>
typedef long long int64;
static const int MAXN = 100005;
static const int INF = 0x7fffffff;

struct ring {
    int inner, outer, height;
};
inline bool operator < (const ring &lhs, const ring &rhs) {
    return (lhs.outer == rhs.outer) ? (lhs.inner > rhs.inner) : (lhs.outer > rhs.outer);
}

int n;
ring r[MAXN];
std::map<int, int> discretize;

namespace sgt {

static const int MAXN = ::MAXN * 4;

int sz;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN];
int64 val[MAXN];

int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R; val[idx] = 0;
    if (L == R) lch[idx] = rch[idx] = -1;
    else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
    }
    return idx;
}
inline void build(int N) { sz = 0; build(0, N - 1); }

int QL, QR; int64 QV;
void modify(int idx) {
    if (l[idx] == r[idx]) { val[idx] = QV; return; }
    if (QL <= r[lch[idx]]) modify(lch[idx]); else modify(rch[idx]);
    val[idx] = std::max(val[lch[idx]], val[rch[idx]]);
}
inline void modify(int P, int64 V) { QL = P, QV = V; modify(0); }

int64 query(int idx) {
    if (l[idx] >= QL && r[idx] <= QR) return val[idx];
    int64 ans = 0;
    if (QL <= r[lch[idx]]) ans = std::max(ans, query(lch[idx]));
    if (QR >= l[rch[idx]]) ans = std::max(ans, query(rch[idx]));
    return ans;
}
inline int64 query(int L, int R) { if (L > R) return -INF; QL = L, QR = R; return query(0); }

}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &r[i].inner, &r[i].outer, &r[i].height);
    std::sort(r, r + n);
    for (int i = 0; i < n; ++i) discretize[r[i].inner] = discretize[r[i].outer] = 114514;
    int ct = 0;
    for (std::map<int, int>::iterator i = discretize.begin(); i != discretize.end(); ++i) {
        i->second = ct++;
    }

    sgt::build(ct);
    for (int i = 0; i < n; ++i) {
        sgt::modify(discretize[r[i].inner], sgt::query(0, discretize[r[i].outer] - 1) + r[i].height);
    }

    printf("%I64d\n", sgt::query(0, ct - 1));
    return 0;
}