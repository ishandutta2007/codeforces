#include <cstdio>
static const int MAXN = 100007;
static const int MAXM = 100007;

int n, q;
int x_i;
int sum[MAXM] = { 0 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x_i);
        sum[x_i]++;
    }
    for (int i = 1; i < MAXM; ++i) sum[i] += sum[i - 1];

    scanf("%d", &q);
    do {
        scanf("%d", &x_i);
        if (x_i >= MAXM) printf("%d\n", n);
        else printf("%d\n", sum[x_i]);
    } while (--q);

    return 0;
}