#include <stdio.h>
#include <string.h>
#define MAXN 100002

int main()
{
    char s[MAXN], t[MAXN];
    gets(s); gets(t);
    int n = strlen(s), hamming = 0, i;
    for (i = 0; i < n; ++i) if (s[i] != t[i]) ++hamming;
    if (hamming & 1) {
        puts("impossible");
    } else {
        for (i = 0; i < n; ++i)
            if (s[i] != t[i] && hamming) {
                putchar(s[i]); hamming -= 2;
            } else putchar(t[i]);
        putchar('\n');
    }
    return 0;
}