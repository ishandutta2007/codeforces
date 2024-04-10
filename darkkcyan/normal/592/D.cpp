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
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n, m;
ve<vi> gr;
ve<bool> x;
void read() {
    scanf("%d%d", &n, &m);
    gr.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v); --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    x.resize(n);
    int u;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &u);
        x[--u] = true;
    }
    if (m == 1) printf("%d\n%d", u + 1, 0), exit(0);
}

long ans = 0;
int r = -1;
ve<vi> tgr;
vi cnt;
void dfs(int u, int p) {
    cnt[u] = x[u];
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i];
        if (p == v) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    if (0 < cnt[u] and cnt[u] < m and u != p) {
        tgr[u].push_back(p);
        tgr[p].push_back(u);
        r = u;
        ans += 2;
    }
}

void preprocess() {
    tgr.resize(n);
    cnt.resize(n);
    dfs(0, 0);
}

queue<int> qu;
vi dst;
int bfs(int u) {
    dst.assign(n, -1);
    dst[u] = 0;
    int md = 0, ans = u;
    for (qu.push(u); qu.size(); qu.pop()) {
        u = qu.front();
        if (dst[u] > md) {
            md = dst[u];
            ans = u;
        } else if (dst[u] == md) ans = min(ans, u);
        for (int i = 0; i < sz(tgr[u]); ++i) {
            int v = tgr[u][i];
            if (dst[v] != -1) continue;
            dst[v] = dst[u] + 1;
            qu.push(v);
        }
    }
    return ans;
}

int process() {
    preprocess();
    int x = bfs(r);
    int y = bfs(x);
    int z = bfs(y);
    ans -= dst[z];
    return min(y, z);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE


    read();
    cout << process() + 1<< endl;
    cout << ans;
    return 0;
}