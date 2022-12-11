#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

static const int MAXN = 2e5 + 4;
static const int MAXK = 2e5 + 3;

static int n, k;
static std::pair<int, int> p[MAXN];
static int idx[MAXN];

static std::vector<int> q[MAXN];
static int ans[MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    for (int i = 0, u, v; i < k; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        q[u].push_back(v);
        q[v].push_back(u);
    }

    std::sort(p, p + n);
    for (int i = 0; i < n; ++i) idx[p[i].second] = i;

    for (int i = 0, j; i < n; ) {
        for (j = i + 1; j < n && p[j].first == p[i].first; ++j) ;
        for (int count = i; i < j; ++i) {
            int r = count;
            for (int t : q[p[i].second]) if (p[idx[t]].first < p[i].first) --r;
            ans[p[i].second] = r;
        }
    }

    for (int i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    return 0;
}