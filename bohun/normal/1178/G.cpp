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
const int nax = 2e5 + 5;

struct linearcht {
	struct line {
		ll x, y;
	};
	ll val(line a, ll x) {
		return a.x * x + a.y;
	}
	deque <line> s;
	
	ld prze(line a, line b) {
		return (ld) (b.y - a.y) / (a.x - b.x);
	}
	
	void add(ll x, ll y) {
		line a = {x, y};
		while(ss(s) && s.back().x == a.x) {
			if(s.back().y >= a.y)
				return;
			s.pop_back();
		}	
		while(ss(s) > 1 && prze(a, s[ss(s) - 2]) <= prze(s.back(), s[ss(s) - 2]))
			s.pop_back();
		s.pb(a);
	}
	
	ll opt(ll x) {
		while(ss(s) > 1 && val(s[0], x) <= val(s[1], x))
			s.pop_front();
		return val(s[0], x);
	}
};
		


int n, q;
vector <int> v[nax];
int a, b;
ll d[nax], B[nax], A[nax];
vector <pair <ll, int>> Sort[nax];

struct pier {
	const int block = 150;
	int blok[nax];
	ll a[nax];
	int dodaj[nax];
	linearcht on[10005];
	
	void akt(int nr) {
		int l = block * nr;
		int p = block * (nr + 1) - 1;
		for(int i = l; i <= p; ++i) {
			a[i] += dodaj[nr];
		}
		dodaj[nr] = 0;
		on[nr].s.clear();
		for(auto it: Sort[nr]) {
			on[nr].add(it.fi, (ll) a[it.se] * it.fi);
		}
	} 
	
	ll poj(int i) {
		return abs((ll) (a[i] + dodaj[blok[i]]) * B[i]);
	}
	
	ll daj(int nr) {
		int X = dodaj[nr];
		return on[nr].opt(X);
	}
	
	void init(int n) {
		for(int i = 0; i < n; ++i) {
			blok[i] = i / block;
			dodaj[i / block] = 0;
		}
	}
	void add(int l, int r, int val) {
		if(l > r)
			return;
		if(blok[l] == blok[r]) {
			for(int i = l; i <= r; ++i)
				a[i] += val;
			akt(blok[l]);
			return;
		}
		int x = blok[l];
		int y = blok[r];
		while(blok[l] == x) 
			a[l++] += val;
		while(blok[r] == y)
			a[r--] += val;
		for(int i = x + 1; i <= y - 1; ++i) {
			dodaj[i] += val;
		}
		akt(x);
		akt(y);
	}
	
	ll query(int l, int r) {
		ll res = 0;
		int x = blok[l];
		int y = blok[r];
		if(x == y) {
			for(int i = l; i <= r; ++i)
				res = max(res, poj(i));
			return res;
		}
		while(x == blok[l])
			res = max(res, poj(l++));
		while(y == blok[r])
			res = max(res, poj(r--));
		for(int i = x + 1; i <= y - 1; ++i)
			res = max(res, daj(i));
		return res;
	}
};
	
pier ja;

int tim = 0;
int in[nax], out[nax], seg[nax];

void dfs(int u) {
	seg[tim] = u;
	in[u] = tim++;
	for(auto it: v[u]) {
		dfs(it);
	}
	out[u] = tim;
}
			
ll pref[nax];		
		
	

int main() {
	
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &a);
		v[a].pb(i);
	}
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &A[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &d[i]);
	ja.init(n);
	dfs(1);
	for(int i = 1; i <= n; ++i) {
		pref[in[i]] += d[i];
		pref[out[i]] -= d[i];
	}
	for(int i = 0; i <= n; ++i) {
		if(i)
			pref[i] += pref[i - 1];
		B[i] = pref[i];
	}
	for(int i = 0; i < n; ++i)
		pref[i] = 0;
	for(int i = 1; i <= n; ++i) {
		pref[in[i]] += A[i];
		pref[out[i]] -= A[i];
	}
	for(int i = 0; i < n; ++i) {
		if(i)
			pref[i] += pref[i - 1];
		ja.a[i] = pref[i];
	}
	
	for(int i = 0; i < n; ++i) {
		int nr = i / 150;
		Sort[nr].pb(mp(B[i], i));
		Sort[nr].pb(mp(-B[i], i));
	}
	
		
	for(int i = 0; i <= (n - 1) / 150; ++i) {
		sort(Sort[i].begin(), Sort[i].end());
		ja.akt(i);
	}
	
	while(q--) {
		int type, x;
		scanf("%d%d", &type, &x);
		if(type == 1) {
			int val;
			scanf("%d", &val);
			ja.add(in[x], out[x] - 1, val);
		}
		else {
			printf("%lld\n", ja.query(in[x], out[x] - 1));
		}
	}
		
		
		
	
	
	
	
	
	return 0;
}