#include <iostream>
#include <string>
using namespace std;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 31; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

string S, T; int c1 = 0, c2 = 0;
long long c[500009], pows[500009], mod = 1000000007;

long long hash_value(long long l, long long r) {
	return Div((c[r] - c[l] + mod) % mod, pows[l], mod);
}

int main() {
	cin >> S >> T;
	for (int i = 0; i < S.size(); i++) { if (S[i] == '0') c1++; else c2++; }

	long long res = 1;
	for (int i = 0; i < T.size(); i++) {
		pows[i] = res;
		c[i + 1] = c[i] + 1LL * res * (T[i] - '0' + 1);
		c[i + 1] %= mod;
		res *= 311LL; res %= mod;
	}

	long long maxn = 0;
	for (int i = 1; i <= T.size(); i++) {
		long long J1 = hash_value(0, T.size() - i);
		long long J2 = hash_value(i, T.size());
		if (J1 == J2) { maxn = i; break; }
	}

	for (int i = 0; i < S.size(); i++) {
		if (c1 == 0) { cout << "1"; c2--; }
		else if (c2 == 0) { cout << "0"; c1--; }
		else {
			if (T[i%maxn] == '0') { cout << "0"; c1--; }
			else { cout << "1"; c2--; }
		}
	}
	cout << endl;
	return 0;
}