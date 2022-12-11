#include <cstdio>
static const int MAXN = 200004;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] % 2 == 0) a[i] = 0;
        else { --a[i]; if (--a[i + 1] < 0) { puts("NO"); return 0; } }
    }

    puts(a[n - 1] % 2 == 0 ? "YES" : "NO");

    return 0;
}