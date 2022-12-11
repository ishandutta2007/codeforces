#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

typedef long long int64;
static const int MAXN = 2e5 + 4;

static int n, m;
static std::vector<std::pair<int, int64>> e[MAXN];
static int64 a[MAXN];

static int64 f[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    int64 w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%I64d", &u, &v, &w); --u, --v;
        e[u].push_back({v, w * 2});
        e[v].push_back({u, w * 2});
    }
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);

    std::priority_queue<
        std::pair<int64, int>,
        std::vector<std::pair<int64, int>>,
        std::greater<std::pair<int64, int>>
    > q;
    for (int i = 0; i < n; ++i) {
        f[i] = a[i];
        q.push({f[i], i});
    }
    while (!q.empty()) {
        std::pair<int64, int> r;
        do { r = q.top(); q.pop(); } while (f[r.second] != r.first && !q.empty());
        if (f[r.second] != r.first) break;
        for (auto w : e[r.second]) {
            if (f[w.first] > r.first + w.second) {
                f[w.first] = r.first + w.second;
                q.push({f[w.first], w.first});
            }
        }
    }

    for (int i = 0; i < n; ++i) printf("%I64d%c", f[i], i == n - 1 ? '\n' : ' ');

    return 0;
}