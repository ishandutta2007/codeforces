#include <stdio.h>
unsigned long long a[12800];
int top = 0;

int main()
{
    int i, j;
    unsigned long long n = (unsigned long long)-1;
    for (i = 63; i >= 1; --i) {
        n ^= (1LL << i);
        for (j = i - 2; j >= 0; --j) {
            n ^= (1LL << j);
            a[top++] = n;
            n ^= (1LL << j);
        }
    }
    unsigned long long lb, ub;
    int ans = 0;
    scanf("%I64u%I64u", &lb, &ub);
    for (i = 0; i < top; ++i) {
        if (a[i] >= lb && a[i] <= ub) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}