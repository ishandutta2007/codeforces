#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 1e9 + 7;
template<class T>
inline T power(T a, i64 b) {
	T res = 1;
	for (; b; b >>= 1, a *= a)
		if (b & 1) res *= a;
	return res;
}
inline int norm(int x) {
	if (x < 0) x += P;
	if (x >= P) x -= P;
	return x;
}
struct Z {
	int x;
	Z(int _x = 0) : x(norm(_x)) {}
	inline Z operator-() const {
		if (!x) return 0;
		return Z(P - x);
	}
	inline Z &operator+=(const Z &rhs) {
		x += rhs.x;
		if (x >= P) x -= P;
		return *this;
	}
	inline Z &operator-=(const Z &rhs) {
		x -= rhs.x;
		if (x < 0) x += P;
		return *this;
	}
	inline Z &operator*=(const Z &rhs) {
		x = 1ull * x * rhs.x % P;
		return *this;
	}
	inline Z inv() const {
		return power(*this, P - 2);
	}
	inline Z &operator/=(const Z &rhs) {
		*this *= rhs.inv();
		return *this;
	}
	inline friend Z operator+(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		return res += rhs, res;
	}
	inline friend Z operator-(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		return res -= rhs, res;
	}
	inline friend Z operator*(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		return res *= rhs, res;
	}
	inline friend Z operator/(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		return res /= rhs, res;
	}
};
const int N = 100005;
Z fac[N], ifac[N], pw[N];
void init(int n) {
	fac[0] = pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i;
		pw[i] = pw[i - 1] * 2;
	}
	ifac[n] = fac[n].inv();
	for (int i = n; i; --i) {
		ifac[i - 1] = ifac[i] * i;
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	init(n);
	if (k >= n) {
		cout << pw[n].x << "\n";
		return 0;
	}
	Z ans = 0;
	for (int i = 0; i <= k; ++i) {
		ans += fac[n] * ifac[i] * ifac[n - i];
	}
	cout << ans.x << "\n";
    return 0;
}