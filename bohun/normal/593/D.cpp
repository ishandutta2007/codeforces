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

const int nax = 2e5 + 111;
const long long INF = 1e18 + 111;

ll mul(ll a, ll b) {
	if(a > INF / b) return INF;
	return a * b;
}

struct uf {
	int p[nax];
	int k[nax];
	
	void init() {
		for(int i = 1; i < nax; ++i)
			p[i] = k[i] = i;
	}
	
	int find(int x) {
		if(x == p[x]) return x;
		return p[x] = find(p[x]);
	}
	
	void unia(int x, int y) {
		x = find(x);
		y = find(y);
		// x do y
		if(x != y) {
			k[x] = -1;
			p[x] = y;
		}
	}
} ja;

int n, m;
vector <pair<int, ll>> v[nax];
int a[nax], b[nax];
ll c;			
ll w[nax];
int h[nax];
int jump[nax][18];

void dfs(int u, int p, int last = 0) {
	h[u] = h[p] + 1;
	jump[u][0] = p;
	
	for(auto it : v[u]) 
		if(it.fi == p) w[u] = it.se;
	
	if(w[u] > 1) 
		ja.k[u] = last;
	else {
		ja.k[u] = -1;
		ja.unia(u, p);
	}
	
	if(w[u] > 1) last = u;
	for(auto it : v[u])
		if(it.fi != p)
			dfs(it.fi, u, last);
} 

int lca(int x, int y) {
	if(h[x] < h[y]) swap(x, y);
	for(int i = 17; 0 <= i; --i)
		if(h[y] <= h[x] - (1 << i))
			x = jump[x][i];
	if(x == y) return x;
	for(int i = 17; 0 <= i; --i)
		if(jump[x][i] != jump[y][i]) {
			x = jump[x][i];
			y = jump[y][i];
		}
	return jump[x][0];
}

void go1() {
	int x, y;
	ll z;
	scanf("%d %d %lld", &x, &y, &z);
	
	int LCA = lca(x, y);
	ll r = 1;
	
	while(h[LCA] < h[x] && r != INF) {
		//printf("%d a %d\n", x, ja.k[x]);
		if(ja.k[x] == -1)
			x = ja.find(x);
		else {
			r = mul(r, w[x]);
			x = ja.k[x];
		}
	}
	
	while(h[LCA] < h[y] && r != INF) {
		//printf("%d b %d\n", y, ja.k[y]);
		if(ja.k[y] == -1)
			y = ja.find(y);
		else {
			r = mul(r, w[y]);
			y = ja.k[y];
		}
	}
	
	printf("%lld\n", z / r);
}
			
void go2() {
	int nr;
	scanf("%d %lld", &nr, &c);
	int ver;
	if(h[a[nr]] > h[b[nr]])		
		ver = a[nr];
	else
		ver = b[nr];
	
	w[ver] = c;
	if(c == 1) {
		ja.unia(ver, ja.k[ver]);
	}
}
			
			
int main() {
	ja.init();
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; ++i) {
		scanf("%d %d %lld", a + i, b + i, &c);
		v[a[i]].pb(mp(b[i], c));
		v[b[i]].pb(mp(a[i], c));
	}
	
	dfs(1, 1);
	
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n; ++i)
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
	for(int i = 1; i <= m; ++i) {
		int type;
		scanf("%d", &type);
		if(type == 1)
			go1();
		else
			go2();
	}
	return 0;
}