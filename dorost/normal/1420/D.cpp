/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const long long M = 998244353; 
const int N = 301234; 
long long fac[N], inv[N]; 

ll tav(ll x, ll n) {
	if (n == 0)
		return 1;
	ll a = tav(x, n / 2);
	a = a * a % M;
	if (n % 2) {
		a *= x;
		a %= M;
	}
	return a;
}

ll ent(int n, int k) { 
	if (k < 0 || k > n) { 
		return 0; 
	} 
	ll ans = fac[n]; 
	ans = (ans * inv[n - k]) % M; 
	ans = (ans * inv[k]) % M; 
	return ans; 
} 

ll ans(vector<pair<int, int>> v, int k, int n) { 
	sort(v.begin(), v.end()); 
	ll an = 0; 
	multiset <int> m; 
	for (int i = 0; i < n; i++) { 
		while (!m.empty() && (*m.begin() < v[i].F)) { 
			m.erase(m.begin()); 
		} 
		an += ent((int)m.size(), k - 1); 
		an += M; 
		an %= M; 
		m.insert(v[i].S); 
	}
	return an;
} 

int32_t main() { 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	scanf("%d%d", &n, &k);
	vector <pair<int, int>> v; 
	long long fact = 1; 
	fac[0] = 1; 
	inv[0] = 1; 
	for (int i = 1; i < N; i++) { 
		fact = (fact * i) % M; 
		fac[i] = fact; 
		inv[i] = tav(fac[i], M - 2); 
	}
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		v.push_back({l, r});
	}
	printf("%lld", ans(v, k, n));
}