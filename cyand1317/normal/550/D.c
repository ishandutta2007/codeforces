#include <stdio.h>

int main()
{
    int k, i, j;
    scanf("%d", &k);
    if (k % 2 == 0) puts("NO");
    else if (k == 1) {
        puts("YES\n2 1\n1 2");
    } else {
        printf("YES\n%d %d\n", k + k + 4, k * (k + k + 4) / 2);
        for (i = 2; i <= k; ++i)
            printf("1 %d\n%d %d\n%d %d\n", i, i, k + 1, i, k + 2);
        for (i = 2; i < k; ++i)
            for (j = i + 1; j <= k; ++j)
                if ((i & 1) || j != i + 1) printf("%d %d\n", i, j);
        printf("%d %d\n", k + 1, k + 2);

        for (i = 2; i <= k; ++i)
            printf("%d %d\n%d %d\n%d %d\n",
                k + 3, k + 2 + i, k + 2 + i, k + k + 3, k + 2 + i, k + k + 4);
        for (i = 2; i < k; ++i)
            for (j = i + 1; j <= k; ++j)
                if ((i & 1) || j != i + 1) printf("%d %d\n", i + k + 2, j + k + 2);
        printf("%d %d\n", k + k + 3, k + k + 4);
        printf("1 %d\n", k + 3);
    }
    return 0;
}