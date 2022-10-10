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

int n, m, k;
ve<vi> gr;
vi c;
void read() {
    scanf("%d%d%d", &n, &m, &k);
    gr.resize(n);
    c.resize(k);
    for (int i = 0; i < k; ++i) scanf("%d", &c[i]), --c[i];
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}

vi dad;
long edgecnt, vcnt, cecnt;
void dfs(int u) {
    vcnt++;
    edgecnt += sz(gr[u]);
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i];
        if (dad[v] == -1) {
            dad[v] = u;
            dfs(v);
        }
    }
}

long process() {
    dad.resize(n, -1);
    long ans = 0;
    long t = 0;
    for (int i = 0; i < k; ++i) {
        vcnt = 0;
        dad[c[i]] = c[i];
        dfs(c[i]);
        t = max(t, (long)vcnt);
        ans += vcnt * (vcnt - 1) / 2;
    }
    ans -= m;
    for (int i = 0; i < n; ++i) {
        if (dad[i] == -1) {
            ans += t;
            ++t;
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    cout << process();

    return 0;
}