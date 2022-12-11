#include <cstdio>
typedef long long int64;
static const int MAXN = 100007;

int n, k;
int c[MAXN];
int id[MAXN];
bool is_capital[MAXN] = { false };

int main()
{
    scanf("%d%d", &n, &k);

    int64 sum_capital = 0, sum_all = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
        sum_all += c[i];
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &id[i]); --id[i];
        is_capital[id[i]] = true;
        sum_capital += c[id[i]];
    }

    int64 ans = 0;
    ans += sum_capital * sum_all;
    for (int i = 0; i < k; ++i) {
        ans -= (int64)c[id[i]] * c[id[i]];
        sum_capital -= c[id[i]];
        ans -= sum_capital * c[id[i]];
    }
    for (int i = 0; i < n; ++i) if (!is_capital[i] && !is_capital[(i + 1) % n]) {
        ans += (int64)c[i] * c[(i + 1) % n];
    }
    printf("%I64d\n", ans);

    return 0;
}