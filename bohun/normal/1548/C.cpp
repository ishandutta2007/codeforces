#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
typedef long long ll;
using namespace std;
const int P = 1e9 + 7;
const int N = 3e6 + 100;
ll power(ll a, ll b) {
	ll res = 1;
	for (; b; b /= 2, a = a * a % P)
		if (b & 1)
			res = res * a % P;
	return res;
}
ll f[N], r[N], dp[N];
ll C(int n, int k) {
	if (n < k) return 0;
	return f[n] * r[n - k] % P * r[k] % P;
}
void add(ll &a, ll b) {
	while (b < 0)
		b += P;
	a = (a + b) % P;
}
int n, q;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	f[0] = r[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = f[i - 1] * i % P;
		r[i] = power(f[i], P - 2);
	}
	for (int j = 0; j < 3; j++)
		for (int i = 0; i <= 3 * n; i += 3)
			add(dp[j], C(i, j));
	ll inv3 = power(3, P - 2);
	for (int j = 3; j <= 3 * n; j++) {
		ll sum = C(3 * n + 1, j + 1);
		add(sum, C(3 * n, j));
		add(sum, C(3 * n, j));
		ll b = (dp[j - 2] - C(3 * n, j - 2)) % P;
		ll c = (dp[j - 1] - C(3 * n, j - 1)) % P;
		add(sum, -b);
		add(sum, -(c + c + c));
		dp[j] = sum * inv3 % P;
	}
	while (q--) {
		int a;
		cin >> a;
		cout << (dp[a] + P) % P << "\n";
	}
	return 0;
}