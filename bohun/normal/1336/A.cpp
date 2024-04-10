#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int nax = 2e5 + 100;

int n, k, a, b;
vector <int> g[nax];

int h[nax];
int siz[nax];
int f[nax];
int par[nax];

void dfs(int v, int p) {
	par[v] = p;
	siz[v] = 1;
	h[v] = h[p] + 1;
	for (auto it : g[v])
		if (it != p) {
			dfs(it, v);
			siz[v] += siz[it];
			f[v]++;
		}
}

multiset <pair<int, int>> s;

ll ans = 0;

int main() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	rep(i, 1, n) {
		if (f[i] == 0) {
			s.insert({h[i] - siz[i], i});
		}
	}
	while (k--) {
		auto it = *(--s.end());
		s.erase(--s.end());
		ans += it.fi;
		f[par[it.se]]--;
		if (!f[par[it.se]]) {
			s.insert({h[par[it.se]] - siz[par[it.se]], par[it.se]});
		}
	}
	printf ("%lld\n", ans);
	
	
	return 0;
}