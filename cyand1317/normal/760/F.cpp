#include <cstdio>
typedef long long int64;
static const int MAXN = 5004;
static const int ALPHA = 26;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
#define __ %= MODULUS

int n; char s[MAXN];
int binom[MAXN][MAXN];
// f[length of compressed string][last letter of string]
int f[MAXN][ALPHA] = {{ 0 }}, f_rowsum[MAXN] = { 0 };

void preprocess_binomials()
{
    binom[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j])_;
    }
}

int main()
{
    preprocess_binomials();

    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar() - 'a';

    f_rowsum[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int len = i + 1; len >= 1; --len) {
            int increment = ((f_rowsum[len - 1] - f[len - 1][s[i]] - f[len][s[i]])_ + MODULUS)_;
            (f[len][s[i]] += increment)__;
            (f_rowsum[len] += increment)__;
        }
    }
    /*for (int i = 0; i <= n; ++i) {
        printf("Len=%d |", i);
        for (int j = 0; j < ALPHA; ++j) printf(" %d", f[i][j]);
        putchar('\n');
    }*/
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < ALPHA; ++j)
            ans = ((int64)ans + (int64)f[i][j] * binom[n - 1][i - 1])_;

    printf("%d\n", ans);
    return 0;
}