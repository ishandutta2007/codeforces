#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int i, j, n, p, uk, tt;

    scanf("%d", &tt);

    for (; tt; tt--) {
        scanf("%d%d", &n, &p);

        for (i=1, uk=0; i<=n; i++) {
            for (j=i+1; j<=n; j++) {
                printf("%d %d\n", i, j);
                uk++;
                if (uk == 2 * n + p)
                    break;
            }
            if (uk == 2 * n + p)
                break;
        }
    }

    return 0;
}