#include <stdio.h>
#define MAXN 100002

int main()
{
    int n, a[MAXN];
    unsigned char keep[MAXN] = { 0 };
    int changeable[MAXN], ch_top = 0;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        if (a[i] < n && !keep[a[i]]) keep[a[i]] = 1;
        else changeable[ch_top++] = i;
    }
    for (i = 0; i < n; ++i)
        if (!keep[i]) a[changeable[--ch_top]] = i;
    printf("%d", a[0] + 1);
    for (i = 1; i < n; ++i) printf(" %d", a[i] + 1);
    putchar('\n');
    return 0;
}