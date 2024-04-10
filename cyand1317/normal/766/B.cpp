#include <cstdio>
#include <algorithm>
static const int MAXN = 1e5 + 4;

int n, a[MAXN];

// a <= b <= c
inline bool check(int a, int b, int c)
{
    return (a + b > c && b - a < c);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n);
    for (int i = 2; i < n; ++i) if (check(a[i - 2], a[i - 1], a[i])) { puts("YES"); return 0; }
    puts("NO"); return 0;
}