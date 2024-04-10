#include <cstdio>
static const int INF = 0x3fffffff;
static const int MAXN = 262144 + 10;
template <typename T> inline void upd_min(T &var, const T val) { if (var > val) var = val; }

int n, q, s[MAXN];

namespace sgt {
static const int MAXN = 524288 + 10;
static const int MATSZ = 6;
typedef int mat[MATSZ][MATSZ];
static const int L_TMP = MAXN - 1, R_TMP = MAXN - 2;

int n;
mat val[MAXN];
inline void reset_mat(int a) {
    for (int j = 0; j < MATSZ; ++j)
        for (int k = 0; k < MATSZ; ++k) val[a][j][k] = (j == k ? 0 : INF);
}
inline void merge_mat(int a, int b, int c) {
    static mat ret;
    for (int i = 0; i < MATSZ; ++i)
        for (int j = 0; j < MATSZ; ++j) {
            ret[i][j] = INF;
            for (int k = 0; k < MATSZ; ++k) upd_min(ret[i][j], val[b][i][k] + val[c][k][j]);
        }
    for (int i = 0; i < MATSZ; ++i)
        for (int j = 0; j < MATSZ; ++j) val[a][i][j] = ret[i][j];
}
inline void build(int _n) {
    n = 1 << (8 * sizeof(int) - __builtin_clz(_n));
    for (int i = n; i < n * 2; ++i) {
        reset_mat(i);
        switch (s[i - n]) {
            case '2': val[i][0][0] = 1; val[i][0][1] = 0; break;
            case '0': val[i][1][1] = 1; val[i][1][2] = 0; break;
            case '1': val[i][2][2] = 1; val[i][2][3] = 0; break;
            case '6':
                val[i][3][3] = val[i][4][4] = 1;
                val[i][3][5] = val[i][4][5] = 0; break;
            case '7': val[i][3][3] = 1; val[i][3][4] = 0; break;
            default: break;
        }
    }
    for (int i = n - 1; i >= 1; --i) merge_mat(i, i * 2, i * 2 + 1);
}

inline int query(int l, int r) {
    l += n; r += n;
    reset_mat(L_TMP); reset_mat(R_TMP);
    while (l < r) {
        if (l & 1) merge_mat(L_TMP, L_TMP, l), ++l;
        if (!(r & 1)) merge_mat(R_TMP, r, R_TMP), --r;
        l >>= 1; r >>= 1;
    }
    if (l == r) merge_mat(L_TMP, L_TMP, l);
    merge_mat(L_TMP, L_TMP, R_TMP);
    return val[L_TMP][0][4] == INF ? -1 : val[L_TMP][0][4];
}
}

int main()
{
    scanf("%d%d", &n, &q); getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar();
    sgt::build(n);

    int a_i, b_i;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &a_i, &b_i); --a_i, --b_i;
        printf("%d\n", sgt::query(a_i, b_i));
    }

    return 0;
}