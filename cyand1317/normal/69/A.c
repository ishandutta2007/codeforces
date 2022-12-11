// Long time no C.
// Goodbye, October. Hello, November.
#include <stdio.h>
#define MAXN 104

int x_sum = 0, y_sum = 0, z_sum = 0;
int n, x, y, z;

int main()
{
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        x_sum += x; y_sum += y; z_sum += z;
    }

    puts(x_sum == 0 && y_sum == 0 && z_sum == 0 ? "YES" : "NO");
    return 0;
}