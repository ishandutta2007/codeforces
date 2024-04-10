/**
 *  created: 02/05/2021, 19:06:04
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, m, x, sz[max_n];
long long a[max_n], val[max_n];
int U[max_n], V[max_n], used[max_n];
vector<int> g[max_n], g_all[max_n], ans;

void dfs_tree(int v) {
    used[v] = 1;
    val[v] = a[v];
    for (int id : g_all[v]) {
        const int to = v ^ U[id] ^ V[id];
        if (!used[to]) {
            dfs_tree(to);
            g[v].push_back(id);
            g[to].push_back(id);
            val[v] += val[to] - x;
        }
    }
}

void solve(int root, int p) {
    vector<pair<long long, int>> all;
    vector<int> bad;
    for (int id : g[root]) {
        const int to = root ^ U[id] ^ V[id];
        if (to == p) {
            continue;
        }
        if (val[to] >= 0) {
            all.push_back({val[to], id});
            solve(to, root);
        } else {
            bad.push_back(id);
        }
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (auto p : all) {
        assert(p.first + a[root] >= x);
        a[root] += p.first - x;
        ans.push_back(p.second);
    }
    for (int id : bad) {
        const int to = root ^ U[id] ^ V[id];
        assert(a[root] >= x - val[to]);
        ans.push_back(id);
        a[root] -= x - val[to];
        a[to] -= val[to];
        solve(to, root);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; ++i) {
        int A;
        scanf("%d", &A);
        a[i] = A;
    }
    if (accumulate(a, a + n, 0LL) < 1LL * (n - 1) * x) {
        puts("NO");
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &U[i], &V[i]);
        --U[i];
        --V[i];
        g_all[U[i]].push_back(i);
        g_all[V[i]].push_back(i);
    }
    dfs_tree(0);
    solve(0, -1);
    puts("YES");
    for (int id : ans) {
        printf("%d\n", 1 + id);
    }
    return 0;
}