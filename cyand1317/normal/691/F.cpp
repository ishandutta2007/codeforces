#include <cstdio>
typedef long long int64;
static const int MAXN = 1e6 + 4;
static const int MAXP = 3e6 + 4;

int n, q, p;
int ct[MAXP];
int64 cp[MAXP] = { 0 }; // (x

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q); ++ct[q];
    }

    for (int i = 1; i < MAXP; ++i) {
        for (int j = 1; (int64)i * j < MAXP; ++j) {
            if (j == i) cp[i * j] += (int64)ct[i] * (ct[i] - 1);
            else cp[i * j] += (int64)ct[i] * ct[j];
        }
    }
    for (int i = 1; i < MAXP; ++i) cp[i] += cp[i - 1];
    scanf("%d", &q);
    do {
        scanf("%d", &p);
        printf("%I64d\n", (int64)n * (n - 1) - cp[p - 1]);
    } while (--q);
    return 0;
}