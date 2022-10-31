#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i;

    scanf("%d%d", &n, &m);

    printf("%d\n", m + n - 1);
    for (i=1; i<=m; i++)
        printf("1 %d\n", i);

    for (i=2; i<=n; i++)
        printf("%d 1\n", i);

    return 0;
}