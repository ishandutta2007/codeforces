#include <stdio.h>
#define LLINF 0x7fffffffffffffffLL

int main()
{
    long long l, r, k;
    long long cur;
    unsigned char printed = 0;
    scanf("%I64d%I64d%I64d", &l, &r, &k);
    cur = 1;
    while (cur < l) {
        if (LLINF / k >= cur) cur *= k;
        else cur = LLINF;
    }
    while (cur <= r) {
        printed = 1; printf("%I64d ", cur);
        if (LLINF / k >= cur) cur *= k;
        else cur = LLINF;
    }
    if (printed) putchar('\n'); else puts("-1");
    return 0;
}