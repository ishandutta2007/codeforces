#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;
const ll MOD = 1e9+7;

ll modpow(ll b, ll p=MOD-2, ll m=MOD) {
    ll ans = 1;
    for (; p; p/=2, b=b*b%m) {
        if (p&1) ans = ans*b%m;
    }
    return ans;
}

ll r[N];
void setup() {
    r[1] = 1;
    for (int i=2; i<N; ++i)
        r[i] = (MOD - (MOD/i) * r[MOD%i] % MOD) % MOD;
}

ll pre[N], b[N], init_sz[N], sz[N], ans[N];
int8_t bad[N];
vector<pii> adj[N];
queue<int> q;
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n;
    for (int i=1; i<n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i=0; i<n; ++i) {
        init_sz[i] = sz[i] = adj[i].size();
        pre[i] = 1;
        ll d = modpow(sz[i]);
        for (auto& pr : adj[i]) {
            int v = pr.first;
            ll w = pr.second;
            b[i] = (b[i]+w*d)%MOD;
        }
        if (init_sz[i] == 1) {
            //cerr << " : " << i << endl;
            --init_sz[i];
            q.push(i);
            b[i] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        //cerr << "  u=" << u << " sz " << sz[u] << " init_sz " << init_sz[u] << " pre " << pre[u] << " b " << b[u] << endl;
        if (u == 0) continue;
        if (init_sz[u] == 0) {
            bad[u] = 1;
            int v = adj[u][0].first;
            if (--sz[v] <= 1) {
                q.push(v);
            }
        } else {
            int v = -1;
            for (auto& pr : adj[u]) {
                if (bad[pr.first]) continue;
                assert(v == -1);
                v = pr.first;
            }
            assert(v != -1);

            bad[u] = 1;
            if (--sz[v] <= 1) {
                q.push(v);
            }
            
            ll den = r[init_sz[v]]*modpow(pre[u])%MOD;
            pre[v] = (pre[v] + MOD*MOD - r[init_sz[u]]*den)%MOD;
            b[v] = (b[v] + b[u]*den)%MOD;
        }
    }

    cout << b[0]*modpow(pre[0])%MOD << "\n";
    return 0;
}