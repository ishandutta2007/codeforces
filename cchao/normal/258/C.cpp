#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll p(ll a, int b) {
	ll r = 1;
	for(; b; b >>= 1, a = a * a % mod)
		if(b & 1) r = r * a % mod;
	return r;
}
int inv_t[200];
void inv_table(int n, int mod) {
	inv_t[1] = 1;
	for(int i = 2; i < n; ++i)
		inv_t[i] = (mod - 1LL * (mod / i) * inv_t[mod % i] % mod) % mod;
}
int n, a[100010];
vector<int> fact[100010];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int m = a[n - 1];
	for(int i = 2; i <= m; ++i)
		for(int j = i; j <= m; j += i)
			fact[j].push_back(i);
	inv_table(200, mod);
	ll ans = 0;
	for(int i = 1; i <= m; ++i) {
		int k = 1;
		ll tmp = 1, lst = 0;
		for(int t: fact[i]) {
			int c = n - (upper_bound(a, a + n, t - 1) - a);
			lst = tmp;
			tmp = tmp * p(1LL * inv_t[k] * (k + 1) % mod, c) % mod; ++k;
		}
		ans = (ans + tmp - lst + mod) % mod;
	}
	cout << ans << endl;
	return 0;
}