#include <bits/stdc++.h>
using namespace std;

using Poly = vector<int>;

const int P = 998244353;

Poly operator+(Poly lhs, Poly rhs) {
	Poly ret(max(lhs.size(), rhs.size()), 0);
	for (int i = 0; i < ret.size(); i++) ret[i] = ((i < lhs.size() ? lhs[i] : 0) + (i < rhs.size() ? rhs[i] : 0)) % P;
	return ret;
}

Poly operator-(Poly lhs, Poly rhs) {
	Poly ret(max(lhs.size(), rhs.size()), 0);
	for (int i = 0; i < ret.size(); i++) ret[i] = ((i < lhs.size() ? lhs[i] : 0) + (i < rhs.size() ? P - rhs[i] : 0)) % P;
	return ret;
}

Poly operator*(Poly lhs, Poly rhs) {
	Poly ret(max(0, (int)(lhs.size() + rhs.size()) - 1), 0);
	for (int i = 0; i < lhs.size(); i++) {
		for (int j = 0; j < rhs.size(); j++) {
			ret[i+j] = (ret[i+j] + lhs[i] * 1LL * rhs[j]) % P;
		}
	}
	return ret;
}

Poly operator*(Poly lhs, int rhs) {
	for (int &x : lhs) x = x * 1LL * rhs % P;
	return lhs;
}

Poly s(Poly p, int k) {
	Poly q(k, 0); p.insert(p.begin(), q.begin(), q.end());
	return p;
}

Poly dot(Poly p) {
	for (int i = 0; i < p.size(); i++) p[i] = 1LL * i * p[i] % P;
	return p;
}

int calc(Poly &a) {
	reverse(a.begin(), a.end());
	int ret = 0;
	while (!a.empty() && !a.back()) a.pop_back(), ret++;
	reverse(a.begin(), a.end());
	return ret;
}

int solve(Poly a, Poly b, int n) {
	n -= calc(a) - calc(b);
	if (n < 0) return 0;
	vector<int> c(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		c[i] = i < a.size() ? a[i] : 0;
		for (int j = 1; j < b.size() && j <= i; j++) c[i] = (c[i] + (P - c[i - j]) * 1LL * b[j]) % P;
	}
	return c[n];
}

int main() {
	int n; cin >> n;
	Poly A = {1, 0, P-1, 0, P-1}, B = dot(A), C = dot(B);
	Poly F0 = B * B * 2 - C * A, F1 = F0 + A * A - B * A * 2, F2 = F1 + A * A * 3 - B * A * 2;
	F0 = A * A * A - s(F0, 1), F1 = s(F1, 2), F2 = A * A * A - s(F2, 3);
	Poly F = F0 * F2 - F1 * F1;
	cout << (solve(B, A, n) * 6LL + P - solve(dot(F), F, n)) % P << endl;
	return 0;
}