#include <cstdio>
typedef long long int64;
static const int64 INF64 = (1LL << 61);
static const int MAXN = 5015;
template <typename T> inline void upd_min(T &var, const T val) { if (var > val) var = val; }

int n, s, t, x[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int64 f[MAXN][MAXN];    // f[# of vertices considered][# of components]

int main()
{
    scanf("%d%d%d", &n, &s, &t); --s, --t;
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < MAXN; ++j) f[i][j] = INF64;
    if (s == 0) f[0][1] = (int64)d[0] - x[0];
    else if (t == 0) f[0][1] = (int64)b[0] - x[0];
    else f[0][1] = (int64)b[0] + d[0] - x[0] - x[0];

    for (int i = 1; i < n; ++i) {
        if (i == s) {
            for (int j = 1; j <= i + 1; ++j) {
                // #1: Out=Right
                upd_min(f[i][j], f[i - 1][j - 1] + d[i] - x[i]);
                // #2: Out=Left
                upd_min(f[i][j], f[i - 1][j] + c[i] + x[i]);
            }
        } else if (i == t) {
            for (int j = 1; j <= i + 1; ++j) {
                // #1: In=Right
                upd_min(f[i][j], f[i - 1][j - 1] + b[i] - x[i]);
                // #2: In=Left
                upd_min(f[i][j], f[i - 1][j] + a[i] + x[i]);
            }
        } else {
            for (int j = 1; j <= i + 1; ++j) {
                // #1: In=Right, Out=Right
                upd_min(f[i][j], f[i - 1][j - 1] + b[i] + d[i] - x[i] - x[i]);
                // #2: In=Right, Out=Left
                if (j - (s < i) >= 1) upd_min(f[i][j], f[i - 1][j] + b[i] + c[i]);
                // #3: In=Left, Out=Right
                if (j - (t < i) >= 1) upd_min(f[i][j], f[i - 1][j] + a[i] + d[i]);
                // #4: In=Left, Out=Left
                upd_min(f[i][j], f[i - 1][j + 1] + a[i] + c[i] + x[i] + x[i]);
            }
        }
        if (i < n - 1 && s <= i && t <= i) f[i][1] = INF64;
    }

    printf("%I64d\n", f[n - 1][1]);
    return 0;
}