#include <stdio.h>
#define MAXN 10009

char s[MAXN] = { 0 };
char t[MAXN];

int main()
{
    gets(s);
    int m, i, l, r, k;
    scanf("%d", &m);
    do {
        scanf("%d%d%d", &l, &r, &k);
        --l;
        for (i = 0; i < r - l; ++i)
            t[l + (i + k) % (r - l)] = s[l + i];
        for (i = 0; i < r - l; ++i)
            s[l + i] = t[l + i];
    } while (--m);
    puts(s);
    return 0;
}