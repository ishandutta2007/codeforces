#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " " << x << endl;


using namespace std;

const int nax = 300005, mod = 1e9 + 7;

int n, m, a, b;
vector <pair<int, int>> v[nax];
int dp[nax];
int h[nax];
int nr[nax];

vector <int> E[nax];

void dfs(int u, int p) {
	for(auto it: v[u]) {
		if(h[it.fi] == 0) {
			h[it.fi] = h[u] + 1;
			dfs(it.fi, u);
			if(dp[it.fi])
				nr[u] = nr[it.fi];
			dp[u] += dp[it.fi];
		}
		else if(it.fi != p && h[it.fi] > h[u]) {
			dp[u]--;
		}
		else if(it.fi != p){
			nr[u] = it.se;
			dp[u]++;
		}
	}
	if(!nr[u]) {
		nr[u] = u;
	}
}

int res[nax];
int lca[nax][17];
int H[nax];
int dwa[nax];


void go(int u, int p) {
	res[u] += (u > n);
	for(auto it: E[u]) {
		if(it == p)
			continue;
		H[it] = H[u] + 1;
		lca[it][0] = u;
		res[it] = res[u];
		go(it, u);
	}
}

int Lca(int x, int y) {
	if(H[x] < H[y])
		swap(x, y);
	for(int i = 16; 0 <= i; --i)
		if(H[x] - (1 << i) >= H[y]) {
			x = lca[x][i];
	}
	if(x == y)
		return x;
	for(int i = 16; 0 <= i; --i) {
		if(lca[x][i] != lca[y][i]) {
			x = lca[x][i];
			y = lca[y][i];
		}
	}
	return lca[x][0];
}

int pt(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1)
			r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}
	
			
				
int main() {
	dwa[0] = 1;
	for(int i = 1; i < nax; ++i)
		dwa[i] = (ll) dwa[i - 1] * 2 % mod;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		v[a].pb(mp(b, i + n));
		v[b].pb(mp(a, i + n));
	}
	h[1] = 1;
	dfs(1, 0);
	vector <int> node;
	
	for(int i = 1; i <= n; ++i) {
		for(auto it: v[i]) {
			if(nr[it.fi] > nr[i]) {
				E[nr[it.fi]].pb(nr[i]);
				E[nr[i]].pb(nr[it.fi]);
			}
		}
		node.pb(nr[i]);
	}
	go(nr[1], 0);
	sort(node.begin(), node.end());
	node.erase(unique(node.begin(), node.end()), node.end());
	
	
	for(int i = 1; i <= 16; ++i)
		for(auto j: node)
			lca[j][i] = lca[lca[j][i - 1]][i - 1];
	
	
	int q;
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d", &a, &b);
		a = nr[a];
		b = nr[b];
		int ans = res[a] + res[b] - 2 * res[Lca(a, b)] + (Lca(a, b) > n);
		printf("%d\n", dwa[ans]);
	}
	
	
	
	
	
	
		
	return 0;
}