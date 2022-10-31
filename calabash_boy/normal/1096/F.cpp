#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 1 << 20;
const int mod = 998244353;
int n, p[N], sum[N];
int A[N], B[N];
bool bo[N];
ll ans, inv[N];
ll Pow(ll a, int x) {
	ll res = 1;
	while (x) {
		if (x & 1)
			(res *= a) %= mod;
		(a *= a) %= mod;
		x >>= 1;
	}
	return res;
}
int ask(int a[], int x) {
	int res = 0;
	while (x) {
		res += a[x];
		x -= x & -x;
	}
	return res;
}
void ins(int a[], int x) {
	while (x <= n) {
		a[x]++;
		x += x & -x;
	}
}
int main() {
	inv[0] = 1;
	for (int i = 1; i < N; ++i) inv[i] = Pow(i, mod - 2); 
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1];
		scanf("%d", p + i);
		if (p[i] == -1) {
			sum[i]++;
		} else {
			bo[p[i]] = 1;
			(ans += ask(A, n) - ask(A, p[i])) %= mod;
			ins(A, p[i]);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!bo[i]) ins(B, i);
	(ans += (ll)sum[n] * (sum[n] - 1) % mod * inv[2] % mod * inv[2] % mod) %= mod; 
	for (int i = 1; i <= n; ++i) {
		if (p[i] != -1) {
			(ans += (ll)sum[i] * inv[sum[n]] % mod * (sum[n] - ask(B, p[i])) % mod) %= mod;
			(ans += (ll)(sum[n] - sum[i]) * inv[sum[n]] % mod * ask(B, p[i]) % mod) %= mod;
		}
	}
	cout << ans;
}