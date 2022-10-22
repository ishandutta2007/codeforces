#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cout << #x << " = " << x << endl
 
using namespace std;

const int nax = 1111;

int n, a, b, c;
vector <pair<int,int>> v[nax];
int deg[nax];
int leaf[nax];

void dfs1(int u, int p) {
	bool ok = 1;
	for(auto it : v[u]) {
		if(it.fi == p)
			continue;
		ok = 0;
		dfs1(it.fi, u);
		leaf[u] = leaf[it.fi];
	}
	if(ok)
		leaf[u] = u;
}

vector <pair<pair<int,int>, int>> res;
ll sum[nax];
ll suma = 0;

void dfs2(int u, int p) {
	suma += sum[u];
	for(auto it : v[u]) 
		if(it.fi != p)
			dfs2(it.fi, u);
}

void add(int x, int y, int z) {
	sum[x] += z;
	sum[y] += z;
	res.pb({{x, y}, z});
}

void solve(int u, int p, int dod = -1) {
	if(leaf[u] == u)
		return;
	vector <int> gao;
	for(auto &it : v[u]) {
		if(it.fi == p)
			continue;
		gao.pb(leaf[it.fi]);
		suma = 0;
		dfs2(it.fi, u);
		it.se -= suma;
	}
	if(dod != -1)
		gao.pb(dod);
	for(auto it : v[u]) {
		if(it.fi == p)
			continue;
		vector <int> help;
		int c = it.se / 2;
		for(auto g : gao) {
			if(g != leaf[it.fi])	
				help.pb(g);
			if(ss(help) == 2)
				break;
		}
		add(leaf[it.fi], help[0], c);
		add(leaf[it.fi], help[1], c);
		add(help[0], help[1], -c);
	}
	for(auto it : v[u]) {
		if(it.fi != p) {
			int wsk = 0;
			while(v[u][wsk].fi == p || v[u][wsk].fi == it.fi)
				wsk += 1;
			solve(it.fi, u, leaf[v[u][wsk].fi]); 
		}
	}
}
		
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].pb({b, c});
		v[b].pb({a, c});
		deg[a] += 1;
		deg[b] += 1;
	}
	for(int i = 1; i <= n; ++i) {
		if(deg[i] == 2) {
			printf("NO\n");
			return 0;
		}
	}
	if(n == 2) {
		printf("YES\n");
		printf("1\n");
		printf("1 2 %d", v[1][0].se);
		return 0;
	}
	int root = 1;
	while(deg[root] == 1)
		root += 1;
	dfs1(root, 0);
	solve(root, 0);
	printf("YES\n");
	printf("%d\n", ss(res));
	for(auto it : res) {
		printf("%d %d %d\n", it.fi.fi, it.fi.se, it.se);
	}
	
	
	
 
	return 0;
}