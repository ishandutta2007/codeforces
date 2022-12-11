#include <cstdio>
#include <algorithm>
static const int MAXN = 202;

int n, a[MAXN];

int main()
{
    scanf("%d", &n); n *= 2;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    std::sort(a, a + n);
    puts(a[n / 2 - 1] < a[n / 2] ? "YES" : "NO");

    return 0;
}