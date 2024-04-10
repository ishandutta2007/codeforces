#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
vector<array<int,2>> adj[MN];
set<int> at[MN];
vector<int> szs[MN];
int st[MN], ed[MN], sz[MN], wot[MN], howmany[MN], tt;
long long ans;
void init (int cur, int p = -1) {
    st[cur] = ++tt;
    wot[tt] = cur;
    sz[cur] = 1;
    for (auto [i,w] : adj[cur]) if (i != p) {
        init(i,cur);
        sz[cur] += sz[i];
    }
    ed[cur] = tt;
}
void dfs (int cur, int p = -1, int pe = -1) {
    for (auto [i,w] : adj[cur]) if (i != p) {
        dfs(i, cur, w);
    }
    if (pe == -1) {
        for (int c = 0; c < MN; c++) if (!at[c].empty()) {
            int cnt = sz[cur];
            for (int i : at[c]) cnt -= sz[wot[i]];
            for (int i : at[c]) ans += (long long)cnt * howmany[wot[i]];
            szs[c].push_back(cnt);
        }
    } else {
        auto ist = at[pe].lower_bound(st[cur]);
        auto ied = at[pe].upper_bound(ed[cur]);
        vector<int> to_del;
        int cnt = sz[cur];
        for (auto it = ist; it != ied; ++it) {
            int x = *it;
            to_del.push_back(x);
            cnt -= sz[wot[x]];
        }
        for (int i : to_del) {
            ans += (long long)cnt * howmany[wot[i]];
            at[pe].erase(i);
        }
        at[pe].insert(st[cur]);
        howmany[cur] = cnt;
        szs[pe].push_back(cnt);
    }
}
int main () {
    int n; scanf ("%d",&n);
    for (int i = 1; i < n; i++) {
        int u,v,x; scanf ("%d %d %d",&u,&v,&x);
        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }
    init(1);
    dfs(1);
    printf ("%lld\n",ans);
    return 0;
}