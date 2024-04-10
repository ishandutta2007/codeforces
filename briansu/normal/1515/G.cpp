#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXn = 2e5 + 5;

vector<pll> v[MAXn], vr[MAXn];
vector<int> top;

ll vis[MAXn], gc[MAXn], g[MAXn], git, dph[MAXn];

void dfs1(int now) {
    vis[now] = 1;
    for (auto &[k, w] : vr[now])
        if (!vis[k])
            dfs1(k);
    top.pb(now);
}

void dfs2(int now) {
    vis[now] = 1;
    g[now] = git;
    for (auto &[k, w] : v[now]) {
        if (vis[k]) {
            if (g[k] == git)
                gc[git] = gcd(gc[git], (dph[now] - dph[k] + w));
        }
        else {
            dph[k] = dph[now] + w;
            dfs2(k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
        vr[b].pb({a, c});
    }
    fill_n(vis + 1, n, 0);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);
    fill_n(vis + 1, n, 0);
    reverse(ALL(top));
    for (int i : top)
        if (!vis[i]) {
            ++git;
            dph[i] = 0;
            dfs2(i);
        }
    ll q;
    cin >> q;
    while (q--) {
        int x, s, t;
        cin >> x >> s >> t;
        if (ll _g = gc[g[x]]; s == 0 || (_g != 0 && s % gcd(t, _g) == 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}