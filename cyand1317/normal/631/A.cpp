#include <cstdio>
static const int MAXN = 1005;

int n, a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    int a_sum = 0, b_sum = 0;
    for (int i = 0; i < n; ++i) a_sum |= a[i], b_sum |= b[i];
    printf("%d\n", a_sum + b_sum);
    return 0;
}