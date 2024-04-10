#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll md = 1000000007;
ll pow_mod(int a, int b) {
	if(b == 0) return 1;
	ll t = pow_mod(a, b >> 1);
	t = t * t % md;
	if(b & 1) t = t * a % md;
	return t;
}

ll p2[1010], fac[1010], invf[1010];

int main() {

	p2[0] = fac[0] = invf[0] = 1;
	for(int i = 1; i < 1010; ++i) {
		p2[i] = p2[i-1] * 2 % md;
		fac[i] = fac[i-1] * i % md;
		invf[i] = pow_mod(fac[i], md - 2);
		// assert(fac[i] * invf[i] % md == 1);
	}

	int n, m;
	scanf("%d%d", &n, &m);

	if(m == 0) {
		printf("%d\n", 0);
		return 0;
	}

	vector<int> a(m);
	for(int i = 0; i < m; ++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());		

	ll ans = fac[n - m];

	// cout << ans << endl;

	for(int i = 1; i < m; ++i) ans = ans * invf[a[i] - a[i-1] - 1] % md;

	// cout << ans << endl;

	ans = ans * invf[a[0] - 1] % md;
	ans = ans * invf[n - a[m -1]] % md;

	// cout << ans << endl;

	for(int i = 1; i < m; ++i) if(a[i] > a[i-1] + 1) ans = ans * p2[a[i] - a[i-1] - 2] % md;

	cout << ans << endl;

	return 0;
}