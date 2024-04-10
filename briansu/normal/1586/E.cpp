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

const int MAXn = 3e5 + 5;

int vis[MAXn], ew[MAXn];
vector<pii> v[MAXn];
vector<int> ans[MAXn];

bool dfs(int now, int targ, int kz) {
    vis[now] = 1;
    if (now == targ)
        return ans[kz].pb(now), true;
    bool ok = 0;
    for (auto [k, idx] : v[now])
        if (ew[idx] && !vis[k] && dfs(k, targ, kz)) {
            ok = 1;
            ans[kz].pb(now);
            ew[idx] = 0;
            break;
        }
    if (ok)
        return true;
    for (auto [k, idx] : v[now])
        if (!vis[k] && dfs(k, targ, kz)) {
            ok = 1;
            ans[kz].pb(now);
            ew[idx] = 1;
            break;
        }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb({b, i});
        v[b].pb({a, i});
    }
    ll q;
    cin >> q;
    for (int kz = 1; kz <= q; kz++) {
        int a, b;
        cin >> a >> b;
        fill_n(vis + 1, n, 0);
        assert(dfs(a, b, kz));
    }
    int tt = 0;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (auto [k, idx] : v[i])
            if (ew[idx])
                c++;
        tt += (c&1);
    }
    if (tt == 0) {
        cout << "YES\n";
        for (int i = 1; i <= q; i++) {
            cout << SZ(ans[i]) << "\n";
            reverse(ALL(ans[i]));
            for (int j = 0; j < SZ(ans[i]); j++)
                cout << ans[i][j] << " \n"[j + 1 == SZ(ans[i])];
        }
    }
    else {
        assert(tt % 2 == 0);
        cout << "NO\n";
        cout << tt / 2 << endl;
    }
    
}