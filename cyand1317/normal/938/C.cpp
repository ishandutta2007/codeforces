#include <cmath>
#include <cstdio>

void work()
{
    int x; scanf("%d", &x);
    if (x == 0) puts("1 1");
    else {
        // i^2 - (i / <?>)^2 == x
        // i^2 <= 4x / 3
        for (int i = (int)ceil(sqrt(x + 1)); i * i <= 2 * x; ++i) {
            int j = i * i - x;
            int sqrt_j = (int)floor(sqrt(j));
            if (sqrt_j * sqrt_j == j) {
                // i / <?> == sqrt_j
                int k = i / sqrt_j;
                if (k && i / k == sqrt_j) {
                    printf("%d %d\n", i, k); return;
                } else if (i / (k + 1) == sqrt_j) {
                    printf("%d %d\n", i, k + 1); return;
                }
            }
        }
        puts("-1");
    }
}

int main()
{
    int T; scanf("%d", &T);
    do work(); while (--T);
    return 0;
}