#include <stdio.h>
#define MAXN 103

int main()
{
    int n, i, j, good = 0; unsigned short a[MAXN];
    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) a[i] = getchar() == '*';
    for (i = 0; i < n; ++i) if (a[i]) {
        for (j = 1; j < n; ++j) {
            if (i + j * 4 >= n) break;
            else if (a[i + j] && a[i + j + j]
                && a[i + j + j + j] && a[i + j + j + j + j]) {
                good = 1;
                break;
            }
        }
        if (good) break;
    }
    puts(good ? "yes" : "no");
    return 0;
}