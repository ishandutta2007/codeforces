#include <cstdio>

int n, s, a_i, max_a = 0, sum_a = 0;

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a_i);
        if (max_a < a_i) max_a = a_i;
        sum_a += a_i;
    }
    puts(sum_a - max_a <= s ? "YES" : "NO");
    return 0;
}