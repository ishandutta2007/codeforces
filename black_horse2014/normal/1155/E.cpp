#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a(11);
	auto query = [&](int x) {
		cout << "? " << x << endl;
		cout.flush();
		int ret; cin >> ret;
		return ret;
	};
	for (int i = 0; i < 11; i++) {
		a[i] = query(i);
		if (a[i] == 0) {
			cout << "! " << i << endl;
			cout.flush();
			return 0;
		}
	}
	const int P = 1e6 + 3;
	auto fast_exponentiation = [&](int a, int n, int p) {
		int ret = 1;
		for (; n; n >>= 1, a = 1LL * a * a % p) {
			if (n & 1) {
				ret = ret * 1LL * a % P;
			}
		}
		return ret;
	};
	vector<int> f(11), g(11);
	for (int i = 0; i < 11; i++) {
		f[i] = i == 0 ? 1 : f[i - 1] * i % P;
		g[i] = fast_exponentiation(f[i], P - 2, P);
	}
	for (int i = 11; i < P; i++) {
		vector<int> L(11), R(11);
		for (int j = 0; j < 11; j++) {
			L[j] = j == 0 ? 1 : L[j - 1] * 1LL * (i - j + 1) % P;
			R[j] = j == 0 ? 1 : R[j - 1] * 1LL * (i - (11 - j)) % P;
		}
		int ret = 0;
		for (int j = 0; j < 11; j++) {
			int cur = L[j] * 1LL * R[10 - j] % P * g[j] % P * g[10 - j] % P * a[j] % P;
			if (j & 1) {
				cur = P - cur;
			}
			ret = (ret + cur) % P;
		}
		if (ret == 0) {
			cout << "! " << i << '\n';
			cout.flush();
			return 0;
		}
	}
	cout << "! -1\n";
	cout.flush();
	return 0;
}