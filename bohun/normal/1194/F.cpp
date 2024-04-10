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

ld pi = 3.141592653589;
const int nax = 2e5 + 5, mod = 1e9 + 7;

int n, t[nax], last;
ll tim, sum, ans = 0;
int p2[nax];
int f[nax], odw[nax];

int pt(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}

int C(int n, int k) {
	if(k > n)
		return 0;
	return (ll) f[n] * odw[k] % mod * odw[n - k] % mod;
}

int main() {
	//cout << fixed << setprecision(10);
	scanf("%d%lld", &n, &tim);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	p2[0] = f[0] = odw[0] = 1;
	for(int i = 1; i <= n + 2; ++i) {
		f[i] = (ll) f[i - 1] * i % mod;
		odw[i] = pt(f[i], mod - 2);
		p2[i] = (ll) 2 * p2[i - 1] % mod;
	}
	last = -1;
	ll G = 0;
	for(int i = 1; i <= n; ++i) {
		sum += t[i];
		if(sum > tim)
			break;
		int m = min(tim - sum, (ll)i);
		ll mam = 0;
		if(last == -1) {
			for(int j = 0; j <= m; ++j)
				mam += C(i, j);
		}
		else {
			mam = ((ll) 2 * G + C(i - 1, last + 1)) % mod;
		}
		for(int j = last + 1; j > m; --j)
			mam = (mam - C(i, j) + mod) % mod;
		G = mam;	
		ans = (ans + (ll) mam * pt(p2[i], mod - 2 % mod)) % mod;
		last = m;
	}
	cout << ans;
			
		
				
		
	
	

	return 0;
}