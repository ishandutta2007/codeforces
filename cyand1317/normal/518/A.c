#include <stdio.h>
#define MAXN 103
#define NOSOL_MSG "No such string"

int main()
{
    int n = 0, i = 0, valid = 0; char ch, s[MAXN];
    while ((s[n++] = getchar()) != '\n');
    for (i = --n - 1; i >= 0; --i) if (s[i] != 'z') break;
    if (i == -1) {
        puts(NOSOL_MSG);
        return 0;
    }
    for (s[i++]++; i < n; i++) s[i] = 'a';
    s[n] = 0; i = 0;
    while ((ch = getchar()) != '\n') {
        if (ch > s[i++]) { valid = 1; break; }
    }
    if (valid) puts(s);
    else puts(NOSOL_MSG);
    return 0;
}