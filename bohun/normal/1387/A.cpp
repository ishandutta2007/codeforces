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
#define ld long double

using namespace std;	

const int N = 211111;
const ld eps = 0.0000000001;

int n, m, dep[N], cost[N];
vector <pair<int, int>> G[N], d[N];
int a[N], b[N], c[N];		
bool vis[N], oddcycle;

ld out[N], costcycle;
vector <int> now;
vector <int> jacie;

void dfs(int v, int p) {
	now.pb(v);
	vis[v] = true;
	dep[v] = dep[p] + 1;
	for (auto it : G[v]) {
		int u = it.fi, w = it.se;
		if (u == v) {
			jacie.pb(v);
			out[v] = (ld) w / 2;
			continue;
		}
		if (u == p) continue;
		if (vis[u] && dep[v] % 2 == dep[u] % 2 && dep[v] > dep[u]) {
			oddcycle = true;
			costcycle = ((ld) w - cost[u] - cost[v]) / 2;
			if (dep[v] % 2 == 0)
				costcycle *= -1.0;
		}
		if (!vis[u]) {
			d[u].pb({v, w});
			d[v].pb({u, w});
			cost[u] = w - cost[v];
			dfs(u, v);
		}
	}
}

void ustaw(int v, int p, ld ja) {
	out[v] = ja;
	for (auto it : d[v]) {
		int u = it.fi, w = it.se;
		if (u == p) continue;
		ustaw(u, v, w - ja);
	}
}

ld f(ld k) {
	ld res = 0.0;
	for (auto u : now) {
		if (dep[u] & 1) res += abs(out[u] + k);
		else res += abs(out[u] - k);
	}
	return res;
}	

int main() {	
	scanf ("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v, w;
		scanf ("%d%d%d", &u, &v, &w);
		a[i] = u;
		b[i] = v;
		c[i] = w;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	
	rep(i, 1, n) {
		if (vis[i]) continue;
		oddcycle = false;
		now.clear();
		jacie.clear();
		dfs(i, 0);
		
		if (!jacie.empty()) {
			ustaw(jacie[0], 0, out[jacie[0]]);
			continue;
		}
			
		ustaw(i, 0, oddcycle ? costcycle : 0.0);
		if (oddcycle) continue;
		
		ld l = -1e8, r = 1e8;
		
		rep(i, 1, 120) {
			ld d = (r - l) / 3;
			ld m1 = l + d;
			ld m2 = r - d;
			
			if (f(m1) - f(m2) > eps)
				l = m1;
			else
				r = m2;
		}
		
		for (auto u : now) {
			if (dep[u] & 1) out[u] += l;
			else out[u] -= l;
		}
	} 
	
	rep(i, 1, m) {
		if (abs(c[i] - (out[a[i]] + out[b[i]])) > eps)
			return printf ("NO\n"), 0;
	}
		
	printf ("YES\n");
	rep(i, 1, n)
		printf ("%.14Lf ", out[i]);
		
	
	return 0;
}