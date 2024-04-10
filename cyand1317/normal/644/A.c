#include <stdio.h>
#define MAXN 128

int n, a, b;
int s[MAXN][MAXN] = {{ 0 }};

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    int c1 = 0, c2 = 0, i, j;
    for (i = 0; i < a; ++i)
        if (i & 1) {
            c1 += b - b / 2;
            c2 += b / 2;
        } else {
            c2 += b - b / 2;
            c1 += b / 2;
        }
    if (c1 < c2) { i = c1; c1 = c2; c2 = i; }
    if (c1 >= n - n / 2 && c2 >= n / 2) {
        int odd = -1, even = 0;
        for (i = 0; i < a; ++i)
            for (j = 0; j < b; ++j) {
                if ((i + j) & 1) s[i][j] = (even += 2);
                else s[i][j] = (odd += 2);
                if (s[i][j] > n) s[i][j] = 0;
            }
        for (i = 0; i < a; ++i) {
            printf("%d", s[i][0]);
            for (j = 1; j < b; ++j) printf(" %d", s[i][j]);
            putchar('\n');
        }
    } else {
        puts("-1");
    }
    return 0;
}