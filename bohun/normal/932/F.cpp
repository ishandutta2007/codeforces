#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
 
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;	

int Q = 0;
struct cht {
	const ll INF = 1e18;
	struct line {
		mutable ll x, y, p;
		bool operator < (const line &a) const{
			return Q == 0 ? x < a.x : p < a.p;
		}
	};
	multiset <line> s;
	bool wywal(auto x, auto y) {
		if(y == s.end()) { x->p = INF; return 0; }
		if(x->x == y->x) x->p = (x->y >= y->y ? INF : -INF);
		else x->p = floor ((ld) (y->y - x->y) / (x->x - y->x));
		return x->p >= y->p;
	}
	
	void add(ll a, ll b) {
		line p = {a, b, 0};
		auto z = s.insert(p), y = z++, x = y;
		while(wywal(y, z))
			z = s.erase(z);
		if(x != s.begin() && wywal(--x, y)) wywal(x, y = s.erase(y));
		while((y = x) != s.begin() && (--x)->p >= y->p) 
			wywal(x, s.erase(y));
	}	
	
	ll opt(ll x) {
		Q = 1;
		auto l = s.lower_bound({0, 0, x});
		Q = 0;
		return l->x * x + l->y;
	}
};




const int nax = 100005;

int n;
int a[nax], b[nax];
int p, q;
vector <int> v[nax];
cht go[nax], xd;
int w[nax];
ll dp[nax];

void dfs(int u, int p) {
	int big = 0;
	for(auto it: v[u]) {
		if(it == p)
			continue;
		dfs(it, u);
		if(ss(go[w[big]].s) <= ss(go[w[it]].s)) {
			big = it;
		}
	}
	w[u] = w[big];
	if(!big) {
		dp[u] = 0;
		w[u] = u;
		go[u].add(-b[u], 0);
		return;
	}
	
	for(auto it: v[u]) {
		if(it == p || it == big) {
			continue;
		}
		for(auto i: go[w[it]].s) {
			go[w[u]].add(i.x, i.y);
		}
	}
	dp[u] = -go[w[u]].opt(a[u]);
	go[w[u]].add(-b[u], -dp[u]);
}

 
int main() {	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", b + i);
	}
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &p, &q);
		v[p].pb(q);
		v[q].pb(p);
	}
	
	dfs(1, 0);
	
	for(int i = 1; i <= n; ++i) {
		printf("%lld ", dp[i]);
	}
	
	
	
	
	return 0;
}