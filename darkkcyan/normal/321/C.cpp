#include <bits/stdc++.h>

using namespace std;

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
typedef ve<int> vi;
typedef pair<int, int> ii;

int n;
ve<vi> gr;
void read() {
    cin >> n;
    gr.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}

ve<char> ans;
ve<bool> vis, iscentroid;
vi cnt;
bool ON = false;
void dfs0(int u) {
    vis[u] = ON;
    cnt[u] = 1;
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i];
        if (vis[v] == ON or iscentroid[v]) continue;
        dfs0(v);
        cnt[u] += cnt[v];
    }
}

void dfs1(int u, char tans = 'A') {
    ON ^= 1;
    dfs0(u);
    int cen = u;
    bool found = true;
    int scnt = cnt[u];
    do {
        found = true;
        for (int i = 0; i < sz(gr[cen]); ++i) {
            int v = gr[cen][i];
            if (iscentroid[v]) continue;
            if (cnt[v] <= scnt / 2) continue;
            cnt[cen] = scnt - cnt[v];
            cnt[v] = scnt;
            cen = v;
            found = false;
            break;
        }
    } while (!found);
    ans[cen] = tans;
    iscentroid[cen] = true;
    for (int i = 0; i < sz(gr[cen]); ++i) {
        int v = gr[cen][i];
        if (iscentroid[v]) continue;
        dfs1(v, tans + 1);
    }
    ON ^= 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    #define fn "file"
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #undef fn
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read();
    iscentroid.assign(n, 0); vis = iscentroid;
    cnt.assign(n, 0);
    ans.assign(n, 0);
    dfs1(0);
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';

    return 0;
}