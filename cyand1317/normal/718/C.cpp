#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
static const int MAXN = 1e5 + 5;
static const int MAXM = 1e5 + 5;

inline int64 fpow(int64 base, int exp) {
    int64 ans = 0;
    for (; exp; exp >>= 1) {
        if (exp & 1) ans = ans * base _;
        base = base * base _;
    }
    return ans;
}
inline int64 inv(int64 x) { return fpow(x, MODULUS - 2); }

typedef int64 mat2[2][2];
static const mat2 ZERO = {{0, 0}, {0, 0}};
static const mat2 IDENTITY = {{1, 0}, {0, 1}};
static const mat2 FIBONACCI = {{1, 1}, {1, 0}};
inline void mat2_assign(mat2 a, const mat2 b) {
    memcpy(a, b, sizeof(mat2));
}
inline void mat2_add(mat2 a, const mat2 b) {
    a[0][0] = (a[0][0] + b[0][0])_;
    a[0][1] = (a[0][1] + b[0][1])_;
    a[1][0] = (a[1][0] + b[1][0])_;
    a[1][1] = (a[1][1] + b[1][1])_;
}
inline void mat2_mul(mat2 a, const mat2 b) {
    static mat2 c;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j])_;
    memcpy(a, c, sizeof(mat2));
}
inline void mat2_fpow(mat2 base, int exp) {
    mat2 ans; mat2_assign(ans, IDENTITY);
    for (; exp; exp >>= 1) {
        if (exp & 1) mat2_mul(ans, base);
        mat2_mul(base, base);
    }
    memcpy(base, ans, sizeof(mat2));
}

int n, m;
int a[MAXN];

namespace sgt {

static const int MAXN = ::MAXN * 2;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN];
mat2 val[MAXN];
mat2 tag[MAXN];
int sz = 0;

mat2 tmp;

inline void push(int idx) {
    if (lch[idx] == -1) return;
    mat2_mul(val[lch[idx]], tag[idx]);
    mat2_mul(val[rch[idx]], tag[idx]);
    mat2_mul(tag[lch[idx]], tag[idx]);  // mdzz ()
    mat2_mul(tag[rch[idx]], tag[idx]);  // mdzz ()
    mat2_assign(tag[idx], IDENTITY);
}
inline void update(int idx) {
    if (lch[idx] == -1) return;
    mat2_assign(val[idx], val[lch[idx]]);
    mat2_add(val[idx], val[rch[idx]]);
}

int build(int L, int R) {
    int idx = sz++;
    l[idx] = L; r[idx] = R;
    mat2_assign(tag[idx], IDENTITY);
    if (L == R) {
        lch[idx] = rch[idx] = -1;
        mat2_assign(val[idx], FIBONACCI);
        mat2_fpow(val[idx], ::a[L - 1]);
    } else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
        mat2_assign(val[idx], val[lch[idx]]);
        mat2_add(val[idx], val[rch[idx]]);
    }
    return idx;
}

int ql, qr;
void query(mat2 res, int idx) {
    push(idx);
    if (l[idx] >= ql && r[idx] <= qr) {
        mat2_add(res, val[idx]);
        return;
    }
    if (r[lch[idx]] >= ql) query(res, lch[idx]);
    if (l[rch[idx]] <= qr) query(res, rch[idx]);
    update(idx);
}
inline int64 query(int L, int R) {
    ql = L, qr = R;
    mat2 ans; mat2_assign(ans, ZERO);
    query(ans, 0);
    return ans[0][1];
}
int qv;
mat2 qmat;
void modify(int idx) {
    push(idx);
    if (l[idx] >= ql && r[idx] <= qr) {
        mat2_mul(val[idx], qmat);
        mat2_mul(tag[idx], qmat);
        return;
    }
    if (r[lch[idx]] >= ql) modify(lch[idx]);
    if (l[rch[idx]] <= qr) modify(rch[idx]);
    update(idx);
}
inline void modify(int L, int R, int val) {
    ql = L, qr = R, qv = val;
    mat2_assign(qmat, FIBONACCI);
    mat2_fpow(qmat, val);
    modify(0);
}

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sgt::build(1, n);

    int op, l, r, x;
    do {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            scanf("%d", &x);
            sgt::modify(l, r, x);
        } else {    // op == 2
            printf("%I64d\n", sgt::query(l, r));
        }
    } while (--m);

    return 0;
}