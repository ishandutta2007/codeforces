#include <stdio.h>

int main()
{
    float t, s, q;
    scanf("%f%f%f", &t, &s, &q);
    int ans = 0;
    while (s < t) {
        s *= q;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}