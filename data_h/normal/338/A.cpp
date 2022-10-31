#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const long long mod = (long long)(1e9 + 9);

long long k, n, m;

long long sqr(long long x) {
	return x * x % mod;
}

long long poww(long long a, long long b) {
	if (b == 0)
		return 1;
	if (b & 1)
		return poww(a, b - 1) * a % mod;
	return sqr(poww(a, b / 2)) % mod;
}

bool check(long long c) {
	long long nn = n - c * k;
	long long mm = m - c * k;
	long long need = mm / (k - 1) * k;
	if (mm % (k - 1))
		need += mm % (k - 1);
	else
		nn++;
	if (need > nn)
		return false;
	return true;
}

int main() {
	cin >> n >> m >> k;
	long long l = 0, r = m / k, mid;
	while(l < r) {
		mid = (l + r) / 2;
		if (check(mid)) 
			r = mid;
		else
			l = mid + 1;
	}
	long long ans = 0;
	if (r)
		ans = (poww(2, r) + mod - 1) % mod * 2 % mod * k % mod;
	ans += m - r * k;
	cout << ans % mod << endl;
	return 0;
}