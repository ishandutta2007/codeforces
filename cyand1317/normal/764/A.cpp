#include <cstdio>
static const int MAXZ = 1e4 + 2;

int n, m, z;

int main()
{
    scanf("%d%d%d", &n, &m, &z);

    int ans = 0;
    for (int i = n; i <= z; i += n) if (i % m == 0) ++ans;

    printf("%d\n", ans);
    return 0;
}