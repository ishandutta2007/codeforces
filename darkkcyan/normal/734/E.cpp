#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
#define vi ve<int>
#define ii pair<int, int>

vi pp;
int findp(int u) { return pp[u] = pp[u] == u ? u : findp(pp[u]); }
void join(int u, int v) {
    pp[findp(u)] = findp(v);
}

int n;
ve<bool> col;
ve<ii> de;
ve<vi> gr;
void read() {
    cin >> n;
    col.resize(n);
    for (int i = 0; i < n; ++i) {
        int u; cin >> u; col[i] = u;
        pp.push_back(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        if (col[u] == col[v]) join(u, v);
        else de.push_back(ii(u, v));
    }

    gr.resize(n);
    for (; sz(de) > 0; de.pop_back()) {
        int u = de.back().xx, v = de.back().yy;
        u = findp(u), v = findp(v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}

vi dst;
queue<int> qu;
int bfs(int u) {
    dst.assign(n, -1);
    dst[u] = 0;
    for (qu.push(u); qu.size(); qu.pop()) {
        u = qu.front();
        for (int i = 0; i < sz(gr[u]); ++i) {
            int v = gr[u][i];
            if (dst[v] != -1) continue;
            dst[v] = dst[u] + 1;
            qu.push(v);
        }
    }
    return u;
}

int process() {
    int p0 = findp(0);
    int x = bfs(p0);
    int y = bfs(x);
    return (dst[y] + 1) / 2;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read();
    cout << process();

    return 0;
}