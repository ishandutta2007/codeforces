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
const int nax = 500005, p = 43, mod = 998244353, pp = 37;

int n;
int a, b;
pair <int, int> t[nax];
map <pair<int, int>, int> mapka;
map <int, int> x, y;
	
int fac[nax];
		
int main() {
	
	fac[0] = 1;
	FOR(i, 1, nax - 1)
		fac[i] = (ll) fac[i - 1] * i % mod;
	
	cin >> n;
	int res = 0;
	bool good = 1;
	
	FOR(i, 1, n) {
		cin >> a >> b;
		x[a]++;
		y[b]++;
		mapka[{a, b}]++;
		t[i] = mp(a, b);
	}
	
	sort(t + 1, t + n + 1);
	FOR(i, 1, n - 1) {
		good &= (t[i + 1].se >= t[i].se);
	}
	
	
	int A = 1;
	int B = 1;
	int C = 1;
	for(auto it: x) {
		A = (ll) A * fac[it.se] % mod;
	}
	for(auto it: y) {
		B = (ll) B * fac[it.se] % mod;
	}
	for(auto it: mapka) {
		C = (ll) C * fac[it.se] % mod;
	}
	res = A + B;
	if(good) {
		res -= C;
	}
	if(res < 0)
		res += mod;
	res %= mod;
	res = fac[n] - res;
	if(res < 0)
		res += mod;
	res %= mod;
	cout << res;
		
	
	
	
	return 0;
}