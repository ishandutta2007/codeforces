#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;	

const int N = 111111;

int n, out[N];
ll dp[N][2];
vector <int> G[N];
vector <int> opt[N][2]; // gdzie sa jedynki
bool vis[N];
	
void dfs(int v, int p) {
	// lisc
	if (ss(G[v]) == 1 && G[v][0] == p) {
		dp[v][1] = 0;
		dp[v][0] = 1e7;
		return;
	}
	
	ll S = 0;
	vector <pair<ll, int>> ord;
	
	for (auto u : G[v]) {
		if (u == p) continue;
		dfs(u, v);
		S += dp[u][0];
		ord.pb({-dp[u][0] + dp[u][1] + 2, u});
	}
	
	sort(all(ord));
	
	// dp[v][1] - v idzie do gory
	dp[v][1] = S;
	int j = 0;
	while (j + 1 < ss(ord) && ord[j].fi + ord[j + 1].fi < 0) {
		dp[v][1] += ord[j].fi + ord[j + 1].fi;
		opt[v][1].pb(ord[j].se);
		opt[v][1].pb(ord[j + 1].se);
		j += 2;
	}
	
	// dp[v][0] - v match z kims
	
	// 1. odd
	vector <int> now = {ord[0].se};
	ll s1 = S + ord[0].fi;
	j = 1;
	while (j + 1 < ss(ord) && ord[j].fi + ord[j + 1].fi < 0) {
		s1 += ord[j].fi + ord[j + 1].fi;
		now.pb(ord[j].se);
		now.pb(ord[j + 1].se);
		j += 2;
	}
	
	dp[v][0] = s1;
	opt[v][0] = now;
	
	// 2. even
	if (ss(ord) >= 2) {
		s1 = S + ord[0].fi + ord[1].fi;
		now = {ord[0].se, ord[1].se};
		j = 2;
		
		while (j + 1 < ss(ord) && ord[j].fi + ord[j + 1].fi < 0) {
			s1 += ord[j].fi + ord[j + 1].fi;
			now.pb(ord[j].se);
			now.pb(ord[j + 1].se);
			j += 2;
		}
		
		if (s1 < dp[v][0]) {
			dp[v][0] = s1;
			opt[v][0] = now;
		}
	}
	
	if (S + 2 < dp[v][0]) {
		dp[v][0] = S + 2;
		opt[v][0] = {};
	}
	
	//printf ("%d %lld %lld %d %lld\n", v, dp[v][0], dp[v][1], ss(opt[v][0]), S);
}
		
void odzyskaj(int v, int p, int k) {
	vis[v] = true;
	
	for (auto u : opt[v][k])
		odzyskaj(u, v, 1);
	for (auto u : G[v])
		if (!vis[u])
			odzyskaj(u, v, 0);
			
	if (k == 1) {
		assert(ss(opt[v][1]) % 2 == 0);
		for (int i = 0; i < ss(opt[v][1]); i += 2) {
			int a = opt[v][1][i], b = opt[v][1][i + 1];
			out[a] = b;
			out[b] = a;
		}
	}
	else {
		if (opt[v][0].empty()) {
			int son = -1;
			for (auto u : G[v])
				if (u != p) {
					son = u;
					break;
				}
			assert(son != -1);
			out[v] = out[son];
			out[son] = v;
		}
		else if (ss(opt[v][0]) % 2 == 1) {
			opt[v][0].pb(v);
			for (int i = 0; i < ss(opt[v][0]); i += 2) {
				int a = opt[v][0][i], b = opt[v][0][i + 1];
				out[a] = b;
				out[b] = a;
			}
		}
		else {
			for (int i = 0; i < ss(opt[v][0]); i += 2) {
				int a = opt[v][0][i], b = opt[v][0][i + 1];
				if (i != 0) {
					out[a] = b;
					out[b] = a;
				}
				else {
					out[a] = v;
					out[v] = b;
					out[b] = a;
				}
			}
		}
	}
}
			

int main() {	
	scanf ("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf ("%d%d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	printf ("%lld\n", dp[1][0]);
	odzyskaj(1, 0, 0);
	rep(i, 1, n)
		printf ("%d ", out[i]);
	return 0;
}