#include <cstdio>
typedef long long int64;
static const int MAXN = 200006;
static const int BITS = 32;

int n;
int64 a[MAXN], b[MAXN], c[MAXN];
int ct[BITS] = { 0 };
int64 bb[MAXN], cc[MAXN];   // validation

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%I64d", &b[i]);
    for (int i = 0; i < n; ++i) scanf("%I64d", &c[i]);

    int64 sum_a = 0;
    for (int i = 0; i < n; ++i) sum_a += (b[i] + c[i]);
    sum_a /= (n + n);
    for (int i = 0; i < n; ++i) a[i] = (b[i] + c[i] - sum_a) / n;

    for (int i = 0; i < BITS; ++i)
        for (int j = 0; j < n; ++j) if (a[j] & (1LL << i)) ++ct[i];
    for (int i = 0; i < n; ++i) bb[i] = cc[i] = 0;
    for (int i = 0; i < BITS; ++i)
        for (int j = 0; j < n; ++j) {
            if (a[j] & (1LL << i)) {
                bb[j] += (1LL << i) * ct[i];
                cc[j] += (1LL << i) * n;
            } else {
                bb[j] += 0;
                cc[j] += (1LL << i) * ct[i];
            }
        }

    //for (int i = 0; i < n; ++i) printf("%I64d%c", bb[i], i == n - 1 ? '\n' : ' ');
    //for (int i = 0; i < n; ++i) printf("%I64d%c", cc[i], i == n - 1 ? '\n' : ' ');
    for (int i = 0; i < n; ++i)
        if (bb[i] != b[i] || cc[i] != c[i]) { puts("-1"); return 0; }
    for (int i = 0; i < n; ++i) printf("%I64d%c", a[i], i == n - 1 ? '\n' : ' ');

    return 0;
}