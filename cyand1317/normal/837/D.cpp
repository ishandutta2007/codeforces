#include <cstdio>
typedef long long int64;
static const int MAXN = 202;
static const int MAXD = 202 * 64;
static const int INF = 0x3fffffff;
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n, k;
int64 a[MAXN];
int twos[MAXN], fifs[MAXN];

// f[# of selected elements][twos] = maximum fives
int f[MAXN][MAXD];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        twos[i] = fifs[i] = 0;
        while (a[i] % 2 == 0) a[i] /= 2, ++twos[i];
        while (a[i] % 5 == 0) a[i] /= 5, ++fifs[i];
    }

    for (int i = 0; i <= k; ++i)
        for (int j = 0; j < MAXD; ++j) f[i][j] = -INF;
    f[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = k - 1; j >= 0; --j)
            for (int k = 0; k < MAXD - twos[i]; ++k)
                upd_max(f[j + 1][k + twos[i]], f[j][k] + fifs[i]);
    }

    int ans = 0;
    for (int i = 0; i < MAXD; ++i)
        upd_max(ans, (i < f[k][i] ? i : f[k][i]));
    printf("%d\n", ans);

    return 0;
}