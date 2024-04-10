#include <cstdio>
typedef long long int64;
static const int MAXN = 1e6 + 4;
static const int MAXA = 1e6 + 3;

int n, a[MAXN];
int last[MAXN];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < MAXA; ++i) last[i] = -1;
    int64 ans = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ans += (int64)(i - last[a[i]]) * (n - i);
        last[a[i]] = i;
    }

    ans = ans * 2 - n;
    printf("%.8lf\n", (double)ans / n / n);

    return 0;
}