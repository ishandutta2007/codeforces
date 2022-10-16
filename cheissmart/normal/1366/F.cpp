#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2002, M = 1e9 + 7;

V<pi> G[N];
int dp[N][N], w[N];

void add(int &a, int b) {
	a += b;
	if(a >= M) a -= M;
}

V<pair<ll, ll>> stk;

void add_seg(pair<ll, ll> p) {
	while(stk.size()) {
		if(stk.back().F == p.F) {
			stk.pop_back();
			continue;
		}
		if(stk.size() < 2) break;
		if(stk.back().F == p.F) {
			stk.pop_back();
			continue;
		}
		ll a = p.F, b = p.S;
		ll a1 = stk[stk.size()-1].F, b1 = stk[stk.size()-1].S;
		ll a2 = stk[stk.size()-2].F, b2 = stk[stk.size()-2].S;
		if((b2 - b1) * (a - a2) >= (b2 - b) * (a1 - a2)) {
			stk.pop_back();
		} else {
			break;
		}
	}
	stk.PB(p);
}

signed main()
{
	IO_OP;
	// freopen("in.txt", "r", stdin);	
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].EB(v, w);
		G[v].EB(u, w);
	}
	memset(dp, -1, sizeof dp);
	dp[1][0] = 0;
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			for(pi e:G[i]) {
				int k = e.F, w = e.S;
				if(dp[k][j-1] != -1) dp[i][j] = max(dp[i][j], dp[k][j-1] + w);
			}
		}
	}
	int ans = 0;
	// for i <= m
	for(int i = 1; i <= m; i++) {
		int mx = 0;
		for(int j = 1; j <= n; j++) mx = max(mx, dp[j][i]);
		add(ans, mx % M);
	}
	for(int i = 1; i <= n; i++) {
		// w[u] = max weight adj edge
		for(pi e:G[i]) w[i] = max(w[i], e.S);
	}
	// for m < i <= q
	V<pair<ll, ll>> v;
	for(int u = 1; u <= n; u++) {
		// weight_u(i) = i * w[u] - m * w[u] + dp[u][m]
		ll a = w[u], b = (ll) -m * w[u] + dp[u][m];
		v.EB(a, b);
	}
	sort(ALL(v));
	for(pair<ll, ll> p:v) {
		add_seg(p);
	}
	V<pair<ll, pair<ll, ll>>> tt;
	for(int i = 0; i < (int)stk.size() - 1; i++) {
		ll x = (stk[i].S - stk[i+1].S) / (stk[i+1].F - stk[i].F);
		tt.EB(x, stk[i]);
	}
	tt.EB(1e18, stk.back());
	int l = m + 1;
	for(auto p:tt) {
		ll r = p.F;
		r = min(r, (ll)q);
		if(r < l) continue;
		ll a = p.S.F, b = p.S.S;
		ll cans = (r - l + 1) * (b % M) % M + a % M * ((l+r)*(r-l+1)/2%M) % M;
		cans = (cans % M + M) % M;
		add(ans, cans);
		if(r == q) break;
		l = r + 1;
	}
	cout << ans << endl;

	
}