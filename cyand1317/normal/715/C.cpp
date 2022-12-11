#include <cstdio>
#include <algorithm>
#include <map>
typedef long long int64;
static const int MAXN = 1e5 + 4;
static const int MAXM = 1e9 + 8;

int n, mod, inv10;
#define _ % mod
int pow10[MAXN], pow10inv[MAXN];
int head[MAXN], dest[MAXN * 2], tag[MAXN * 2], next[MAXN * 2];

inline int phi(int m) {
    int ret = m;
    for (int i = 2; i * i <= m; ++i) if (m % i == 0) {
        ret = ret / i * (i - 1);
        do m /= i; while (m % i == 0);
    }
    if (m > 1) ret = ret / m * (m - 1);
    return ret;
}
inline int fpow(int base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) ans = ans * base _;
        base = (int64)base * base _;
    }
    return (int)ans;
}

int64 ans = 0;
bool marked[MAXN] = { false };
int sts[MAXN];
int up[MAXN], down[MAXN];
std::map<int, int> all, child[MAXN];

void calc_sts(int u, int p = -1) {
    sts[u] = 1;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p && !marked[dest[w]]) {
        calc_sts(dest[w], u);
        sts[u] += sts[dest[w]];
    }
}
int calc_centroid(int u, int cc_sz, int p = -1) {
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p && !marked[dest[w]]) {
        if (sts[dest[w]] * 2 > cc_sz) return calc_centroid(dest[w], cc_sz, u);
    }
    return u;
}
void dfs_subproblem(int u, int p = -1, int d = 0) {
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p && !marked[dest[w]]) {
        down[dest[w]] = ((int64)down[u] * 10 + tag[w])_;
        up[dest[w]] = ((int64)tag[w] * pow10[d] + up[u])_;
        dfs_subproblem(dest[w], u, d + 1);
    }
}
void add_subtree_to_map(int u, int st, int p = -1) {
    all[up[u]] += 1;
    child[st][up[u]] += 1;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p && !marked[dest[w]]) {
        add_subtree_to_map(dest[w], st, u);
    }
}
void count_subtree_to_ans(int u, int st, int p = -1, int d = 1) {
    int64 expected_up = (mod - ((int64)down[u] * pow10inv[d])_)_;
    ans += (all[expected_up] - child[st][expected_up]);
    if (up[u] == 0) ++ans;
    if (down[u] == 0) ++ans;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p && !marked[dest[w]]) {
        count_subtree_to_ans(dest[w], st, u, d + 1);
    }
}
void solve_subproblem(int u) {
    calc_sts(u);
    int c = calc_centroid(u, sts[u]);
    marked[c] = true;
    // (1) Divide
    for (int w = head[c]; w != -1; w = next[w]) if (!marked[dest[w]]) {
        solve_subproblem(dest[w]);
    }
    // (2) Conquer
    down[c] = up[c] = 0;
    dfs_subproblem(c);
    int64 prev = ans;
    all.clear();
    for (int w = head[c]; w != -1; w = next[w]) if (!marked[dest[w]]) {
        child[dest[w]].clear();
        add_subtree_to_map(dest[w], dest[w]);
    }
    for (int w = head[c]; w != -1; w = next[w]) if (!marked[dest[w]]) {
        count_subtree_to_ans(dest[w], dest[w]);
    }
    // Pack up
    marked[c] = false;
}

inline void add_edge(const int u, const int v, const int t) {
    static int w = 0;
    dest[w] = v; tag[w] = t; next[w] = head[u]; head[u] = w++;
    dest[w] = u; tag[w] = t; next[w] = head[v]; head[v] = w++;
}

int main()
{
    scanf("%d%d", &n, &mod);
    inv10 = fpow(10, phi(mod) - 1);
    pow10[0] = pow10inv[0] = 1;
    for (int i = 0; i < n; ++i) {
        pow10[i + 1] = (int64)pow10[i] * 10 _;
        pow10inv[i + 1] = (int64)pow10inv[i] * inv10 _;
    }

    for (int i = 0; i < n; ++i) head[i] = -1;
    int ui, vi, wi;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d", &ui, &vi, &wi);
        add_edge(ui, vi, wi);
    }

    solve_subproblem(0);
    printf("%I64d\n", ans);

    return 0;
}