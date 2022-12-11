#include <cstdio>
static const int MAXN = 102;
template <typename T> inline T abs(const T x) { return x > 0 ? x : -x; }
template <typename T> inline void update_min(T &var, const T val) { if (var > val) var = val; }

int n, d;
int a[MAXN], x[MAXN], y[MAXN];
int f[MAXN][MAXN] = {{ 0 }};

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i < n - 1; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j) f[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d - a[i];
    // FloydWarshall
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                update_min(f[i][j], f[i][k] + f[k][j]);

    printf("%d\n", f[0][n - 1]);

    return 0;
}