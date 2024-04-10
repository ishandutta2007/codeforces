#include <cstdio>
typedef long long int64;
static const int MAXN = 52;

int n; int64 k;
int64 freestyle[MAXN];
int ans[MAXN];

int main()
{
    scanf("%d%I64d", &n, &k);

    freestyle[0] = freestyle[1] = 1;
    for (int i = 2; i < MAXN; ++i) freestyle[i] = freestyle[i - 1] + freestyle[i - 2];

    for (int i = 1; i <= n; ) {
        if (k <= freestyle[n - i]) {
            ans[i - 1] = i; i += 1;
        } else {
            k -= freestyle[n - i];
            ans[i - 1] = i + 1; ans[i] = i; i += 2;
        }
    }

    for (int i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    return 0;
}