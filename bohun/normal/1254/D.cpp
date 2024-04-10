#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
 
using namespace std;

const int nax = 151111;
const int mod = 998244353;

int pt(int a, int b) { int c = 1; while(b) {if(b & 1) c = (ll) c * a % mod; a = (ll) a * a % mod; b /= 2;} return c;};

int n, m;
int a, b;
vector <int> v[nax];

ll fen[nax];

void add(int x, int c) {
	for(int i = x; i < nax; i += i & -i)
		fen[i] += c;
}

ll query(int x) {
	ll res = 0;
	for(int i = x; 0 < i; i -= i & -i)
		res += fen[i];
	return res;
}

void range(int l, int r, int c) {
	if(l > r)
		return;
	add(l, c);
	add(r + 1, -c);
}

int siz[nax];
int heavy[nax];
int tim = 1;
int pre[nax];
int post[nax];
int parent[nax];
int block[nax];

void dfs(int u, int p) {
	parent[u] = p;
	siz[u] = 1;
	pre[u] = tim++;
	for(auto it : v[u])
		if(it != p) {
			dfs(it, u);
			siz[u] += siz[it];
			if(siz[heavy[u]] < siz[it])
				heavy[u] = it;
		}
	post[u] = tim - 1;
}

pair<int, int> jump[nax];

void dfs2(int u, int p, pair<int, int> last = {-1, -1}) {
	jump[u] = last;
	for(auto it : v[u]) {
		if(it != p) {
			if(!(heavy[u] == it))
				dfs2(it, u, {it, siz[it]});
			else
				dfs2(it, u, last);
		}
	}
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
	
	int odw = pt(n, mod - 2);
	
	for(int i = 1; i <= m; ++i) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int ver, d;
			scanf("%d %d", &ver, &d);
			block[ver] += d;
			block[ver] %= mod;
			range(1, n, (ll) d * n % mod);
			range(1, n, (ll) -(n - siz[ver]) * d % mod);
			range(pre[ver], post[ver], (ll) (n - siz[ver]) * d % mod);
			if(heavy[ver])
				range(pre[heavy[ver]], post[heavy[ver]], (ll) -siz[heavy[ver]] * d % mod);
		}
		else {
			int ver;
			scanf("%d", &ver);
			ll res = query(pre[ver]);
			ll cou = 0;
			while(jump[ver] != mp(-1, -1)) {
				cou = jump[ver].se;
				ver = jump[ver].fi;
				res -= (ll) block[parent[ver]] * cou % mod;
				ver = parent[ver];
			}
			res %= mod;
			res += mod;
			res %= mod;
			printf("%lld\n", res * odw % mod);
		}
	} 
				
				
				
	

 
 
	return 0;
}