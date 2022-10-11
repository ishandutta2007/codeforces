#include<iostream>
using namespace std;
#define mod 1000000007LL
long long fact[500000], inv[500000], factinv[500000];
long long ncr(int n, int r) { return (n - r >= 0 && r >= 0) ? 1LL * fact[n] * factinv[r] % mod * factinv[n - r] % mod : 0; }
void init() {
	fact[0] = 1;
	for (int i = 1; i < 500000; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
	inv[1] = 1;
	for (int i = 2; i < 500000; i++) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
	factinv[0] = 1;
	for (int i = 1; i < 500000; i++) factinv[i] = 1LL * factinv[i - 1] * inv[i] % mod;
}
long long n, a[500009], cnt, b[500009], c[500009];
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i]; init();
	if (n == 1) { cout << a[0] << endl; return 0; }
	long long G = (n / 2) * 2 - 1;
	for (int i = 0; i <= G; i++) { b[i] = ncr(G / 2, i / 2); if (n % 4 < 2 && i % 2 == 1)b[i] *= -1; }
	if (n % 2 == 0) { for (int i = 0; i < n; i++)c[i] = b[i]; }
	else {
		for (int i = 0; i < n - 1; i++) {
			long long S = 1; if (i % 2 == 1)S = -1;
			c[i] += b[i]; c[i + 1] += b[i] * S;
		}
	}
	for (int i = 0; i < n; i++) {
		cnt += a[i] * c[i]; while (cnt < 0)cnt += mod*mod; cnt %= mod;
	}
	cout << cnt << endl;
	return 0;
}