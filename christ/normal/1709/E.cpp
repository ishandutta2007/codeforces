#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9 + 7, MM = 1e5;
vector<int> adj[MN];
vector<int> a;
int ans;
int sz[MN], lz[MN];
set<int> wee[MN];
void dfs (int cur, int p = -1) {
    sz[cur] = 1;
    int big = -1;
    for (int i : adj[cur]) if (i != p) {
        dfs(i,cur);
        sz[cur] += sz[i];
        if (big == -1 || sz[i] > sz[big]) big = i;
    }
    if (big == -1) {
        wee[cur] = {a[cur]};
        return;
    }
    swap(wee[cur],wee[big]);
    lz[cur] = lz[big] ^ a[cur];
    for (int i : adj[cur]) if (i != p && i != big) {
        for (int j : wee[i]) {
            int togo = j ^ lz[i] ^ a[cur] ^ lz[cur];
            if (wee[cur].count(j ^ lz[i] ^ lz[cur])) {
                ++ans;
                wee[cur].clear(); lz[cur] = 0;
                goto succ;
            }
        }
        for (int j : wee[i]) {
            wee[cur].insert(j ^ lz[i] ^ a[cur] ^ lz[cur]);
        }
    }
    wee[cur].insert(a[cur] ^ lz[cur]);
    if (wee[cur].count(lz[cur])) {
        ++ans; wee[cur].clear(); lz[cur] = 0;
    }
    succ:;
}
int main () {
    int n; scanf ("%d",&n);
    a.resize(n+1);
    for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
    for (int i = 1; i < n; i++) {
        int u,v; scanf ("%d %d",&u,&v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
    ans = 0;
    dfs(1);
    printf ("%d\n",ans);
    return 0;
}