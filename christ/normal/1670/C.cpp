#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9 + 7;
vector<int> adj[MN];
bool done[MN];
bool vis[MN];
int sz;
bool dfs (int cur) {
    vis[cur] = true;
    ++sz;
    bool got = done[cur];
    for (int i : adj[cur]) if (!vis[i]) {
        got |= dfs(i);
    }
    return got;
}
void solve () {
    int n; scanf ("%d",&n);
    for (int i = 1; i <= n; i++) adj[i].clear();
    vector<int> posOf(n+1), a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        posOf[a[i]] = i;
        vis[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&b[i]);
    }
    for (int i = 1; i <= n; i++) {
        int v = posOf[b[i]];
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf ("%d",&x);
        if (x == 0) done[i] = 0;
        else done[i] = 1;
    }
    int ret = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        sz = 0;
        if (!dfs(i) && sz > 1) ret = ret * 2 % MOD;
    }
    printf ("%d\n",ret);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}