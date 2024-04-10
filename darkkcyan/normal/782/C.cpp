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

int n, k;
ve<vi> gr;
vi ans;

void dfs(int u, int p) {
    int curc = 1;
    for (int i = -1; ++i < sz(gr[u]); ) {
        int v = gr[u][i];
        if (v == p) continue;
        while (curc == ans[u] or curc == ans[p]) ++curc;
        ans[v] = curc++;
        dfs(v, u);
    }
}

int main() {
    cin >> n;
    gr.resize(n);
    for (int i = 0; ++i < n; ) {
        int u, v; cin >> u >> v; --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    k = 0;
    for (int i = -1; ++i < n; ) k = max(k, sz(gr[i]));
    ++k;
    ans.assign(n, -1);
    ans[0] = 1;
    dfs(0, 0);

    cout << k << '\n';
    for (int i = -1; ++i < n; ) cout << ans[i] << ' ';

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