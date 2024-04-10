#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;	

const int N = 2e5 + 101;

int n, cost[N], h[N], in[N], out[N];
vector <int> G[N];	
bool vis[N];
ll dp[N][2], ans;

void umax(ll &a, ll b) {
	a = max(a, b);
}

void dfs(int v, int p = 0, bool root = true) {
	vis[v] = true;
	vector <ll> vals;
	ll a = 0;
	for (auto u : G[v]) {
		if (vis[u]) continue;
		dfs(u, v, false);
		a += dp[u][0];
		vals.pb(dp[u][1] - dp[u][0]);
	}
	sort(all(vals));
	vals.pb(0);
	reverse(all(vals));
	
	int sz = ss(vals) - 1;
	rep(i, 0, ss(vals) - 1) {
		a += vals[i];
		
		int IN = in[v] + sz - i;
		int OUT = out[v] + i;
		int b = OUT - IN;
		ll val = 1LL * min(IN, OUT) * cost[v];
		
		a += val;
		
		if (b < 0) {
			umax(dp[v][0], a + (!root ? cost[v] : 0));
			umax(dp[v][1], a);
		}
		if (!b) {
			umax(dp[v][0], a);
			umax(dp[v][1], a);
		}
		if (b > 0) {
			umax(dp[v][1], a + (!root ? cost[v] : 0));
			umax(dp[v][0], a);
		}
		
		a -= val;
	}
}			
			

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", cost + i);
	rep(i, 1, n) scanf ("%d", h + i);
	rep(i, 2, n) {
		int u, v;
		scanf ("%d%d", &u, &v);
		ans += cost[u] + cost[v];
		if (h[u] != h[v]) {
			if (h[u] > h[v]) swap(u, v);
			out[u]++;
			in[v]++;
		}
		else {
			G[u].pb(v);
			G[v].pb(u);
		}
	}
	rep(i, 1, n) if (!vis[i]) {
		dfs(i);
		//cout << i << " " << dp[i][0] << endl;
		ans -= max(dp[i][0], dp[i][1]);
	}
	printf ("%lld\n", ans);
		
	return 0;
}