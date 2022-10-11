#include<iostream>
#include<algorithm>
using namespace std;
long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 63; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}
long long Div(long long a, long long b, long long m) {
	return (a*modpow(b, m - 2, m)) % m;
}
long long powsum(long long a, long long b, long long m) {
	if (a == 1)return (b + 1) % m;
	return Div((modpow(a, b, m)*a - 1) % m, a - 1, m);
}
long long A, B, n, x, mod = 1000000007;
int main() {
	cin >> A >> B >> n >> x;
	long long V = modpow(A, n, mod);
	long long W = powsum(A, n - 1, mod);
	cout << ((W*B%mod) + (x*V % mod)) % mod << endl;
	return 0;
}