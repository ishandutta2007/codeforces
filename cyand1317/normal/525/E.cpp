#include <cstdio>
#include <map>
typedef long long int64;
static const int MAXN = 25;
static const int UBD_FACT = 18;

int n, k; int64 s;
int a[MAXN];
int64 fact[UBD_FACT + 1];
std::map<int64, int> count[MAXN + 1];

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= UBD_FACT; ++i) fact[i] = fact[i - 1] * i;

    scanf("%d%d%I64d", &n, &k, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int lhalf = n / 2, rhalf = n - lhalf;
    for (int i = 0; i < (1 << lhalf); ++i) {
        for (int j = 0; j < (1 << lhalf); ++j) if ((j & i) == j && __builtin_popcount(j) <= k) {
            bool valid = true;
            int64 sum = 0;
            for (int p = 0; p < lhalf; ++p) if (i & (1 << p)) {
                if (j & (1 << p)) {
                    if (a[p] > UBD_FACT) { valid = false; break; }
                    else sum += fact[a[p]];
                } else sum += a[p];
            }
            if (valid) {
                for (int sel = 0; sel <= k - __builtin_popcount(j); ++sel) ++count[sel][sum];
            }
        }
    }

    int64 ans = 0;
    for (int i = 0; i < (1 << rhalf); ++i) {
        for (int j = 0; j < (1 << rhalf); ++j) if ((j & i) == j && __builtin_popcount(j) <= k) {
            bool valid = true;
            int64 sum = 0;
            for (int p = 0; p < rhalf; ++p) if (i & (1 << p)) {
                if (j & (1 << p)) {
                    if (a[p + lhalf] > UBD_FACT) { valid = false; break; }
                    else sum += fact[a[p + lhalf]];
                } else sum += a[p + lhalf];
            }
            if (valid) ans += count[__builtin_popcount(j)][s - sum];
        }
    }

    printf("%I64d\n", ans);
    return 0;
}