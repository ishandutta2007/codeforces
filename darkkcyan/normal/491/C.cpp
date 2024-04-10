#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;

int n, k;
string a, b;
void read() { cin >> n >> k >> a >> b; }

int pos(char a) {
    if (islower(a)) return a - 'a';
    else return a - 'A' + 26;
}

char ch(int p) {
    if (p < 26) return p + 'a';
    else return p + 'A' - 26;
}

const int inf = numeric_limits<int>::max();
ve<vi> gr;
void buildgr() {
    gr.resize(k, vi(k, 0));
    for (int i = 0; i < n; ++i) {
        int u = pos(a[i]), v = pos(b[i]);
        gr[u][v]++;
    }
}

vi fu, fv, pu, pv;
int edge(int u, int v) { return fu[u] + fv[v] - gr[u][v]; }

queue<int> qu;
ve<bool> vu, vv;
vi tr;
int bfs(int u) {
    while (qu.size()) qu.pop();
    vu.assign(k, 0);
    vv = vu;
    tr.resize(k, -1);
    vu[u] = 1;
    for (qu.push(u); qu.size(); qu.pop()) {
        int u = qu.front();
        for (int v = 0; v < k; ++v) {
            if (edge(u, v) != 0 or vv[v]) continue;
            vv[v] = true;
            tr[v] = u;
            if (pv[v] == -1) return v;
            vu[pv[v]] = true;
            qu.push(pv[v]);
        }
    }
    return -1;
}

void trans() {
    int cmin = inf;
    for (int u = 0; u < k; ++u) {
        if (!vu[u]) continue;
        for (int v = 0; v < k; ++v) {
            if (vv[v]) continue;
            cmin = min(cmin, edge(u, v));
        }
    }
    for (int i = 0; i < k; ++i) {
        if (vu[i]) fu[i] -= cmin;
        if (vv[i]) fv[i] += cmin;
    }
}

void incmatch(int v) {
    while (v != -1) {
        int u = tr[v];
        int t = pu[u];
        pv[v] = u;
        pu[u] = v;
        v = t;
    }
}

string ans;
int process() {
    buildgr();
    fu.resize(k, 0); fv = fu;
    pu.resize(k, -1); pv = pu;
    for (int i = 0; i < k; ++i) {
        int mm = 0;
        for (int f = 0; f < k; ++f) mm = max(mm, gr[i][f]);
        fu[i] = mm;
    }
    for (int i = 0; i < k; ++i) {
        int v;
        while (true) {
            v = bfs(i);
            if (v != -1) break;
            trans();
        }
        incmatch(v);
    }
    int sans = 0;
    for (int i = 0; i < k; ++i) sans += gr[i][pu[i]], ans += ch(pu[i]);
    return sans;
}

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    cout << process() << '\n' << ans;

    return 0;
}