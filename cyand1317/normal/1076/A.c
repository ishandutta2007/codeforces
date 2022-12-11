#include <stdio.h>
#define MAXN    200004

int n;
char s[MAXN];

int main()
{
    scanf("%d%s", &n, s);

    int i, j;
    for (i = 0; i < n; ++i) if (s[i] > s[i + 1]) break;
    for (j = 0; j < n; ++j) if (i != j) putchar(s[j]);
    putchar('\n');

    return 0;
}