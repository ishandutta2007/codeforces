#include <cstdio>
static const int MAXN = 107;

int n, a[MAXN];
int idx[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int max_id = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) ++max_id;
        idx[i] = max_id < 0 ? 0 : max_id;
    }

    if (max_id == -1) { puts("NO"); return 0; }
    puts("YES");
    printf("%d\n", idx[n - 1] + 1);
    printf("1");
    for (int i = 1; i < n; ++i) {
        if (idx[i] != idx[i - 1]) printf(" %d\n%d", i, i + 1);
    }
    printf(" %d\n", n);

    return 0;
}