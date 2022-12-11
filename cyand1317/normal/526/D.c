#include <stdio.h>
#define MAXN 1000004

int main()
{
    int n, k, i, j = -1;
    int pre[MAXN];
    char s[MAXN];
    scanf("%d%d\n", &n, &k);
    s[0] = getchar(); pre[0] = -1;
    for (i = 1; i < n; ++i) {
        s[i] = getchar();
        while (j != -1 && s[j + 1] != s[i]) j = pre[j];
        if (s[j + 1] == s[i]) ++j;
        pre[i] = j;
    }
    for (i = 0; i < n; ++i) {
        // P = (regexp)((AB)+A) = (regexp)(S+T?) where T is a prefix of S
        // Assume that S appears R times
        // See the editorial
        int r = (i + 1) / (i - pre[i]);
        putchar(r / k - r % k > 0
            || ((i + 1) % (i - pre[i]) == 0 && r / k - r % k == 0) ?
            '1' : '0');
    }
    return 0;
}