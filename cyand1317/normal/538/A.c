#include <stdio.h>
#include <string.h>
#define MAXLEN 106
const char *banner = "CODEFORCES";

int main()
{
    int blen = strlen(banner), slen;
    char s[MAXLEN];
    gets(s); slen = strlen(s);
    int i, j;
    i = 0; while (banner[i] == s[i]) ++i;
    j = blen - 1; while (banner[j] == s[j - blen + slen]) --j;
    puts(i + (blen - j - 1) >= blen ? "YES" : "NO");
    return 0;
}