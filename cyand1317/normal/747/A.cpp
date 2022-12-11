#include <cstdio>

int n;
int best_a, best_b;

int main()
{
    scanf("%d", &n);
    for (int a = 1; a * a <= n; ++a) if (n % a == 0) {
        best_a = a; best_b = n / a;
    }

    printf("%d %d\n", best_a, best_b);
    return 0;
}