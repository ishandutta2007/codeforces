#include <cstdio>

int main()
{
    int n, i, br0=0, br5=0, tmp;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        if (tmp == 0)
            br0++;
        else
            br5++;
    }

    if (!br0)
        printf("-1\n");
    else {
        for (i=0; i<br5-br5%9; i++)
            printf("5");
        if (br5 >= 9)
            for (i=0; i<br0; i++)
                printf("0");
        else
            printf("0");
    }
    printf("\n");

    return 0;
}