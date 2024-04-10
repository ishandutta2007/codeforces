#include <cstdio>
static const int MAXN = 103;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - 1; ++j) if (a[j] > a[j + 1]) {
            int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            printf("%d %d\n", j + 1, j + 2);
        }

    return 0;
}