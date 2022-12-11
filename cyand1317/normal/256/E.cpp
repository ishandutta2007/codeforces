#include <cstdio>
typedef long long int64;
static const int MAXN = 77790;
typedef int mat[3][3];
static const int MODULUS = 777777777;
#define _  %  MODULUS
#define __ %= MODULUS

int n, m;
mat w;
inline void zerofill(mat a) { for (register int i = 0; i < 3; ++i) a[i][0] = a[i][1] = a[i][2] = 0; }

namespace sgt {

static const int MAXN = ::MAXN * 2;
int sz;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN];
mat val[MAXN];

inline void update(int idx) {
    if (lch[idx] == -1) return;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            val[idx][i][j] = 0;
            for (int k = 0; k < 3; ++k)
                for (int l = 0; l < 3; ++l) if (w[k][l])
                    val[idx][i][j] = ((int64)val[lch[idx]][i][k] * val[rch[idx]][l][j] + val[idx][i][j])_;
        }
}

int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R;
    if (L == R) {
        lch[idx] = rch[idx] = -1;
        zerofill(val[idx]);
        for (int i = 0; i < 3; ++i) val[idx][i][i] = 1;
    } else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
        update(idx);
    }
    return idx;
}
inline void build(int N) { sz = 0; build(0, N - 1); }

int qp, qv;
void modify(int idx) {
    if (lch[idx] == -1) {
        zerofill(val[idx]);
        if (qv == -1) for (int i = 0; i < 3; ++i) val[idx][i][i] = 1;
        else val[idx][qv][qv] = 1;
        return;
    }
    if (r[lch[idx]] >= qp) modify(lch[idx]); else modify(rch[idx]);
    update(idx);
    return;
}
inline void modify(int P, int V) { qp = P, qv = V; modify(0); }

inline int get_answer() {
    int64 ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) ans += (int64)val[0][i][j];
    return ans _;
}

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) scanf("%d", &w[i][j]);

    sgt::build(n);
    int v_i, t_i;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &v_i, &t_i); --v_i, --t_i;
        sgt::modify(v_i, t_i);
        printf("%d\n", sgt::get_answer());
    }

    return 0;
}