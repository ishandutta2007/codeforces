#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 200200;

int x[N], y[N], ord[N];
ll ans[N];
ll w[N], p[N]; // w[i], p[i] are weight, strength of edge leading up from i

// sub_lo, sub_hi are ranges for possible subtree weights for
// the edges below node i AND the edge leading up to it
ll sub_lo[N], sub_hi[N], wlo[N], whi[N];
ll w_final[N];
int n;

vector<int> ch[N];

bool dfs_build(int u) {
    ll ch_lo = 0, ch_hi = 0;
    for (auto& v : ch[u]) {
        bool res = dfs_build(v);
        if (!res) return false;

        ch_lo += sub_lo[v];
        ch_hi += sub_hi[v];
    }

    if (ch_lo > p[u]) return false;

    ll p_hi = p[u];
    ll p_lo = max(0LL, p[u]-(w[u])+1);
    ll w_hi = w[u];
    ll w_lo = w[u]+p_lo-p_hi;

    wlo[u] = w_lo;
    whi[u] = w_hi;

    sub_hi[u] = min(p_hi, ch_hi) + w_hi;
    sub_lo[u] = ch_lo + w_lo + (max(p_lo, ch_lo) - p_lo);
    assert(sub_lo[u] <= sub_hi[u]);

    //cerr << "  $ " << u << " : subr " << sub_lo[u] << " " << sub_hi[u] << " wr " << wlo[u] << " " << whi[u] << endl;

    return true;
}

void dfs_recon(int u, ll z) { // z = assigned subtree weight
    ll base = wlo[u];
    for (auto& v : ch[u]) {
        base += sub_lo[v];
    }

    ll extra = z - base;
    assert (extra >= 0);

    ll take = min(extra, whi[u]-wlo[u]);
    extra -= take;

    w_final[u] = take + wlo[u];
    //cerr << " wfinal " << u << " : " << w_final[u] << " had extra " << extra << " took " << take << " :: " << sub_lo[u] << " vs " << z << endl;

    for (auto& v : ch[u]) {
        take = min(extra, sub_hi[v] - sub_lo[v]);
        extra -= take;

        dfs_recon(v, take + sub_lo[v]);
    }

    //cerr << "  ! u " << u << " extra " << extra << endl;

    assert(extra == 0);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        cin >> x[i] >> y[i];
        cin >> w[y[i]] >> p[y[i]];
        ord[y[i]] = i;
        ch[x[i]].push_back(y[i]);
    }
    p[1] = 1e18;
    w[1] = 1;

    bool res = dfs_build(1);
    if (!res) {
        cout << -1 << '\n';
        return 0;
    }

    dfs_recon(1, sub_hi[1]);

    cout << n << "\n";
    for (int i=1; i<n; ++i) {
        cout << x[i] << " " << y[i] << " " << w_final[y[i]] << " " << w_final[y[i]]-w[y[i]]+p[y[i]] << "\n";
    }
    return 0;
}