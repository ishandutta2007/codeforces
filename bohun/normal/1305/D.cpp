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

const int nax = 1100;

int n;
int a, b;
vector <int> v[nax];

bool de[nax];
int h[nax];
int par[nax];

pair <int, int> best;

void dfs(int u, int p) {
	par[u] = p;
	h[u] = h[p] + 1;
	
	best = max(best, {h[u], u});
	
	for (auto it : v[u])
		if (it != p && !de[it])
			dfs(it, u);
}

int main() {	
	scanf ("%d", &n);
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	int g = 1;
		
	while (true) {
		best = {-1, -1};
		dfs(g, 0);
		int c = best.se;
		best = {-1, -1};
		dfs(c, 0);
		int d = best.se;
		
		if (c == d) {
			printf ("! %d", c);
			return 0;
		}
		printf ("? %d %d\n", c, d);
		fflush(stdout);
		int e;
		scanf ("%d", &e);
		if (e == c) {
			printf ("! %d", c);
			return 0;
		}
		if (e == d) {
			printf ("! %d", d);
			return 0;
		}
		
		if (h[c] < h[d]) swap(c, d);
		
		while (h[c] > h[d]) {
			de[c] = (c != e ? 1 : 0);
			c = par[c];
		}
		
		while (c != d) {
			de[c] = (c != e ? 1 : 0);
			de[d] = (d != e ? 1 : 0);
			c = par[c];
			d = par[d];
		}
		
		de[c] = (c != e ? 1 : 0);
		
		g = e;
	}
			
		
		
		
		
	
	return 0;
}