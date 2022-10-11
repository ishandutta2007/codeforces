#include<iostream>
#include<algorithm>
using namespace std;
long long mod = 1000000007;
long long phi(long long n) {
	if (n == 1)return 1LL;
	long long sum = n;
	for (long long i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			sum = sum / i*(i - 1);
			while (n%i == 0) { n /= i; }
		}
	}
	if (n != 1) { sum = sum / n*(n - 1); }
	return sum;
}
long long n, k;
int main() {
	cin >> n >> k;
	long long p = n, s = n;
	for (long long i = 1; i <= k; i += 2) {
		p = phi(p);
		if (p == s) { cout << p % mod << endl; return 0; }
		s = p;
	}
	cout << p%mod << endl;
	return 0;
}