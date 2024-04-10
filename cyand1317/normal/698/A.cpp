#include <cstdio>
static const int INF = 0x1fffffff;
static const int MAXN = 105;

template <typename T> inline void update_min(T &var, const T val) {
    if (var > val) var = val;
}

int n;
int a[MAXN];
int f[MAXN][3];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i % 2 == 1)
            a[i] = ((a[i] & 1) << 1) + ((a[i] & 2) >> 1);
    }
    //for (int i = 0; i < n; ++i) printf("%d\n", a[i]);

    for (int i = 0; i < n; ++i)
        f[i][0] = f[i][1] = f[i][2] = INF;
    int i = 0;
    while (i < n && a[i] == 0) {
        f[i][0] = i + 1;
        f[i][1] = f[i][2] = INF;
        ++i;
    }
    f[i][0] = i + 1;
    f[i][1] = ((a[i] & 1) ? i : INF);
    f[i][2] = ((a[i] & 2) ? i : INF);
    for (; i < n - 1; ++i) {
        if (a[i + 1] & 1) {
            update_min(f[i + 1][1], f[i][1]);
            update_min(f[i + 1][1], f[i][0]);
        }
        if (a[i + 1] & 2) {
            update_min(f[i + 1][2], f[i][2]);
            update_min(f[i + 1][2], f[i][0]);
        }
        update_min(f[i + 1][0], f[i][0] + 1);
        update_min(f[i + 1][0], f[i][1] + 1);
        update_min(f[i + 1][0], f[i][2] + 1);
    }
    //for (int i = 0; i < n; ++i)
    //    printf("%d %d %d\n", f[i][0], f[i][1], f[i][2]);

    int ans = INF;
    update_min(ans, f[n - 1][0]);
    update_min(ans, f[n - 1][1]);
    update_min(ans, f[n - 1][2]);
    printf("%d\n", ans);

    return 0;
}