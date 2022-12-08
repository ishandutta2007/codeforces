#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, m = 100000;
inline int power(int a, int b) {
	long long res = a, ans = 1;
	for(; b; b >>= 1, res = res * res % mod) if(b & 1) ans = ans * res % mod;
	return ans;
}
int a[100010], n, dsy[100010], prime[100010], np[100010], mu[100010], cnt;
int main() {
	np[1] = mu[1] = 1;
	scanf("%d", &n);
	for(int i = 2; i <= m; i++) {
		if(!np[i]) prime[++cnt] = i, mu[i] = -1;
		for(int j = 1; prime[j] * i <= m; j++) {
			np[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		dsy[a[i]]++;
	}
	for(int i = 1; i <= cnt; i++) {
		for(int j = m / prime[i]; j > 0; j--) {
			dsy[j] += dsy[prime[i] * j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++) if(mu[i]) ans = mu[i] == 1 ? (ans + power(2, dsy[i]) - 1) % mod : (ans - power(2, dsy[i]) + 1 + mod) % mod;
	return cout << (ans % mod + mod) % mod << endl, 0;
}