#include <stdio.h>
#include <stdlib.h>

int a[300000], st[300000];

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    j = 0;
    for (i = 0; i < n; i++) {
        while (j > 0 && st[j - 1] == a[i]) {
            a[i]++;
            j--;
        }
        st[j++] = a[i];
    }
    printf("%d\n", j);
    for (i = 0; i < j; i++) {
        printf("%d ", st[i]);
    }
    return 0;
}