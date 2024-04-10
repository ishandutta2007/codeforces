#include <cstdio>
#include <vector>
static const int MAXN = 1005;
static const int MAXW = 1005;
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n, m, tot_w;
int w[MAXN], b[MAXN];

namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    int root(int u) { return p[u] == u ? u : (p[u] = root(p[u])); }
    inline void unite(int u, int v) { u = root(u), v = root(v); static int w = 0; if (++w & 1) p[u] = v; else p[v] = u; }
}

int group_w[MAXN] = { 0 }, group_b[MAXN] = { 0 };
bool is_root[MAXN] = { false };
std::vector<int> root_ids;
std::vector<int> group_members[MAXN];
int f[MAXW];

int main()
{
    scanf("%d%d%d", &n, &m, &tot_w);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    int u, v;
    dsu::init(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        dsu::unite(u, v);
    }
    for (int i = 0; i < n; ++i) {
        int r = dsu::root(i);
        if (!is_root[r]) { is_root[r] = true; root_ids.push_back(r); }
        group_w[r] += w[i];
        group_b[r] += b[i];
        group_members[r].push_back(i);
    }

    for (std::vector<int>::iterator i = root_ids.begin(); i != root_ids.end(); ++i) {
        for (int j = tot_w; j >= 0; --j) {
            for (std::vector<int>::iterator k = group_members[*i].begin(); k != group_members[*i].end(); ++k)
                if (j + w[*k] <= tot_w) upd_max(f[j + w[*k]], f[j] + b[*k]);
            if (j + group_w[*i] <= tot_w) upd_max(f[j + group_w[*i]], f[j] + group_b[*i]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= tot_w; ++i) upd_max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}