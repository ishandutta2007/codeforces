#include <stdio.h>
#define MAXLEN 100008

int len = 0;
char s[MAXLEN];

int main()
{
    while ((s[len] = getchar()) >= '0' && s[len] <= '9') ++len;
    int i;
    for (i = 0; i < len; ++i) putchar(s[i]);
    for (--i; i >= 0; --i) putchar(s[i]);
    putchar('\n');
    return 0;
}