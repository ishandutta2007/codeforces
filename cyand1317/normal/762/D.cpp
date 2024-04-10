#include <cstdio>
typedef long long int64;
static const int64 INF64 = 1LL << 62;
static const int64 DELECTABLE = 1LL << 54;
static const int MAXN = 1e5 + 4;
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n;
int64 a[MAXN][3];
int64 f[MAXN][1 << 3];

int main()
{
    scanf("%d", &n);
    n += 2;
    a[0][0] = a[n - 1][2] = DELECTABLE;
    a[0][1] = a[0][2] = a[n - 1][0] = a[n - 1][1] = -INF64;
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j < n - 1; ++j) scanf("%I64d", &a[j][i]);

    for (int j = 0; j < 8; ++j) f[0][j] = -INF64;
    f[0][1] = a[0][0];
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 8; ++j) f[i + 1][j] = -INF64;
        // f[i][0]
        upd_max(f[i + 1][0], f[i][0]);
        // f[i][1]
        upd_max(f[i + 1][1], f[i][1] + a[i + 1][0]);
        upd_max(f[i + 1][7], f[i][1] + a[i + 1][0] + a[i + 1][1] + a[i + 1][2]);
        upd_max(f[i + 1][2], f[i][1] + a[i + 1][0] + a[i + 1][1]);
        upd_max(f[i + 1][4], f[i][1] + a[i + 1][0] + a[i + 1][1] + a[i + 1][2]);
        // f[i][2]
        upd_max(f[i + 1][2], f[i][2] + a[i + 1][1]);
        upd_max(f[i + 1][1], f[i][2] + a[i + 1][1] + a[i + 1][0]);
        upd_max(f[i + 1][4], f[i][2] + a[i + 1][1] + a[i + 1][2]);
        // f[i][4]
        upd_max(f[i + 1][4], f[i][4] + a[i + 1][2]);
        upd_max(f[i + 1][7], f[i][4] + a[i + 1][2] + a[i + 1][1] + a[i + 1][0]);
        upd_max(f[i + 1][2], f[i][4] + a[i + 1][2] + a[i + 1][1]);
        upd_max(f[i + 1][1], f[i][4] + a[i + 1][2] + a[i + 1][1] + a[i + 1][0]);
        // f[i][3]
        upd_max(f[i + 1][3], f[i][3] + a[i + 1][0] + a[i + 1][1]);
        upd_max(f[i + 1][0], f[i][3] + a[i + 1][0] + a[i + 1][1]);
        upd_max(f[i + 1][5], f[i][3] + a[i + 1][0] + a[i + 1][1] + a[i + 1][2]);
        // f[i][5]
        upd_max(f[i + 1][5], f[i][5] + a[i + 1][0] + a[i + 1][2]);
        upd_max(f[i + 1][0], f[i][5] + a[i + 1][0] + a[i + 1][1] + a[i + 1][2]);
        // f[i][6]
        upd_max(f[i + 1][6], f[i][6] + a[i + 1][2] + a[i + 1][1]);
        upd_max(f[i + 1][0], f[i][6] + a[i + 1][2] + a[i + 1][1]);
        upd_max(f[i + 1][5], f[i][6] + a[i + 1][2] + a[i + 1][1] + a[i + 1][0]);
        // f[i][7]
        upd_max(f[i + 1][7], f[i][7] + a[i + 1][0] + a[i + 1][1] + a[i + 1][2]);
        upd_max(f[i + 1][4], f[i][7] + a[i + 1][0] + a[i + 1][1] + a[i + 1][2]);
        upd_max(f[i + 1][1], f[i][7] + a[i + 1][0] + a[i + 1][1] + a[i + 1][2]);
    }
    /*for (int i = 0; i < n; ++i)
        for (int j = 0; j < 8; ++j) printf("%I64d%c", f[i][j] == -INF64 ? -114514 : f[i][j] - DELECTABLE, j == 7 ? '\n' : ' ');*/

    printf("%I64d\n", f[n - 1][4] - DELECTABLE * 2);
    return 0;
}