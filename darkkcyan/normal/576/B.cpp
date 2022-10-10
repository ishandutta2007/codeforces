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
vi a;
void read() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
}

vi pp, cnt;
int findp (int u) {
    if (u == pp[u]) return u;
    return pp[u] = findp(pp[u]);
}

void join(int u, int v) {
    u = findp(u), v = findp(v);
    if (u == v) return;
    pp[u] = v;
    cnt[v] += cnt[u];
}

ve<bool> vis;
void solve() {
    pp.resize(n); cnt.resize(n, 1);
    for (int i = 0; i < n; ++i) pp[i] = i;
    vis.resize(n);
    for (int i = 0; i < n; ++i) {
        int t = i;
        while (!vis[t]) {
            vis[t] = true;
            join(t, a[t]);
            t = a[t];
        }
    }

    ii x(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        x = min(x, ii(cnt[findp(i)], findp(i)));
    }
    int minid = x.yy;
    if (x.xx != 1 and x.xx != 2) cout << "NO", exit(0);
    for (int i = 0; i < n; ++i) {
        if (cnt[findp(i)] % x.xx) cout << "NO", exit(0);
    }
    cout << "YES\n";
    vis.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (findp(i) == findp(minid)) continue;
        int u = i, v = minid;
        while (!vis[u]) {
            cout << u + 1 << ' ' << v + 1 << '\n';
            vis[u] = true;
            u = a[u], v = a[v];
        }
    }
//    cout << endl;
    for (int u = minid, v = a[u]; v != minid; swap(u, v), v = a[u]) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
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
    solve();


    return 0;
}