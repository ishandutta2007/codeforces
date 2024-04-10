#include <cstdio>

int main()
{
    int n, i, r=0, zad, tmp;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        if (!i || tmp % 2 != zad)
            r++;
        zad = tmp % 2;
    }

    printf("%d\n", r);

    return 0;
}