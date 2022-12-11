#include <stdio.h>
#define MAXN 300006

int n, k;
short a[MAXN];

int main()
{
    int i, j;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; ++i) scanf("%hd", &a[i]);

    i = j = 0; int ct = 0;
    while (j < n && ct < k) { ct += !a[j]; ++j; }
    while (j < n && a[j]) ++j;
    int ans = j, ans_pos = 0;
    while (j < n) {
        while (a[i]) ++i;
        ++i;    // Go past the zero
        while (j < n && a[j]) ++j;
        if (j < n) ++j;     // Go past the zero
        while (j < n && a[j]) ++j;  // Go past the successive one's
        if (ans < j - i) { ans = j - i; ans_pos = i; }
    }

    printf("%d\n", ans);
    for (i = ans_pos; i < ans_pos + ans; ++i) a[i] = 1;
    for (i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');

    return 0;
}