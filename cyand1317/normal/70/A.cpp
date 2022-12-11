#include <cstdio>
static const int MODULUS = 1e6 + 3;

int n;

int main()
{
    scanf("%d", &n);

    int ans = 1;
    for (int i = 1; i < n; ++i) ans = (ans * 3) % MODULUS;

    printf("%d\n", ans);
    return 0;
}