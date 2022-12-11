#include <cstdio>
typedef long long int64;
static const int64 INF64 = 1LL << 61;
static const int MAXKLEN = 64;
static const int MAXNLEN = 11;
template <typename T> inline void upd_min(T &var, const T val) { if (var > val) var = val; }

int n, klen;
char k[MAXKLEN];
int64 seg[MAXKLEN][MAXNLEN];
int64 f[MAXKLEN];

int main()
{
    scanf("%d", &n); getchar();
    for (klen = 0; (k[klen] = getchar()) != '\n'; ++klen) k[klen] -= '0'; k[klen] = -1;
    for (int i = 0; i <= klen; ++i) seg[i][0] = 0;
    for (int i = 1; i < MAXNLEN; ++i)
        for (int j = 0; j <= klen - i; ++j)
            seg[j][i] = seg[j][i - 1] * 10 + k[i + j - 1];

    f[0] = 0;
    for (int i = 0; i < klen; ++i) {
        f[i + 1] = INF64;
        if (f[i] <= INF64 / n + 1) upd_min(f[i + 1], f[i] * n + k[i]);
        for (int j = 1; j < MAXNLEN; ++j)
            if (i - j >= -1 && seg[i - j + 1][j] < n && k[i - j + 1] != 0 && f[i - j + 1] <= INF64 / n + 1) {
                upd_min(f[i + 1], f[i - j + 1] * n + seg[i - j + 1][j]);
            }
    }

    printf("%I64d\n", f[klen]);
    return 0;
}