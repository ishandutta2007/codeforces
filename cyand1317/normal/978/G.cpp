#include <cstdio>
#include <set>
#include <utility>
#include <vector>

static const int MAXN = 103;
static const int MAXM = MAXN;

static int n, m;
static int s[MAXM], d[MAXM], c[MAXM];

static std::vector<int> start[MAXN];
static std::set<std::pair<int, int>> in;
static bool has_exam[MAXN] = { false };

static bool valid = true;
static int ans[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &s[i], &d[i], &c[i]); --s[i], --d[i];
        start[s[i]].push_back(i);
        has_exam[d[i]] = true;
    }

    for (int i = 0; i < n; ++i) {
        for (int u : start[i]) in.insert({d[u] - 1, u});
        if (has_exam[i]) {
            ans[i] = m + 1;
        } else if (!in.empty()) {
            std::pair<int, int> p = *in.begin();
            if (p.first < i) { valid = false; break; }
            ans[i] = p.second + 1;
            if (--c[p.second] == 0) in.erase(in.begin());
        } else {
            ans[i] = 0;
        }
    }

    for (int i = 0; i < m; ++i) if (c[i] > 0) { valid = false; break; }
    if (valid)
        for (int i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    else puts("-1");

    return 0;
}