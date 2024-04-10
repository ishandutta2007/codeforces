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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;		
const int nax = 2e5 + 11, mod = 1e9 + 7;
int n, k;
int l[nax], r[nax];
vector <pair<int, int>> v;
int ans = 0;
int fac[nax];
int odw[nax];
int bilans = 0;

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
		
int daj(int a, int b) {
	if(b > a)
		return 0;
	return (ll) fac[a] * odw[b] % mod * odw[a - b] % mod;
}

int main() {
	
	fac[0] = odw[0] = 1;
	FOR(i, 1, 200000) {
		fac[i] = (ll) fac[i - 1] * i % mod;
		odw[i] = pt(fac[i], mod - 2);
	}
	
	ios
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> l[i] >> r[i];
		v.pb(mp(l[i], 1));
		v.pb(mp(r[i] + 1, -1));
	}
	
	sort(v.begin(), v.end());
	int last = -2e9;
	
	for(int i = 0; i < ss(v); ++i) {
		int j = i;
		if(last != -2e9) {
			ans = (ans + (ll) (v[i].fi - last - 1) * daj(bilans, k) % mod) % mod;
		}
		bilans += v[i].se;
		
		while(j + 1 < ss(v) && v[j].fi == v[j + 1].fi) {
			++j;
			bilans += v[j].se;
		}
		
		i = j;
		ans = (ans + daj(bilans, k)) % mod;
		last = v[i].fi;
	}
	cout << ans;
		
	
	
	
	
	
	
	
	
	return 0;
}