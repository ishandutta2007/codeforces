#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long mod = 1000000007;
long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 63; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }q *= q; q %= m;
	}
	return p;
}
long long inv(long long a, long long b, long long m) {
	return (a*modpow(b, m - 2, m)) % m;
}
int main() {
	long long n, p = 1, a; cin >> n; bool OK = false;
	for (int i = 0; i < n; i++) { cin >> a; if (a % 2 == 0)OK = true; a %= (mod - 1); p *= a; p %= (mod - 1); }
	long long H = modpow(2, (p + mod - 2) % (mod - 1), mod);
	long long I = 0;
	if (OK == false)I = inv(H - 1, 3, mod);
	if (OK == true)I = inv(H + 1, 3, mod);
	cout << I << "/" << H << endl;
	return 0;
}