#include <cstdio>
static const int MAXN = 1e5 + 6;

int n, a, b;
int c[MAXN];

int main()
{
    scanf("%d%d%d", &n, &a, &b); getchar();
    for (int i = 0; i < n; ++i) c[i] = getchar() - '0';
    puts(c[a - 1] == c[b - 1] ? "0" : "1");
    return 0;
}