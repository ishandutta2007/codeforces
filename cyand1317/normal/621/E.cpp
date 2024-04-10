#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXX = 102;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS

typedef int mat[MAXX][MAXX];
int mat_sz = MAXX;

inline void mat_mul(mat a, mat b) {
    static int64 c[MAXX][MAXX];
    for (int i = 0; i < mat_sz; ++i)
        for (int j = 0; j < mat_sz; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < mat_sz; ++k)
                c[i][j] = (c[i][j] + (int64)a[i][k] * b[k][j])_;
        }
    for (int i = 0; i < mat_sz; ++i)
        for (int j = 0; j < mat_sz; ++j) a[i][j] = c[i][j];
}

inline void mat_fpow(mat a, int exp) {
    mat c = {{ 0 }};
    for (int i = 0; i < mat_sz; ++i) c[i][i] = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) mat_mul(c, a);
        mat_mul(a, a);
    }
    memcpy(a, c, sizeof(mat));
}

int n, b, k, x, ai;

int main()
{
    scanf("%d%d%d%d", &n, &b, &k, &x);
    int ct[10] = { 0 };
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ai);
        ct[ai]++;
    }

    mat_sz = x;
    mat trans = {{ 0 }};
    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j < x; ++j)
            trans[j][(j * 10 + i) % x] += ct[i];
    }

    mat_fpow(trans, b);
    printf("%d\n", trans[0][k]);

    return 0;
}