#include <cstdio>
static const int MAXN = 1e5 + 4;
static const int THRESHOLD = 418;

int n, a[MAXN];
int q, p, k;
int steps[THRESHOLD][MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    for (int i = 1; i < THRESHOLD; ++i) {
        for (int j = n; j >= 1; --j)
            steps[i][j] = (j + a[j] + i > n ? 0 : steps[i][j + a[j] + i]) + 1;
    }

    scanf("%d", &q);
    do {
        scanf("%d%d", &p, &k);
        if (k >= THRESHOLD) {
            int ans = 0;
            while (p <= n) p = p + a[p] + k, ++ans;
            printf("%d\n", ans);
        } else {
            printf("%d\n", steps[k][p]);
        }
    } while (--q);

    return 0;
}