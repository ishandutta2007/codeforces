#include <cstdio>
#include <utility>
typedef long double ldouble;
static const int MAXN = 100005;

int n, q;
double p[MAXN];

namespace sgt {
static const int MAXN = ::MAXN * 2;

int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN];
typedef std::pair<ldouble, ldouble> seg_prob;
#define dom first
#define adv second
seg_prob val[MAXN];
int sz = 0;
static const seg_prob PROB_EMPTY = seg_prob(-1, -1);

inline seg_prob merge(const seg_prob &l, const seg_prob &r) {
    if (l == PROB_EMPTY) return r;
    if (r == PROB_EMPTY) return l;
    return seg_prob(
        l.dom / (1.0 - l.adv * (1.0 - r.dom)) * r.dom,
        r.adv + (1.0 - r.adv) * l.adv * r.dom / (1.0 - (1.0 - r.dom) * l.adv)
    );
}

int build(int _l, int _r) {
    int idx = sz++;
    l[idx] = _l; r[idx] = _r;
    if (_l == _r) {
        lch[idx] = rch[idx] = -1;
        val[idx] = seg_prob(p[_l], p[_l]);
    } else {
        int m = (_l + _r) >> 1;
        lch[idx] = build(_l, m);
        rch[idx] = build(m + 1, _r);
        val[idx] = merge(val[lch[idx]], val[rch[idx]]);
    }
    return idx;
}

int ql, qr;
seg_prob query(int idx) {
    if (l[idx] >= ql && r[idx] <= qr) return val[idx];
    seg_prob ans = PROB_EMPTY;
    if (r[lch[idx]] >= ql) ans = merge(ans, query(lch[idx]));
    if (l[rch[idx]] <= qr) ans = merge(ans, query(rch[idx]));
    return ans;
}
inline seg_prob query(int _l, int _r) {
    ql = _l; qr = _r; return query(0);
}

ldouble qv;
void modify(int idx) {
    if (l[idx] == r[idx]) { val[idx] = seg_prob(qv, qv); return; }
    if (r[lch[idx]] >= ql) modify(lch[idx]); else modify(rch[idx]);
    val[idx] = merge(val[lch[idx]], val[rch[idx]]);
}
inline void modify(int _pos, ldouble val) {
    ql = _pos; qv = val; modify(0);
}

}

int main()
{
    scanf("%d%d", &n, &q);
    int a, b, c, op;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b); p[i] = (ldouble)a / b;
    }
    sgt::build(0, n - 1);

    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1) {
            scanf("%d", &c);
            sgt::modify(a - 1, (ldouble)b / c);
        } else {
            printf("%.8lf\n", (double)(sgt::query(a - 1, b - 1).dom));
        }
    }

    return 0;
}