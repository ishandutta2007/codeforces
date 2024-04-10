#include <stdio.h>
#define MAXN 55

int main()
{
    int n, i, h, v;
    unsigned char asphalted[2][MAXN] = { 0 };

    scanf("%d", &n);
    for (i = 1; i <= n * n; ++i) {
        scanf("%d%d", &h, &v);
        // --h; --v;
        if (!asphalted[0][h] && !asphalted[1][v]) {
            asphalted[0][h] = asphalted[1][v] = 1;
            printf("%d ", i);
        }
    }
    putchar('\n');
    return 0;
}