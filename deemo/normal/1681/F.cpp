#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define tm kljasdf
#define F first
#define S second

const int MAXN = 5e5 + 10;

int n;
vector<pii> adj[MAXN];
int st[MAXN], ft[MAXN], tm, sub[MAXN];
int ft2[MAXN], tm2;
pii edges[MAXN]; int ec;

void dfs(int v, int p = -1, int pw = -1) {
    st[v] = tm++;   tm2++;
    sub[v] = 1;
    if (~p)
        edges[ec++] = {pw, v};

    for (auto e: adj[v]) {
        int u = e.F, w = e.S;
        if (u == p) continue;
        dfs(u, v, w);
        sub[v] += sub[u];
    }
    ft[v] = tm;
    ft2[v] = tm2++;
}

int sec[MAXN], dn[MAXN], anc[MAXN];
int fen[MAXN];

void add_fen(int v, int val) {
    for (; v<MAXN; v+=v&-v)
        fen[v] += val;
}

int get_fen(int v) {
    int res = 0;
    for (; v; v-=v&-v)
        res += fen[v];
    return res;
}

int tl[MAXN], tr[MAXN];
ll count(int l, int r) {
    int sz = 0;
    for (int i = l; i < r; i++)
        sec[sz++] = edges[i].S;
    sort(sec, sec + sz, [](int u, int v) {
            return st[u] < st[v];
            });

    for (int i = sz-1; ~i; i--) {
        int v = sec[i];
        dn[v] = sub[v] - (get_fen(ft[v]) - get_fen(st[v]));
        add_fen(st[v]+1, dn[v]);
    }

    set<pii> fts;
    for (int i = 0; i < sz; i++) {
        int v = sec[i];
        auto it = fts.upper_bound({ft2[v], -1});
        if (it == fts.end()) {
            anc[v] = -1;
            tl[v] = 0;
            tr[v] = n;
        }
        else {
            anc[v] = it->S;
            tl[v] = st[anc[v]]+1;
            tr[v] = ft[anc[v]];
        }
        fts.insert({ft2[v], v});
    }

    ll res = 0;
    for (int i = 0; i < sz; i++) {
        int v = sec[i];
        int up = (anc[v]==-1? n: sub[anc[v]]) - (get_fen(tr[v]) - get_fen(tl[v]));
        res += 1ll * dn[v] * up;
    }

    for (int i = 0; i < sz; i++) {
        int v = sec[i];
        add_fen(st[v]+1, -dn[v]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c, a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(0);
    sort(edges, edges+ec);
    ll ans = 0;
    for (int l = 0; l < ec;) {
        int r = l + 1;
        while (r < n && edges[r].F == edges[l].F) r++;
        ans += count(l, r);
        l = r;
    }
    cout << ans << "\n";
    return 0;
}