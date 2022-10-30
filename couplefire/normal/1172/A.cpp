#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, a[N], b[N], p[N], ans;

int main()
{
    int i, j;

    scanf("%d", &n);

    for (i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        p[a[i]] = 0;
    }

    for (i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        p[b[i]] = i;
    }

    if (p[1])
    {
        for (i = 2; p[i] == p[1] + i - 1; ++i);
        if (p[i - 1] == n)
        {
            for (j = i; j <= n && p[j] <= j - i; ++j);
            if (j > n)
            {
                printf("%d", n - i + 1);
                return 0;
            }
        }
    }

    for (i = 1; i <= n; ++i) ans = max(ans, p[i] - i + 1 + n);

    printf("%d", ans);

    return 0;
}