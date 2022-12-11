#include <cstdio>
#include <algorithm>
using std::min;
typedef long long int64;
static const int MAXN = 1e5 + 6;
static const int LOGK = 36;

int n;
int64 k;
int f[MAXN], w[MAXN];
int64 sum[MAXN][LOGK], mnw[MAXN][LOGK], jmp[MAXN][LOGK];

int main()
{
    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &f[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);

    for (int u = 0; u < n; ++u) {
        sum[u][0] = mnw[u][0] = w[u];
        jmp[u][0] = f[u];
    }
    for (int i = 1; i < LOGK; ++i)
        for (int u = 0; u < n; ++u) {
            sum[u][i] = sum[u][i - 1] + sum[jmp[u][i - 1]][i - 1];
            mnw[u][i] = min(mnw[u][i - 1], mnw[jmp[u][i - 1]][i - 1]);
            jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
        }
    for (int i = 0; i < n; ++i) {
        int u = i;
        int64 s = 0, m = 1LL << 62;
        for (int j = 0; j < LOGK; ++j) if (k & (1LL << j)) {
            s += sum[u][j];
            m = min(m, mnw[u][j]);
            u = jmp[u][j];
        }
        printf("%I64d %I64d\n", s, m);
    }

    return 0;
}