#include <cstdio>
#include <vector>
typedef long long int64;
static const int64 INF = 1LL << 61;
static const int MAXN = 1e5 + 4;

int n;
int64 a[MAXN], b[MAXN];
std::vector<std::pair<int, int>> e[MAXN];

int64 surplus[MAXN];

void dfs(int u)
{
    surplus[u] += b[u] - a[u];
    for (auto p : e[u]) {
        dfs(p.first);
        if (surplus[p.first] >= 0) {
            surplus[u] += surplus[p.first];
        } else {
            if (-surplus[p.first] >= (INF - surplus[u]) / p.second)
                surplus[u] = -INF;
            else surplus[u] -= -surplus[p.first] * p.second;
        }
        if (surplus[u] == -INF) break;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%I64d", &b[i]);
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
    for (int i = 1, x, k; i < n; ++i) {
        scanf("%d%d", &x, &k); --x;
        e[x].push_back({ i, k });
    }

    dfs(0);
    puts(surplus[0] >= 0 ? "YES" : "NO");

    return 0;
}