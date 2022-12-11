#include <cstdio>
#include <cstring>
static const int MAXN = 109;

int sl = 0, tl = 0;
char s[MAXN], t[MAXN];

int main()
{
    while ((s[sl] = getchar()) >= '0' && s[sl] <= '9') ++sl; s[sl] = '\0';
    while ((t[tl] = getchar()) >= '0' && t[tl] <= '9') ++tl; t[tl] = '\0';
    puts(strcmp(s, t) == 0 ? s : "1");
    return 0;
}