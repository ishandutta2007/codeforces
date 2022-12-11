#include <cstdio>
#include <algorithm>
using std::min;
static const int MAXN = 1e6 + 5;

int n, m;
char s[MAXN];

namespace sgt {

static const int MAXN = ::MAXN * 2;

struct query_result {
    int opening, closing, length;
    query_result(int opening = 0, int closing = 0, int length = 0)
        : opening(opening), closing(closing), length(length) { }
    query_result(const query_result lhs, const query_result rhs) {
        this->opening = lhs.opening + rhs.opening;
        this->closing = lhs.closing + rhs.closing;
        this->length = lhs.length + rhs.length + min(lhs.opening - lhs.length, rhs.closing - rhs.length);
    }
};
int sz;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN];
query_result val[MAXN];

int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R;
    if (L == R) {
        lch[idx] = rch[idx] = -1;
        val[idx] = query_result(::s[L] == '(', ::s[R] == ')', 0);
    } else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
        val[idx] = query_result(val[lch[idx]], val[rch[idx]]);
    }
    return idx;
}
inline void build(int N) { sz = 0; build(0, N - 1); }

int QL, QR;
query_result query(int idx) {
    if (QL <= l[idx] && QR >= r[idx]) return val[idx];
    query_result ans;
    if (QL <= r[lch[idx]]) ans = query_result(ans, query(lch[idx]));
    if (QR >= l[rch[idx]]) ans = query_result(ans, query(rch[idx]));
    return ans;
}
inline int query(int L, int R) { QL = L, QR = R; return query(0).length * 2; }

}

int main()
{
    for (n = 0; (s[n] = getchar()) != '\n'; ++n) ;
    sgt::build(n);

    scanf("%d", &m);
    int l, r;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &l, &r); --l, --r;
        printf("%d\n", sgt::query(l, r));
    }

    return 0;
}