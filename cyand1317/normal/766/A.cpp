#include <cstdio>
#include <cstring>
static const int MAXN = 1e5 + 4;

char s[MAXN], t[MAXN];
int slen, tlen;

int main()
{
    gets(s); gets(t);
    slen = strlen(s); tlen = strlen(t);
    if (strcmp(s, t) == 0) puts("-1");
    else printf("%d\n", slen > tlen ? slen : tlen);
    return 0;
}