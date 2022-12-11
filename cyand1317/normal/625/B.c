#include <stdio.h>
#include <string.h>
#define MAXN 100004
#define MAXM 32

int n, m;
char s[MAXN], t[MAXM];

int main()
{
    gets(s); n = strlen(s);
    gets(t); m = strlen(t);
    // We can use KMP here but that's not necessary = =
    int i, j;
    unsigned char matched;
    int ans = 0;
    for (i = 0; i <= n - m; ++i) {
        matched = 1;
        for (j = 0; j < m; ++j)
            if (s[i + j] != t[j]) { matched = 0; break; }
        if (matched) { ++ans; i += (m - 1); }
    }
    printf("%d\n", ans);
    return 0;
}