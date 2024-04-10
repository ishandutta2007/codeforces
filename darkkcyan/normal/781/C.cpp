#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()

namespace Solution {

int n, m, k;
vi p;
ve<vi> gr;
int findp(int u) { return p[u] = p[u] == u ? u : findp(p[u]); }
void join(int u, int v) {
    p[findp(u)] = findp(v);
}

vi ans;
void dfs(int u, int p) {
    ans.push_back(u);
    for (int i = -1; ++i < sz(gr[u]); ) {
        int v = gr[u][i];
        if (v == p) continue;
        dfs(v, u);
        ans.push_back(u);
    }
}

int main() {
    cin >> n >> m >> k;
    p.resize(n); for (int i = n; i--; ) p[i] = i;
    gr.resize(n);
    for (int i = -1; ++i < m; ) {
        int u, v; cin >> u >> v; --u, --v;
        if (findp(u) == findp(v)) continue;
        join(u, v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(0, 0);
    int s = sz(ans) / k;
    int u = 0;
    for (int i = -1; ++i < k; ) {
        int t = s + (i < sz(ans) % k);
        cout << t << ' ';
        for (int f = t; f--; ) cout << ans[u++] + 1 << ' ';
        cout << '\n';
    }


    return 0;
}}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    return Solution::main();
}