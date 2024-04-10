#include <cstdio>
#include <cstdlib>
#include <algorithm>
static const int MAXN = 10003;
static const int MAXK = 102;

int n, k;
int a[MAXK];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) scanf("%d", &a[i]);
    srand(n + k + a[0] + a[k - 1] + a[n % k]);

    int aisle = n, window = 2 * n;

    int ct[4] = { 0, 0, 0, 0 };
    for (int i = 0; i < k; ++i) {
        while (a[i] >= 4) {
            a[i] -= 4;
            if (aisle > 0) aisle -= 1; else window -= 2;
        }
        if (a[i] > 0) ++ct[a[i]];
    }

    bool feas = false;
    for (int j = 0; j <= ct[3]; ++j) {
        ct[3] -= j; ct[1] += j; ct[2] += j; aisle -= ct[3];
        if (ct[3] >= 0 && aisle >= 0) for (int i = 0; i <= ct[2]; ++i) {
            ct[2] -= i; ct[1] += i * 2; ct[1] -= aisle;
            if (std::max(0, ct[1]) + ct[2] <= aisle + window) { feas = true; break; }
            ct[2] += i; ct[1] -= i * 2; ct[1] += aisle;
        }
        aisle += ct[3]; ct[3] += j; ct[1] -= j; ct[2] -= j;
        if (feas) break;
    }

    if (feas) {
        putchar('Y' + (rand() & 1) * 32);
        putchar('E' + (rand() & 1) * 32);
        putchar('S' + (rand() & 1) * 32);
        putchar('\n');
    } else {
        putchar('N' + (rand() & 1) * 32);
        putchar('O' + (rand() & 1) * 32);
        putchar('\n');
    }

    return 0;
}