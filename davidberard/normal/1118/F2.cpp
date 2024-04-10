#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll mod = 998244353;
const int NMAX = 300300;
const int LMAX = 20;

ll n, k;

int a[NMAX];

vector<int> adj[NMAX];
int par[NMAX][LMAX], dep[NMAX], lc[NMAX];
ll ans = 1;
ll dp[NMAX][2];
bool bad;

void dfs(int u, int p, int d) {
    if(dep[u]) return;
    par[u][0] = p;
    dep[u] = d;
    for(auto& v : adj[u]) {
        dfs(v, u, d+1);
    }
}

ll modpow(ll b, ll p) {
    ll a = 1;
    while(p) {
        if(p&1) a = (a*b)%mod;
        b = (b*b)%mod;
        p >>= 1;
    }
    return a;
}

void build() {
    for(int l=1;l<LMAX;++l) {
        for(int i=1;i<=n;++i) {
            par[i][l] = par[par[i][l-1]][l-1];
        }
    }
}

inline void swim(int& u, int d) {
    int l = 0;
    while(d) {
        if(d&1) u = par[u][l];
		//cerr << "-- " << u << endl;
        d >>= 1; ++l;
    }
}

inline int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
	//cerr << " lca " << u << " (to " << v << ") " << endl;
	int d = dep[u]-dep[v];
    swim(u, dep[u]-dep[v]);
	//cerr << " after swim is " << u <<" , diff was "<< d << endl;
    for(int l=LMAX-1;l>=0;l--) {
        if(par[u][l] != par[v][l]) {
            u = par[u][l];
            v = par[v][l];
        }
    }
    if(u != v) u = par[u][0];
    return u;
}

int dfs2(int u) {
    int tc = 0;
    for(auto& v : adj[u]) {
        if(dep[v] != dep[u]+1) continue;
        int nc = dfs2(v);
        if(tc == 0) tc = nc;
        else if(tc != nc && nc) {
			//cerr << " 78 " << u << endl;
			tc = -1;
		}
    }
    if(tc == 0) {
        tc = a[u];
    }
    if(tc != a[u] && a[u]) {
		//cerr << " 86 " << u << endl;
		tc = -1;
	}
    if(tc == -1) {
		return -1;
	}
    if(lc[u]) {
        if(lc[u] != tc) {
			//cerr << " 94 " << u << endl;
			return -1;
		}
        return 0;
    }
	//cerr << " from " << u << " return " << tc << endl;
    return tc;
}

int dfs3(int u) {
    int cc = 0;
	int tc = 0;
    for(auto& v : adj[u]) {
        if(dep[v] != dep[u]+1) continue;
        ++cc;
        tc = max(tc, dfs3(v));
    }
    if(cc = 0) {
        dp[u][0] = 0;
        dp[u][1] = 1;
        return 0;
    }
	if(!tc && a[u]) {
		dp[u][0] = 1;
		dp[u][1] = 0;
		for(auto& v : adj[u]) {
			if(dep[v] != dep[u]+1) continue;
			dp[u][0] = (dp[v][1]+dp[v][0])*dp[u][0]%mod;
		}
		tc = a[u];
	} else if(tc) {
		dp[u][0] = 1;
		dp[u][1] = 0;
		for(auto& v : adj[u]) {
			if(dep[v] != dep[u]+1) continue;
			dp[u][0] = (dp[v][0]+dp[v][1])*dp[u][0]%mod;
			//cerr << "-- " << dp[v][0] << " " << dp[v][1] << endl;
		}
	} else {
		dp[u][1] = 1;
		for(auto& v : adj[u]) {
			if(dep[v] != dep[u]+1) continue;
			dp[u][1] = (dp[v][1]+dp[v][0])*dp[u][1]%mod;
		}
		dp[u][0] = 0;
		for(auto& v : adj[u]) {
			dp[u][0] = (dp[u][0] + (dp[u][1]*dp[v][0]%mod)*modpow(dp[v][0]+dp[v][1], mod-2))%mod;
		}
	}
	//cerr << " dp[" << u << "] = " << dp[u][0] << " " << dp[u][1] << ", now tc is " << tc << endl;
	if(lc[u]) {
		assert(tc);
		return 0;
	}
	return tc;
}

vector<int> of[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        of[a[i]].push_back(i);
    }
    for(int i=0;i<n-1;++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);
    build();
    for(int i=1;i<=k;++i) {
        int l = of[i][0];
        for(int j=1;j<of[i].size();++j) {
			//cerr << " LCA of " << l << " and " << j << " = ";
            l = lca(l, of[i][j]);
			//cerr << l << endl;
        }
		//cerr << " LCA of " << i << " is " << l << endl;
		if(lc[l]) {
			cout << 0 << endl;
			return 0;
		}
        lc[l] = i;
    }
    if(dfs2(1)) {
        cout << 0 << endl;
		return 0;
    }
	dfs3(1);
	cout << dp[1][0] << endl;

    return 0;
}