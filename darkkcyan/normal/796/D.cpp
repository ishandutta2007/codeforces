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
#define rep(i,n) for (int i = -1; ++i < n; )

namespace Sol {

#define maxn 301010
int col[maxn];
int n, k, d;
vi gr[maxn];
map<ii, int> eid;

ve<ii> ans;
queue<int> qu;

ii sii(int u, int v) { return u > v ? ii(u, v) : ii(v, u); }

int main() {
    cin >> n >> k >> d;
    memset(col, -1, sizeof col);
    rep(i, k) {
        int t; cin >> t;
        col[--t] = i;
        qu.push(t);
    }
    rep(i, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
        eid[sii(u, v)] = i + 1;
    }

    for (; qu.size(); qu.pop()) {
        int u = qu.front();
        for (auto v : gr[u]) {
            if (col[v] == col[u]) continue;
            if (col[v] != -1) {
                ans.push_back(sii(u, v));
                continue;
            }
            col[v] = col[u];
            qu.push(v);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << sz(ans) << '\n';
    rep(i, sz(ans)) cout << eid[ans[i]] << ' ';

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return Sol::main();
}