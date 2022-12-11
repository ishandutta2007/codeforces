#include <stdio.h>
#define MAXN 103

int main()
{
    int n, i, j, t;
    unsigned char not_good[MAXN] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j) {
            scanf("%d", &t);
            if (t == -1) continue;
            if (t & 1) not_good[i] = 1;
            if (t & 2) not_good[j] = 1;
        }
    int good_ct = 0, first_num = 1;
    for (i = 0; i < n; ++i) if (!not_good[i]) ++good_ct;
    printf("%d", good_ct);
    for (i = 0; i < n; ++i)
        if (!not_good[i]) {
            putchar(first_num ? '\n' : ' ');
            first_num = 0;
            printf("%d", i + 1);
        }
    return 0;
}