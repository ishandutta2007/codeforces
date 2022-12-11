#include <cstdio>
static const int MAXN = 5e5 + 4;

int n;
int x1[MAXN], x2[MAXN], y1[MAXN], y2[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);

    puts("YES");
    for (int i = 0; i < n; ++i)
        printf("%d\n", (x1[i] & 1) * 2 + (y1[i] & 1) + 1);

    return 0;
}