#include <stdio.h>
#define HOUSE 1234567
#define CAR   123456
#define COM   1234

int main()
{
    int n, a, b;
    scanf("%d", &n);
    for (a = 0; a * HOUSE <= n; ++a)
        for (b = 0; a * HOUSE + b * CAR <= n; ++b)
            if ((n - a * HOUSE - b * CAR) % COM == 0) {
                puts("YES");
                return 0;
            }
    puts("NO");
    return 0;
}