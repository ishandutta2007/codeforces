#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n;
ve<ve<ii> > gr;
vi t, b, l, r;

void dfs1(int u, int p) {
    if (sz(gr[u]) > 4) {
        cout << "NO";
        exit(0);
    }

    int id = 0;
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i].xx;
        if (v == p) continue;
        dfs1(v, u);
        switch (id++) {
        case 0: // right
            gr[u][i].yy = b[v] + 1;
            r[u] = max(r[u], b[v] + 1 + t[v]);
            b[u] = max(b[u], r[v]);
            t[u] = max(t[u], l[v]);
            break;
        case 1: // left
            gr[u][i].yy = b[v] + 1;
            l[u] = max(l[u], b[v] + 1 + t[v]);
            b[u] = max(b[u], l[v]);
            t[u] = max(t[u], r[v]);
            break;
        case 2: // up
            gr[u][i].yy = t[u] + b[v] + 1;
            t[u] = max(t[u], t[u] + b[v] + 1 + t[v]);
            l[u] = max(l[u], l[v]);
            r[u] = max(r[u], r[v]);
            break;
        }
    }
}

ve<ii> ans;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void dfs2(int u, int p, int dir) {
    int id = 0;
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i].xx;
        if (v == p) continue;
        ans[v] = ans[u];
        int td = dir;
        switch(id++) {
        case 0:
            td = (td + 1) % 4;
            break;
        case 1:
            td = (td + 3) % 4;
            break;
        }
        ans[v].xx += gr[u][i].yy * dx[td];
        ans[v].yy += gr[u][i].yy * dy[td];
        dfs2(v, u, td);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    gr.resize(n);
    t.resize(n); b = l = r = t;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        gr[u].push_back(ii(v, 0));
        gr[v].push_back(ii(u, 0));
    }

    int r = 0;
    for (r = 0; r < n; ++r) {
        if (sz(gr[r]) <= 3) break;
    }

    if (r == n) {
        cout << "NO";
        exit(0);
    }

    dfs1(r, r);
    ans.resize(n);
    dfs2(r, r, 0);

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i].xx << ' ' << ans[i].yy << '\n';
    }

    return 0;
}