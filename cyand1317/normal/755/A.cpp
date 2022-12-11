#include <cstdio>

int n, m;

int main()
{
    scanf("%d", &n);
    for (m = 1; m <= 1000; ++m) {
        int t = n * m + 1;
        for (int i = 2; i * i <= t; ++i) if (t % i == 0) {
            printf("%d\n", m); return 0;
        }
    }
    return 0;
}