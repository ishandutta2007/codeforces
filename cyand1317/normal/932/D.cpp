#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int64 INF64 = 1LL << 61;
static const int MAXN = 400005;
static const int LOGN = 20;

static int q, n;
static int p[MAXN];
static int64 w[MAXN];
// anc[u][i] = the ancestor 2^i steps from u
// max[u][i] = maximum value on the path [u, anc[u][i])
// jmp[u][i] = the 2^i-th target from u
// sum[u][i] = the sum on target chain [u, jmp[u][i])
static int anc[MAXN][LOGN], jmp[MAXN][LOGN];
static int64 max[MAXN][LOGN], sum[MAXN][LOGN];

inline void process(int u)
{
    anc[u][0] = p[u];
    for (int i = 1; i < LOGN; ++i)
        anc[u][i] = (anc[u][i - 1] == -1) ? -1 : anc[anc[u][i - 1]][i - 1];
    max[u][0] = w[u];
    for (int i = 1; i < LOGN; ++i)
        max[u][i] = (anc[u][i - 1] == -1) ? INF64 : std::max(max[u][i - 1], max[anc[u][i - 1]][i - 1]);

    int t = p[u];
    for (int i = LOGN - 1; t != -1 && i >= 0; --i) {
        if (max[t][i] < w[u]) t = anc[t][i];
    }

    jmp[u][0] = t;
    for (int i = 1; i < LOGN; ++i)
        jmp[u][i] = (jmp[u][i - 1] == -1) ? -1 : jmp[jmp[u][i - 1]][i - 1];
    sum[u][0] = w[u];
    for (int i = 1; i < LOGN; ++i)
        sum[u][i] = (jmp[u][i - 1] == -1) ? INF64 : (sum[u][i - 1] + sum[jmp[u][i - 1]][i - 1]);
}

inline int64 query(int u, int64 x)
{
    int len = 0;
    for (int i = LOGN - 1; u != -1 && i >= 0; --i) {
        if (sum[u][i] <= x) {
            x -= sum[u][i];
            u = jmp[u][i];
            len += (1 << i);
        }
    }
    return len;
}

int main()
{
    scanf("%d", &q);

    n = 1;
    p[0] = -1;
    w[0] = 0;
    process(0);

    int64 last = 0;
    int op;
    int64 u, v;
    for (int i = 0; i < q; ++i) {
        scanf("%d%lld%lld", &op, &u, &v);
        u ^= last; v ^= last;
        if (op == 1) {
            p[n] = --u;
            w[n] = v;
            process(n++);
        } else if (op == 2) {
            --u;
            printf("%lld\n", last = query(u, v));
        } else puts("> <");
    }

    return 0;
}