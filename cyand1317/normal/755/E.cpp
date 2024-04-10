// (`) PolandBall is sad
#include <cstdio>
static const int MAXN = 1004;

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    if (k > 3 || k == 1 || n <= 3 || (k == 2 && n == 4)) { puts("-1"); return 0; }

    if (k == 2) {
        printf("%d\n", n - 1);
        for (int i = 0; i < n - 1; ++i) printf("%d %d\n", i + 1, i + 2);
    } else {    // k == 3
        printf("%d\n", 3 + (n - 4) * 2);
        printf("1 2\n2 3\n3 4\n");
        for (int i = 5; i <= n; ++i) printf("%d %d\n%d %d\n", i, 2, i, 3);
    }

    return 0;
}