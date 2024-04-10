#include <stdio.h>
#define MAXS 200005

int main()
{
    int m, a, ct[MAXS], len = 0, i;
    char s[MAXS], ch;

    while ((ch = getchar()) != '\n') s[len++] = ch;
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &a);
        ct[a - 1]++;
    }

    for (i = 1; i < len / 2; i++) ct[i] += ct[i - 1];
    for (i = 0; i < len / 2; i++)
        putchar(ct[i] % 2 ? s[len - i - 1] : s[i]);
    for (i = len / 2; i < len; i++)
        putchar(ct[len - i - 1] % 2 ? s[len - i - 1] : s[i]);
    putchar('\n');

    return 0;
}