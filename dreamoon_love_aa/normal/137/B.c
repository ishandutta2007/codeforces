#include <stdio.h>
#define N 5000
int main() {
    int i, n, c, a[N], f[N] = {0};
    scanf("%d", &n);
    c = 0;
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(f[a[i]-1] == 0 && a[i] <= n)
            f[a[i]-1] = 1;
        else
            c++;
    }
    printf("%d\n", c);
    return 0;
}