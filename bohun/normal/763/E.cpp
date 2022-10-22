#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;

const int nax = 1e5 + 111, p = 400;

int n, m, k, a, b, q;
vector <int> graf[nax];
int ans[nax];
int res;

struct uf {
	int p[nax], ile[nax];
	vector <pair<int*, int>> v;
	
	void init() {
		v.clear();
		FOR(i, 1, n) {
			p[i] = i;
			ile[i] = 1;
		}
	}
	
	int find(int x) {
		if(x == p[x])
			return x;
		return find(p[x]);
	}
	
	void unia(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y)
			return;
		res += 1;
		if(ile[x] > ile[y])
			swap(x, y);
		v.pb(mp(&p[x], p[x]));
		v.pb(mp(&ile[y], ile[y]));
		p[x] = y;
		ile[y] += ile[x];
	}
	
	void roll(int c = 0) {
		for(int i = ss(v) - 1; c <= i; --i) 
			*v[i].fi = v[i].se;
		v.resize(c);
	}
} ja;

		
struct gao {
	int l, r, id;
	bool operator < (gao a) {
		return r < a.r;
	}
};

vector <gao> t[nax];
int L, R;
		
void akt(int u) {
	for(auto it: graf[u]) 
		if(it >= L && it <= R)
			ja.unia(it, u);
}
	
			

int main() { 
	ios;
	cin >> n >> k >> m;
	FOR(i, 1, m) {
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	cin >> q;
	FOR(i, 1, q) {
		cin >> a >> b;
		t[a / p].pb({a, b, i});
	}
	
	FOR(i, 0, n / p) {
		if(t[i].empty())
			continue;
		res = 0;
		ja.init();
		sort(t[i].begin(), t[i].end());
		L = i * p + p - 1;
		R = L - 1;
		
		for(auto it: t[i]) {
			L = i * p + p - 1;
			int x = it.l;
			int y = it.r;
			
			if(y < L) {
				L = x;
				R = x - 1;
				while(R < y) 
					akt(++R);
				ans[it.id] = y - x + 1 - res;
				res -= ss(ja.v) / 2;
				ja.roll();
				R = i * p + p - 2;
				continue;
			}
				
			
			while(R < y)
				akt(++R);
			int siz = ss(ja.v);
			while(x < L)
				akt(--L);
			ans[it.id] = y - x + 1 - res;
			res -= (ss(ja.v) - siz) / 2;
			ja.roll(siz);
			
			
		}
	}
	
	FOR(i, 1, q)
		cout << ans[i] << endl;
			
			
		
	
	
			
		
	
	
	
	
	
	return 0;
}