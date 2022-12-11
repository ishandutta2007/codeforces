#include <cstdio>
static const int MAXN = 100004;

int n, x;
int a[MAXN];
int sum = 0;

int main()
{
    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    puts(sum + n - 1 == x ? "YES" : "NO");
    return 0;
}