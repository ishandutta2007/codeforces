#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 3005;
const int LOG = 11;

int n;
int a, b;
vector <int> v[nax];
int m, c;
int pre[nax];
int post[nax];
int h[nax];
int jump[nax][LOG + 1];
int cnt;
int siz[nax];
int par[nax];

void dfs(int u, int p) {
	par[u] = p;
	siz[u] = 1;
	h[u] = h[p] + 1;
	jump[u][0] = p;
	pre[u] = cnt++;
	for(auto it : v[u]) 
		if(it != p) {
			dfs(it, u);
			siz[u] += siz[it];
		}
	post[u] = cnt;
}

int lca(int x, int y) {
	if(h[x] < h[y])
		swap(x, y);
	for(int i = LOG; 0 <= i; --i)
		if(h[y] <= h[x] - (1 << i))
			x = jump[x][i];
	if(x == y)
		return x;
	for(int i = LOG; 0 <= i; --i) 
		if(jump[x][i] != jump[y][i]) {
			x = jump[x][i];
			y = jump[y][i];
		}
	return jump[x][0];
}

int odl(int x, int y) {
	return h[x] + h[y] - 2 * h[lca(x, y)];
}

vector <int> elo[3005];

int daj(int u, int k) {
	for (auto it : elo[k])
			u = jump[u][it];
	return u;
}

ll dp[nax][nax];

vector <pair<int, pair<int,int>>> vec;

int LCA[nax][nax];

int main() {
	
	for (int i = 1; i <= 3000; ++i)
		for (int j = 0; j <= LOG; ++j)
			if(((i >> j) & 1)) {
				elo[i].pb(j);
			}
	
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; ++i) {
		scanf ("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	
	for(int j = 1; j <= LOG; ++j)
		for(int i = 1; i <= n; ++i)
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i != j) 
				vec.pb(mp(odl(i, j), mp(i, j)));
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			LCA[i][j] = LCA[j][i] = lca(i, j);
		
	sort(vec.begin(), vec.end());
	ll debil = 0;
	for (auto it : vec) {
		a = it.se.fi;
		b = it.se.se;
		
		int c = LCA[a][b];
		if(a == c) {
		//	cat("1");
			int roz = h[b] - h[a];
			int mic = daj(b, roz - 1);
			//cat(roz);
			//cat(mic);
			//cat(siz[mic]);
			dp[a][b] = max(dp[a][b], dp[b][mic] + (n - siz[mic]) * siz[b]);
			dp[a][b] = max(dp[a][b], dp[par[b]][a] + (n - siz[mic]) * siz[b]);
		}
		if(b == c) {
			int roz = h[a] - h[b];
			int mic = daj(a, roz - 1);
			dp[a][b] = max(dp[a][b], dp[a][mic] + (n - siz[mic]) * siz[a]);
			dp[a][b] = max(dp[a][b], dp[par[a]][b] + (n - siz[mic]) * siz[a]);
		}
		else if(a != c && b != c){
			dp[a][b] = dp[par[a]][b] + siz[a] * siz[b];
			dp[a][b] = max(dp[a][b], dp[a][par[b]] + siz[a] * siz[b]);
		}
		debil = max(debil, dp[a][b]);
	}
	printf("%lld", debil);
	
	return 0;
}