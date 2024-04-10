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

int n, m, w;
vi a, b;
ve<vi> gr;

vi p;
int findp(int u) { return p[u] = u == p[u] ? u : findp(p[u]); }
void join(int u, int v) {
    u = findp(u), v = findp(v);
    p[u] = v;
}

map<int, int> dp[2];

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &w);
    a.resize(n); b = p = a;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i) p[i] = i;

    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v); --u, --v;
        join(u, v);
    }

    gr.resize(n);
    for (int i = 0; i < n; ++i) gr[findp(i)].push_back(i);

    int cur = 1;
    dp[0][0] = 0;
    map<int, int>::iterator it;
    for (int i = 0; i < n; ++i) {
        if (!sz(gr[i])) continue;
        dp[cur] = dp[!cur];
        int aa = 0, ab = 0;
        for (int f = 0; f < sz(gr[i]); ++f) {
            int u = gr[i][f];
            aa += a[u], ab += b[u];
            if (a[u] > w) continue;
            dp[cur][a[u]] = max(dp[cur][a[u]], b[u]);
            for (it = dp[!cur].begin(); it != dp[!cur].end(); ++it) {
                if (it->xx + a[u] > w) break;
                int s = it->xx + a[u];
                dp[cur][s] = max(dp[cur][s], it->yy + b[u]);
            }
        }

        for (it = dp[!cur].begin(); it != dp[!cur].end(); ++it) {
            if (it->xx + aa > w) break;
            int s = it->xx + aa;
            dp[cur][s] = max(dp[cur][s], it->yy + ab);
        }
        cur ^= 1;
    }

    cur ^= 1;
    int ans = 0;
    for (it = dp[cur].begin(); it != dp[cur].end(); ++it)
        ans = max(ans, it->yy);
    cout << ans;

    return 0;
}