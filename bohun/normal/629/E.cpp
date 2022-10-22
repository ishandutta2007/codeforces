#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int nax = 1e5 + 111;

int n, m;
int a, b;
vector <int> v[nax];
int siz[nax];
ll disdown[nax];
ll disup[nax];
int h[nax];
int jump[nax][17];

void dfs(int u, int p) {
	h[u] = h[p] + 1;
	jump[u][0] = p;
	siz[u] = 1;
	
	for(auto it : v[u]) {
		if(it == p) continue;
		dfs(it, u);
		siz[u] += siz[it];
		disdown[u] += 1ll * disdown[it] + 1ll * siz[it];
	}
}

void dfs2(int u, int p) {
	if(p != 0) {
		disup[u] = disup[p] + (n - siz[u]) + disdown[p] - disdown[u] - siz[u];
	}
	for(auto it : v[u]) {
		if(it == p) continue;
		dfs2(it, u);
	}
}
		

int lca(int x, int y) {
	if(h[x] < h[y]) swap(x, y);
	for(int i = 16; 0 <= i; --i)
		if(h[y] <= h[x] - (1 << i))
			x = jump[x][i];
	if(x == y) return x;
	for(int i = 16; 0 <= i; --i)
		if(jump[x][i] != jump[y][i]) {
			x = jump[x][i];
			y = jump[y][i];
		}
	return jump[x][0];
}

int dis(int a, int b) {
	return h[a] + h[b] - 2 * h[lca(a, b)];
}

int kth(int u, int k) {
	for(int i = 0; i <= 16; ++i)
		if(((k >> i) & 1))
			u = jump[u][i];
	return u;
}
			

int main() {	
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for(int j = 1; j <= 16; ++j)
		for(int i = 1; i <= n; ++i)
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
	for(int i = 1; i <= m; ++i) {
		ld res = 0;
		ll mia = 0;
		scanf("%d %d", &a, &b);
		if(h[b] < h[a]) swap(a, b);
		int c = lca(a, b);
		if(c != a) {
			ll dod = 0;
			mia = 1ll * siz[a] * siz[b];
			dod = 1ll * siz[a] * siz[b] * (dis(a, b) + 1);
			dod += 1ll * disdown[a] * siz[b];
			dod += 1ll * disdown[b] * siz[a];
			res += (ld) dod / mia;
		}
		else {
			ll dod = 0;
			int d = kth(b, h[b] - h[a] - 1);
			mia = 1ll * siz[b] * (n - siz[d]);
			dod = 1ll * (h[b] - h[a] + 1) * siz[b] * (n - siz[d]);
			dod += 1ll * (n - siz[d]) * disdown[b];
			dod += 1ll * siz[b] * (disup[a] + disdown[a] - disdown[d] - siz[d]);
			res += (ld) dod / mia;
		}
		printf("%Lf\n", res);
	}
	return 0;
}