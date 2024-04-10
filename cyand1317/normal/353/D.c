#include <stdio.h>
#define MAXN 1000002
int max(int a, int b) { return a > b ? a : b; }

int n;
char s[MAXN];

int main()
{
    n = 0;
    while ((s[n] = getchar()) == 'M' || s[n] == 'F') ++n;

    int i;
    int f_ct = 0, last = 0;
    for (i = 0; i < n && s[i] == 'F'; ++i) ;
    f_ct = i;
    for (; i < n; ++i) if (s[i] == 'F') {
        last = max(last + 1, i - f_ct);
        f_ct++;
    }
    printf("%d\n", last);

    return 0;
}