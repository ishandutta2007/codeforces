#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(a) ((int)a.size())
#define long long long 
#define inf(t) numeric_limits<t>::max()

vi p, cnt;
int setcnt;
int findp(int u) { return p[u] = u == p[u] ? u : findp(p[u]); }
void join(int u, int v) { 
    u = findp(u), v = findp(v);
    if (u == v) return;
    // clog << "join " << u << ' ' << v << endl;
    setcnt--;
    p[u] = v;
    cnt[v] += cnt[u];
}

int n;
ve<vi> gr;
vi c;

void dfs(int u, int p) {
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i];
        if (v == p) continue;
        if (c[u] == c[v]) join(u, v);
        else {
            cnt[findp(u)]++;
            cnt[findp(v)]++;
        }
        dfs(v, u);
    }
}

int findnode(int u, int p, int n) {
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i];
        if (p == v) continue;
        if (c[v] == n) return v;
        int t = findnode(v, u, n);
        if (t != -1) return t;
    }
    return -1;
}

bool check(int u, int p) {
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i];
        if (v == p) continue;
        if (c[v] != c[u]) return false;
        if (!check(v, u)) return false;
    }
    return true;
}

int main(void) {
#ifndef ONLINE_JUDGE
    FILE* ____;
    ____ = freopen("main.inp", "r", stdin);
    ____ = freopen("main.out", "w", stdout);
#endif // ONLINE_JUDGE
    
    scanf("%d", &n);
    gr.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v); --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    c.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    
    setcnt = n;
    p.resize(n); cnt.resize(n);
    for (int i = n; i--; ) p[i] = i;
    dfs(0, 0);

    int tcnt = 0;
    for (int i = 0; i < n; ++i) 
        if (findp(i) == i) tcnt += cnt[i] > 1;
    if (tcnt > 1) cout << "NO", exit(0);
    int color = c[0];
    for (int i = 0; i < n; ++i) {
        if (findp(i) == i and cnt[i] > 1) {
            color = c[i];
            break;
        }
    }

    int node = -1;
    for (int i = 0; i < n; ++i) {
        if (c[i] != color) {
            node = findnode(i, i, color);
            break;
        } 
    }

    if (node == -1) cout << "YES\n1", exit(0);

    for (int i = 0; i < sz(gr[node]); ++i) {
        if (!check(gr[node][i], node)) {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES\n" << node + 1;

    return 0;
}