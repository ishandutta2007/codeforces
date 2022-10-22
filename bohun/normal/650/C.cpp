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

const int N = 1e6 + 100;

int n, m;
vector <int> v[N];
int a;

int par[N];

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void unia(int x, int y) {
	par[find(x)] = find(y);
}

vector <int> g[N];
vector <pair<int,int>> ord, ed;

int id(int r, int c) {
	return r * m + c;
}

vector <int> post, qw;
bool odw[N];
int dp[N];

void dfs(int u) {
	odw[u] = 1;
	for (auto it : g[u])
		if (!odw[it])
			dfs(it);
	post.pb(u);
}
			

int main() {	
	scanf ("%d%d", &n, &m);
	rep(i, 0, n - 1)
		rep(j, 0, m - 1) {
			scanf ("%d", &a);
			v[i].pb(a);
		}
		
	rep(i, 0, n * m - 1) par[i] = i;
	
	rep(r, 0, n - 1) {
		ord.clear();
		rep(j, 0, m - 1) ord.pb({v[r][j], j});
		sort(ord.begin(), ord.end());
		for (int i = 0; i < ss(ord);) {
			int j = i;
			while (j < ss(ord) && ord[i].fi == ord[j].fi) {
				unia(id(r, ord[i].se), id(r, ord[j].se));
				j++;
			}
			if (j < ss(ord))
				ed.pb(make_pair(id(r, ord[i].se), id(r, ord[j].se)));
			i = j;
		}
	}
	
	rep(c, 0, m - 1) {
		ord.clear();
		rep(i, 0, n - 1) ord.pb({v[i][c], i});
		sort(ord.begin(), ord.end());
		for (int i = 0; i < ss(ord);) {
			int j = i;
			while (j < ss(ord) && ord[i].fi == ord[j].fi) {
				unia(id(ord[i].se, c), id(ord[j].se, c));
				j++;
			}
			if (j < ss(ord))
				ed.pb(make_pair(id(ord[i].se, c), id(ord[j].se, c)));
			i = j;
		}
	}
	
	for (auto it : ed) {
		int a = find(it.fi);
		int b = find(it.se);
		g[a].pb(b);
	}
	
	rep(i, 0, n * m - 1) 
		if (find(i) == i) qw.pb(i);
	
	for (auto it : qw) 
		if (!odw[it])	
			dfs(it);
	for (auto it : qw)
		dp[it] = 1;
		
	per(i, 0, ss(post) - 1) {
		int u = post[i];
		for (auto it : g[u])
			dp[it] = max(dp[it], dp[u] + 1);
	}
	
	rep(i, 0, n - 1) {
		rep(j, 0, m - 1) {
			printf ("%d ", dp[find(id(i, j))]);
		}
		printf ("\n");
	}
	
	return 0;
}