#include <stdio.h>

int main()
{
    int a, b, ans = 0;
    scanf("%d%d", &a, &b);
    while (a > 0 && b > 0 && !(a == 1 && b == 1)) {
        ++ans;
        if (a <= b) { ++a; b -= 2; }
        else { ++b; a -= 2; }
    }
    printf("%d\n", ans);
    return 0;
}