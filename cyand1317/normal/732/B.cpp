#include <cstdio>
static const int MAXN = 504;

int n, k;
int a[MAXN], b[MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) { scanf("%d", &a[i]); b[i] = a[i]; }

    for (int i = 1; i < n; ++i)
        if (b[i - 1] + b[i] < k) b[i] += (k - (b[i - 1] + b[i]));

    int sum = 0;
    for (int i = 0; i < n; ++i) sum += b[i] - a[i];
    printf("%d\n", sum);
    for (int i = 0; i < n; ++i) printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');

    return 0;
}