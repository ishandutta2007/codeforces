#include <cstdio>
static const int MAXN = 100006;
static const int ALPHA = 28;

int n;
int ct[ALPHA] = { 0 };

int main()
{
    scanf("%d", &n); getchar();
    if (n > 26) { puts("-1"); return 0; }
    for (int i = 0; i < n; ++i) ++ct[getchar() - 'a'];
    int ans = 0;
    for (int i = 0; i < ALPHA; ++i) if (ct[i] > 1) ans += ct[i] - 1;
    printf("%d\n", ans);
    return 0;
}