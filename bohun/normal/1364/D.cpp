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

const int N = 1e5 + 101;

int a, b;
int n, m, k;

vector <int> g[N];

bool odw[N];
int par[N];
int h[N];

int best = N;
int up, down;

vector <int> wow[2];

void dfs(int v, int p) {
	par[v] = p;
	h[v] = h[p] + 1;
	odw[v] = true;
	
	wow[h[v] % 2].pb(v);
	
	for (auto it : g[v]) {
		if (odw[it] && it != p && h[v] > h[it]) {
			int dlugosc = 1 + h[v] - h[it];
			if (dlugosc < best) {
				best = dlugosc;
				up = it;
				down = v;
			}
		}
		if (!odw[it])
			dfs(it, v);
	}
}
		
		

int main() {
	scanf ("%d%d%d", &n, &m, &k);
	rep(i, 1, m) {
		scanf ("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	
	int IND = (k + 1) / 2;
	
	if (m == n - 1) {
		if (ss(wow[0]) < ss(wow[1]))
			swap(wow[0], wow[1]);
		printf ("1\n");
		rep(i, 0, IND - 1)
			printf ("%d ", wow[0][i]);
		return 0;
	}
	
	vector <int> cycle;
	int v = down;
	while (v != up) {
		cycle.pb(v);
		v = par[v];
	}
	cycle.pb(up);
	if (ss(cycle) <= k) {
		printf ("2\n");
		printf ("%d\n", ss(cycle));
		for (auto it : cycle)
			printf ("%d ", it);
		return 0;
	}
	vector <int> ans;
	for (int i = 0; i < ss(cycle); i += 2)
		if (ss(ans) < IND)
			ans.pb(cycle[i]);
	
	printf ("1\n");
	for (auto it : ans)
		printf ("%d ", it);
		
	return 0;
}