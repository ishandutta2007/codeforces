#include <stdio.h>
#define MAX2POWN 4100

int n, a[MAX2POWN], p[MAX2POWN], ans = 0;

int max(int a, int b)
{ return a > b ? a : b; }

void adjust(int root)
{
    if (root >= (1 << n)) return;

    adjust(root * 2); adjust(root * 2 + 1);
    p[root * 2] += a[root * 2]; p[root * 2 + 1] += a[root * 2 + 1];
    int m = max(p[root * 2], p[root * 2 + 1]);
    ans += m * 2 - (p[root * 2] + p[root * 2 + 1]);
    p[root] = m;
}

int main()
{
    int i;
    scanf("%d", &n);
    for (i = 2; i < (2 << n); ++i) scanf("%d", &a[i]);

    for (i = (1 << n); i < (2 << n); ++i) p[i] = 0;
    adjust(1);

    printf("%d\n", ans);
    return 0;
}