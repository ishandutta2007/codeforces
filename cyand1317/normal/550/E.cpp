#include <cstdio>
static const int MAXN = 100005;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int last_0 = 0, last_1 = 0, slast_0 = 0;
    int p = n - 1;
    while (p >= 0 && a[p] == 0) --p, ++last_0;
    while (p >= 0 && a[p] == 1) --p, ++last_1;
    while (p >= 0 && a[p] == 0) --p, ++slast_0;

    if (last_0 == 0 || (last_0 == 2 && slast_0 == 0)) {
        puts("NO"); return 0;
    }
    puts("YES");
    if (last_0 == 1) {
        for (int i = 0; i < n; ++i)
            printf("%d%s", a[i], i == n - 1 ? "\n" : "->");
    } else if (last_0 == 2) {
        for (int i = 0; i < n - last_0 - last_1 - 1; ++i) printf("%d->", a[i]);
        printf("(0->(");
        for (int i = 0; i < last_1; ++i) printf("1->");
        printf("0))->0\n");
    } else {    // last_0 >= 3
        for (int i = 0; i < n - 3; ++i) printf("%d->", a[i]);
        printf("(0->0)->0");
    }

    return 0;
}