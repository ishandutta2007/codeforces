#include <bits/stdc++.h>

using namespace std;

struct road {
    int number, ar;
};
struct fool {
    int l, m, r;
};
const int logmx = 21;
const int mx = 250000;
int n, k, p[mx], num[mx], dp[mx][logmx], din[mx], dout[mx], tim = 0, mark[mx], ans[mx];
vector<road> g[mx];
fool fools[mx];

bool upper(int a, int b) {
    return ((din[a] <= din[b]) && (dout[a] >= dout[b]));
}

void dfs_time (int v) {
    din[v] = ++tim;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i].ar != p[v]) {
            dfs_time(g[v][i].ar);
        }
    }
    dout[v] = ++tim;
}

void build_tree (int v) {
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i].ar != p[v]) {
            p[g[v][i].ar] = v;
            num[g[v][i].ar] = g[v][i].number;
            build_tree(g[v][i].ar);
        }
    }
}

void compute_dp_dfs (int v) {
    int v1;
    for (int i = 0; i < logmx; ++i) {
        if (i == 0) dp[v][i] = p[v];
        if (i > 0) dp[v][i] = dp[dp[v][i-1]][i-1];
    }
    for (int i = 0; i < g[v].size(); ++i) {
        v1 = g[v][i].ar;
        if (v1 != p[v]) compute_dp_dfs(v1);
    }
}

int lca (int a, int b) {
    if (upper (a, b)) return a;
    if (upper (b, a)) return b;
    for (int i = logmx - 1; i >= 0; --i) {
        if (! upper (dp[a][i], b)) a = dp[a][i];
    }
    return dp[a][0];
}

int dfs(int v) {
    int summ = 0, v1;
    for (int i = 0; i < g[v].size(); ++i) {
        v1 = g[v][i].ar;
        if (v1 != p[v]) summ += dfs(v1);
    }
    summ += mark[v];
    if (num[v] != -1) ans[num[v]] = summ;
    return summ;
}

int main()
{
    for (int i = 0; i < mx; ++i) {
        mark[i] = 0;
        ans[i] = 0;
    }
    cin >> n;
    int u, v;
    road r;
    for (int i = 0; i < (n - 1); ++i) {
        cin >> u >> v;
        r.ar = (v - 1);
        r.number = i;
        g[u - 1].push_back(r);
        r.ar = (u - 1);
        r.number = i;
        g[v - 1].push_back(r);
    }
    p[0] = 0; num[0] = -1;
    build_tree(0);
    compute_dp_dfs(0);
    dfs_time(0);
    cin >> k;
    int a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        fools[i].l = (a - 1);
        fools[i].r = (b - 1);
        fools[i].m = lca (a - 1, b - 1);
        mark[fools[i].l] += 1;
        mark[fools[i].m] -= 2;
        mark[fools[i].r] += 1;
    }
    dfs(0);
    for (int i = 0; i < (n - 1); ++i) cout << ans[i] << " ";
    return 0;
}