#include <cstdio>
static const int MAXN = 2e5 + 3;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (i % 2 == 0) { int t = a[i]; a[i] = a[j]; a[j] = t; }
    }

    for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ' );
    return 0;
}