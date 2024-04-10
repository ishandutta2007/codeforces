#include <cstdio>
static const int MAXN = 1e5 + 6;
static const int MAXA = 2e5 + 6;

int n, x;
int ai, ct[MAXA] = { 0 };

int main()
{
    scanf("%d%d", &n, &x);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ai);
        ++ct[ai];
        ans += ct[ai ^ x];
        if (x == 0) --ans;
    }

    printf("%I64d\n", ans);
    return 0;
}