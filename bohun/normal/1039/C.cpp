#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)
#define po(x) cerr << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int mod = 1e9 + 7, nax = 500005;
int n, m, k;
ll val[nax];

map<ll, vector <pair<int, int>> > mapa;
int pot[nax];

int p[nax];

int Find(int x) {
	if(p[x] != x)
		p[x] = Find(p[x]);
	return p[x];
}

void Onion(int x, int y) {
	x = Find(x);
	y = Find(y);
	if(x == y)
		return;
	p[x] = y;
}

ll byl[nax];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	pot[0] = 1;
	for(int i = 1; i <= 500000; ++i) {
		pot[i] = (ll) pot[i - 1] * 2 % mod;
		byl[i] = -1;
	}
	
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	
	for(int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		ll c = val[a] ^ val[b];
		assert(c > 0);
		mapa[c].push_back(mp(a, b));
	}
	
	ll ans = 0;
	
	for(auto i: mapa) {
		int ile = 0;
		ll res = 1;
		for(auto it: i.se) {
			p[it.fi] = it.fi;
			p[it.se] = it.se;
		}
		for(auto it: i.se) {
			Onion(it.fi, it.se);
		}
		for(auto it: i.se) {
			if(byl[it.fi] != i.fi)
				++ile;
			if(byl[it.se] != i.fi)
				++ile;
			if(byl[it.fi] != i.fi && p[it.fi] == it.fi) {
				res = (ll) res * 2 % mod;
			}
			if(byl[it.se] != i.fi && p[it.se] == it.se) {
				res = (ll) res * 2 % mod;
			}
			byl[it.fi] = byl[it.se] = i.fi;
		}
		res = (ll) res * pot[n - ile] % mod;
		ans = (ans + res) % mod;
	}
	ans = (ans + (ll) pot[n] * (pot[k] - ss(mapa) + mod) % mod) % mod;
	cout << ans;
	
	return 0;
}