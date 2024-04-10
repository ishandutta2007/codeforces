/* > < */
#include <stdio.h>

#define MAXN    200003

static int n, a[MAXN][2];
static _Bool vis[MAXN] = { 0 };

int main()
{
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &a[i][0], &a[i][1]);
        a[i][0]--;
        a[i][1]--;
    }

    if (n == 3) {
        puts("1 2 3");
    } else {
        if (a[a[0][1]][0] == a[0][0] || a[a[0][1]][1] == a[0][0]) {
            int t = a[0][0];
            a[0][0] = a[0][1];
            a[0][1] = t;
        }
        printf("1 %d", a[0][0] + 1);
        int l2 = 0, l1 = a[0][0];
        for (i = 2; i < n; ++i) {
            int new = a[l2][0] + a[l2][1] - l1;
            l2 = l1;
            l1 = new;
            printf(" %d", l1 + 1);
        }
        putchar('\n');
    }

    return 0;
}