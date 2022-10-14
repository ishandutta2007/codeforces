// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

struct data {
    int ev, od;
} ndat[200005];

void makeFa(int fa, int ch) {
    ndat[fa] = {ndat[fa].ev + ndat[ch].od, ndat[fa].od + ndat[ch].ev};
}

void disown(int fa, int ch) {
    ndat[fa] = {ndat[fa].ev - ndat[ch].od, ndat[fa].od - ndat[ch].ev};
}

ll ans = 0;
vector<int> elist[200005];
int val[200005], n;

void dfs1(int u, int f) {
    ndat[u] = {1, 0};
    for(int& v:elist[u]) {
        if(v == f) continue;
        dfs1(v, u);
        makeFa(u, v);
    }
}

void reroot(int u, int f) {
    ll oans = ans;
    ans = (ans + 1ll * val[u] * n) % MOD;
    for(int& v:elist[u])
        ans = (ans + 1ll * val[u] * (n - ndat[v].ev - ndat[v].od) % MOD *
        (MOD + ndat[v].od - ndat[v].ev)) % MOD;
    for(int& v:elist[u]) {
        if(v == f) continue;
        disown(u, v);
        makeFa(v, u);
        reroot(v, u);
        disown(v, u);
        makeFa(u, v);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    rep1(i, n) {
        cin >> val[i];
        val[i] = (MOD + val[i]) % MOD;
    }
    rep(i, n-1) {
        int u, v; cin >> u >> v;
        elist[u].pb(v);
        elist[v].pb(u);
    }
    dfs1(1, -1);
    reroot(1, -1);
    cout << ans << endl;
}