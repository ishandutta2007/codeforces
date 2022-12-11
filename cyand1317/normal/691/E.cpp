#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 108;
static const int BITS = 64;
static const int MODULUS = 1e9 + 7;
typedef int mat[MAXN][MAXN];

int n;
int64 k;
int64 a[MAXN];
mat t = {{ 0 }};

inline void mat_mul(mat a, mat b)
{
    static int64 x[MAXN][MAXN];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            x[i][j] = 0;
            for (int k = 0; k < n; ++k)
                x[i][j] = (x[i][j] + (int64)a[i][k] * b[k][j]) % MODULUS;
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) a[i][j] = x[i][j];
}
inline void mat_fpow(mat base, int64 exp)
{
    mat ans = {{ 0 }};
    for (int i = 0; i < n; ++i) ans[i][i] = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) mat_mul(ans, base);
        mat_mul(base, base);
    }
    memcpy(base, ans, sizeof(mat));
}

int main()
{
    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
                t[i][j] = 1;
    mat_fpow(t, k - 1);
    int64 ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans += t[i][j];
    printf("%I64d\n", ans % MODULUS);
    return 0;
}