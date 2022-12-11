#include <stdio.h>
#define MAXN 107

int main()
{
    short digit[MAXN] = {0}, n = 1;
    // The digit array will look like {0, 0, n0, x1, x2, x3, ...}
    while ((digit[++n] = getchar() - '0') != '\n' - '0');

    short i, j, k, ans, found = 0;
    for (i = 0; i < n - 2; ++i)
        for (j = i + 1; j < n - 1; ++j)
            for (k = j + 1; k < n; ++k)
                if ((ans = digit[i] * 100 + digit[j] * 10 + digit[k]) % 8 == 0) {
                    found = 1; goto finish;
                }

finish:
    if (found) printf("YES\n%d\n", ans);
    else puts("NO");
    return 0;
}