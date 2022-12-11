#include <cstdio>
static const int MAXN = 103;

int n, a[MAXN], max = -1, sum = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (max < a[i]) max = a[i];
        sum += a[i];
    }

    printf("%d\n", max * n - sum);
    return 0;
}