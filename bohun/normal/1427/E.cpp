#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

struct ff {
	ll a, b, c;
};

vector <ff> ans;
ll x;

map <ll, int> M;
vector <ll> G[100];

void add(ll a, ll b, ll type) {
	if (type == 0) {
		if (M.count(a + b)) return;
		ans.pb({a, b, 0});
		M[a + b] = 1;
		int bit = 64 - __builtin_clzll(a + b);
		G[bit].pb(a + b);
	}
	else {
		if (M.count(a ^ b) || (a ^ b) == 0) return;
		ans.pb({a, b, 1});
		M[a ^ b] = 1;
		int bit = 64 - __builtin_clzll(a ^ b);
		G[bit].pb(a ^ b);
	}
	
}
		

int main() {
	srand(2137);
	scanf ("%lld", &x);
	
	M[x] = 1;
	ll last = x;
	rep(i, 1, 30) {
		add(last, last, 0);
		last = last + last;
	}
	
	last = 2 * x;
	rep(i, 1, 1000) {
		add(last - x, x, 0);
		last += x;
	}
	
	for (ll i = 2; i <= 1000000000; i *= 2) {
		rep(j, 1, 888)
			add(x * j, x * i, 0);
	}
	
	per(i, 0, 50) {
		//~ cat(i);
		//~ cat(sz(ans));
		int T = 1200;
		random_shuffle(all(G[i]));
		for (auto x : G[i]) {
			if (!T) break;
			for (auto y : G[i]) {
				if (!T) break;
				if (x != y && T) {
					T--;
					add(x, y, 1);
				}
			}
		}
	}
	vector <ll> odd, even;
	
	rep(i, 0, 50)
		for (auto x : G[i]) {
			if (x % 2 == 1)
				if (sz(odd) < 40)
					odd.pb(x);
		}
		
	assert(sz(odd));
	//~ assert(sz(even));
		
	int k = (100000 - 1 - sz(ans)) / (sz(even) + sz(odd));
	//~ cat(k);
	rep(f, 0, 1) {
		for (auto x : even) {
			//~ cat(x);
			ll now = x;
			rep(i, 1, k) {
				now += x;
				//~ if (now == 32) cat(now);
				if (!M.count(now)) {
					M[now] = 1;
					ans.pb({now - x, x, 0});
				}
			}
		}
		swap(even, odd);
	}
	
	//~ cat(odd[0]);
	//~ cat(even[0]);
	
	for (auto [x, y] : M) {
		//~ cat(x);
		if (x % 2 == 0 && M.count(x + 1)) {
			ans.pb({x, x + 1, 1});
			M[1] = 1;
			//~ assert(M.count(1));
			break;
		}
	}
	
	printf ("%d\n", sz(ans));
	for (auto it : ans) {
		if (it.c == 0)
			printf ("%lld + %lld\n", it.a, it.b);
		else
			printf ("%lld ^ %lld\n", it.a, it.b);
	}
	assert(sz(ans) <= 100000);
	assert(M.count(1));
	//~ if (!M.count(1)) {
		//~ cout << "BAD = " << x << endl;
		//~ return 0;
	//~ }
	//~ else cout << "GOOD = " << x << endl;	
	//~ cat(sz(ans));
	return 0;
}