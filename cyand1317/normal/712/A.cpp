#include <cstdio>
typedef long long int64;
static const int MAXN = 100006;

int n;
int a[MAXN];
int64 b[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    b[n - 1] = a[n - 1];
    for (int i = n - 2, s = b[n - 1]; i >= 0; --i, s = -s) {
        b[i] = a[i] + s;
        s -= b[i];
    }

    for (int i = 0; i < n; ++i) printf("%I64d%c", b[i], i == n - 1 ? '\n' : ' ');

    return 0;
}