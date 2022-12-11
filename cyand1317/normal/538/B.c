#include <stdio.h>
#include <string.h>
#define MAXLEN 10

int main()
{
    int n, i = 0, maxdigit = -1;
    int digits[MAXLEN] = {0};
    scanf("%d", &n);
    while (n) {
        if (n % 10 > maxdigit) maxdigit = n % 10;
        digits[i++] = n % 10;
        n /= 10;
    }
    printf("%d\n", maxdigit);
    do {
        int ans = 0;
        for (i = MAXLEN - 1; i >= 0; --i)
            if (digits[i]) {
                --digits[i];
                ans = ans * 10 + 1;
            } else ans *= 10;
        if (ans) printf("%d ", ans);
        else break;
    } while (1);
    putchar('\n');
    return 0;
}