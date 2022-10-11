#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long X, Y, s[100009], mod = 1000000007; vector<int>vec;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

int main() {
	cin >> X >> Y;
	if (Y%X != 0) { cout << "0" << endl; return 0; }

	long long N = Y / X, L = N;
	for (int i = 2; i*i <= N; i++) {
		while (N%i == 0) { vec.push_back(i); N /= i; }
	}
	if (N != 1) vec.push_back(N);
	N = L;

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	vector<int>vec2;
	for (int i = 0; i < (1 << vec.size()); i++) {
		int J = 1;
		for (int j = 0; j < vec.size(); j++) { if ((i / (1 << j)) % 2 == 1) J *= vec[j]; }
		vec2.push_back(J);
	}
	vec = vec2;

	for (int i = 0; i < vec.size(); i++) {
		int S = 0, I = vec[i];
		for (int j = 1; j < vec.size(); j++) {
			if (I%vec[j] == 0) { S++; I /= vec[j]; }
		}
		s[i] = S;
	}

	long long ret = 0;

	for (int i = 0; i < vec.size(); i++) {
		if (s[i] % 2 == 0) ret += modpow(2, (N / vec[i]) - 1, mod);
		if (s[i] % 2 == 1) ret -= modpow(2, (N / vec[i]) - 1, mod);
	}
	cout << (ret + mod*mod) % mod << endl;
	return 0;
}