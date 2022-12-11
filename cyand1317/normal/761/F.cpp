#include <cstdio>
typedef long long int64;
static const int MAXN = 1003;
static const int MAXK = 300004;
static const int ALPHABET = 26;
template <typename T> inline T abs(const T x) { return x > 0 ? x : -x; }

int n, m, k;
char p[MAXN][MAXN];
int a[MAXK], b[MAXK], c[MAXK], d[MAXK]; char e[MAXK];

// Only considering changed submatrices
int changed_ct[ALPHABET][MAXN][MAXN] = {{{ 0 }}};
// Distance from original photo to all K photos, represented as a 2D prefix sum
int64 dist_orig[MAXN][MAXN] = {{ 0 }};
// Considering the whole photo
int64 all_ct[ALPHABET][MAXN][MAXN] = {{{ 0 }}};

template <typename T> inline void pfx_transform(T a[][MAXN]) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k); getchar();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m + 1; ++j) p[i][j] = getchar() - 'a';
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d%d %c", &a[i], &b[i], &c[i], &d[i], &e[i]); e[i] -= 'a';
    }

    for (int i = 0; i < k; ++i) {
        ++changed_ct[e[i]][a[i]][b[i]];
        --changed_ct[e[i]][a[i]][d[i] + 1];
        --changed_ct[e[i]][c[i] + 1][b[i]];
        ++changed_ct[e[i]][c[i] + 1][d[i] + 1];
    }
    for (int i = 0; i < ALPHABET; ++i) pfx_transform(changed_ct[i]);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k < ALPHABET; ++k)
                dist_orig[i][j] += abs(k - p[i][j]) * changed_ct[k][i][j];
    pfx_transform(dist_orig);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int changed_here = 0;
            for (int k = 0; k < ALPHABET; ++k) {
                all_ct[k][i][j] += changed_ct[k][i][j];
                changed_here += changed_ct[k][i][j];
            }
            all_ct[p[i][j]][i][j] += (k - changed_here);
        }
    for (int i = 0; i < ALPHABET; ++i) pfx_transform(all_ct[i]);

    int64 best = 1LL << 62, cur;
    for (int i = 0; i < k; ++i) {
        cur = 0;
        // (1) Outside changed submatrix
        cur += dist_orig[n][m];
        cur -= dist_orig[c[i]][d[i]];
        cur += dist_orig[c[i]][b[i] - 1];
        cur += dist_orig[a[i] - 1][d[i]];
        cur -= dist_orig[a[i] - 1][b[i] - 1];
        // (2) Inside changed submatrix
        for (int j = 0; j < ALPHABET; ++j) {
            cur += (int64)abs(j - e[i]) * all_ct[j][c[i]][d[i]];
            cur -= (int64)abs(j - e[i]) * all_ct[j][c[i]][b[i] - 1];
            cur -= (int64)abs(j - e[i]) * all_ct[j][a[i] - 1][d[i]];
            cur += (int64)abs(j - e[i]) * all_ct[j][a[i] - 1][b[i] - 1];
        }
        if (best > cur) best = cur;
    }

    printf("%I64d\n", best);
    return 0;
}