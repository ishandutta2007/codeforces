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
#define rep(i,n) for(int i = -1; ++i < n; )

namespace Sol {

#define maxn 1010101
int n, m;
vi gr[maxn];
bool vis[maxn] = {0};

int p[maxn];
int setcnt;
int findp(int u) { return p[u] = u == p[u] ? u : findp(p[u]); }
void join(int u, int v) {
    u = findp(u), v = findp(v);
    if (u == v) return;
    --setcnt;
    p[u] = v;
}

int main() {
    cin >> n >> m;
    setcnt = 0;
    rep(i, n) p[i] = i;
    long tcnt = 0;
    rep(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        if (!vis[u]) ++setcnt; vis[u] = 1;
        if (!vis[v]) ++setcnt; vis[v] = 1;
        if (u == v) {
            tcnt ++;
            continue;
        }
        gr[u].push_back(v);
        gr[v].push_back(u);
        join(u, v);
    }
    if (setcnt != 1) cout << 0, exit(0);
    long ans = 0;
    for (int i = 0; i < n; ++i) {
        long ec = sz(gr[i]);
        ans += ec * (ec - 1) / 2;
    }
    ans += (m - tcnt) * tcnt;
    ans += tcnt * (tcnt - 1) / 2;
    cout << ans;
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return Sol::main();
}