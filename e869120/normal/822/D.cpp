#include<iostream>
using namespace std;
long long n, l, r, mod = 1000000007, ans, p[5000005];
int main() {
	cin >> n >> l >> r;
	for (int i = 2; i <= 5000000; i++) {
		for (int j = i; j <= 5000000; j += i) { if (p[j] == 0)p[j] = i; }
	}
	long long G = 1;
	for (int i = l; i <= r; i++) {
		long long ret = i, cnt = 0;
		while (ret > 1) {
			long long I = p[ret];
			ret /= I; cnt += ret*(I*(I - 1)) / 2;
		}
		cnt %= mod;
		ans += (G*cnt) % mod; G *= n; G %= mod;
	}
	cout << ans%mod << endl;
	return 0;
}