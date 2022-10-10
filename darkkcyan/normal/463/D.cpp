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

int n, k;
ve<vi> a;
void read() {
    scanf("%d%d", &n, &k);
    a.resize(k, vi(n));
    for (int i = 0; i < k; ++i) {
        for (int f = 0; f < n; ++f) {
            int u; scanf("%d", &u);
            a[i][--u] = f;
        }
    }
}

ve<vi> gr;
void buildgr() {
    gr.resize(n);
    for (int i = 0; i < n; ++i)
    for (int f = 0; f < n; ++f) {
        bool hasedge = 1;
        for (int g = 0; g < k; ++g) {
            if (a[g][i] < a[g][f]) continue;
            hasedge = 0;
            break;
        }
        if (hasedge) gr[i].push_back(f);
    }
}

vi tp;
ve<bool> vis;
void toposort(int u) {
    vis[u] = true;
    for (int i = 0; i < sz(gr[u]); ++i) {
        static int v; v = gr[u][i];
        if (vis[v]) continue;
        toposort(v);
    }
    tp.push_back(u);
}

vi dp;
int process() {
    vis.resize(n);
    for (int i = 0; i < n; ++i)
        if (!vis[i]) toposort(i);
    dp.resize(n, 1);
    int ans = 0;
    for (int i = sz(tp) - 1; i >= 0; --i) {
        int u = tp[i];
        ans = max(ans, dp[u]);
        for (int f = 0; f < sz(gr[u]); ++f) {
            int v = gr[u][f];
            dp[v] = max(dp[v], dp[u] + 1);
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
    buildgr();
    cout << process();

    return 0;
}