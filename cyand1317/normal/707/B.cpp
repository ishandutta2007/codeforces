#include <cstdio>
#include <utility>
#include <vector>
static const int INF = 0x7fffffff;
static const int MAXN = 100006;
static const int MAXM = 100006;

int n, m, k;
int u[MAXM], v[MAXM], w[MAXM];
bool is_storage[MAXN] = { false };

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]); --u[i], --v[i];
    }
    int a_i;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a_i); --a_i;
        is_storage[a_i] = true;
    }

    int ans = INF;
    for (int i = 0; i < m; ++i)
        if ((is_storage[u[i]] ^ is_storage[v[i]]) && ans > w[i])
            ans = w[i];
    printf("%d\n", ans == INF ? -1 : ans);

    return 0;
}