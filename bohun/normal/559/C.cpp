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

const int nax = 5005, mod = 1e9 + 7, N = 200005;

int h, w, n;
pair <int, int> t[nax];	
int f[N], odw[N];

int pt(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = (ll) a *  r % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}

int C(int N, int K) {
	return (ll) f[N] * odw[K] % mod * odw[N - K] % mod;
}

int daj(pair<int, int> a, pair<int, int> b) {
	if(a.fi > b.fi || a.se > b.se)
		return 0;
	int A = b.fi - a.fi;
	int B = b.se - a.se;
	return C(A + B, A);
}

int dp[nax];

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
}

pair <int, int> pocz = mp(1, 1), kon;

int main() {
	f[0] = odw[0] = 1;
	for(int i = 1; i < N; ++i) {
		f[i] = (ll) i * f[i - 1] % mod;
		odw[i] = pt(f[i], mod - 2);
	}
	
	scanf("%d%d%d", &h, &w, &n);
	kon = mp(h, w);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &t[i].fi, &t[i].se);
	}
	sort(t + 1, t + n + 1);
	
	int res = C(h + w - 2, w - 1);
	for(int i = 1; i <= n; ++i) {
		int sum = daj(pocz, t[i]);
		for(int j = 1; j < i; ++j) {
			add(sum, - ((ll) dp[j] * daj(t[j], t[i]) % mod));
		}
		dp[i] = sum;
		res = (res - (ll) sum * daj(t[i], kon) % mod + mod) % mod;
	}
	cout << res;
			
	
	
	
	
	
	return 0;
}