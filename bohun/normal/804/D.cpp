#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int nax = 1e5 + 111;

int n, m, q;
int a, b;

vector <int> v[nax];

int id[nax];
int f;

int sred[nax];
int naj[nax];

pair <int, int> best[nax][2];

vector <int> g[nax];
vector <LL> sum[nax];

void dfs(int u) {
	id[u] = f;
	for (auto it : v[u])
		if (!id[it]) {
			dfs(it);
			pair <int, int> x = {1 + best[it][1].fi, it};
			if (best[u][0] < x) swap(x, best[u][0]);
			if (best[u][1] < best[u][0]) swap(best[u][0], best[u][1]);
		}
}

void dfs2(int u, int p = 0, int gora = 0) {
	naj[u] = max(best[u][1].fi, gora);
	g[f].pb(naj[u]);
	sum[f].pb(naj[u]);
	sred[f] = max(sred[f], naj[u]);
	
	for (auto it : v[u])
		if (it != p) {
			int ngora = (best[u][1].se == it ? best[u][0].fi : best[u][1].fi);
			dfs2(it, u, 1 + max(gora, ngora));
		}
}
		
map <pair<int, int>, LD> mapa;	

int main() {	
	scanf ("%d%d%d", &n, &m, &q);
	rep(i, 1, m) {
		scanf ("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	rep(i, 1, n) {
		if (id[i]) continue;
		f++;
		
		dfs(i);
		dfs2(i);
		
		sort(g[f].begin(), g[f].end());
		
		per(j, 0, ss(sum[f]) - 1) {
			sum[f][j] = g[f][j];
			if (j + 1 != ss(sum[f]))
				sum[f][j] += sum[f][j + 1];
		}
	}
		
	while (q--) {
		scanf ("%d%d", &a, &b);
		a = id[a];
		b = id[b];
		if (a == b) {
			printf ("-1\n");
			continue;
		}
		if (ss(g[a]) > ss(g[b])) swap(a, b);
		
		if (mapa.find({a, b}) != mapa.end()) {
			printf ("%.10Lf\n", mapa[{a, b}]);
			continue;
		}
		
		LD ans = 0.0;
		int k = max(sred[a], sred[b]);
		
		for (auto it : g[a]) {
			int x = (int) (upper_bound(g[b].begin(), g[b].end(), k - it - 1) - g[b].begin());
			int sz = ss(g[b]) - x;
			ans += (LL) k * x;
			ans += sz + (LL) it * sz + sum[b][x];
		}
					
		ans /= (LL) ss(g[a]) * ss(g[b]);
		
		mapa[{a, b}] = ans;
		
		printf ("%.10Lf\n", ans);
	}
		
	
	
	return 0;
}