#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 998244353;
const int mod = P;
template<class T>
inline T power(T a, i64 b) {
	T res = 1;
	for (; b; b >>= 1, a *= a)
		if (b & 1) res *= a;
	return res;
}
struct Z {
	int x;
	Z(int _x = 0) : x(_x) {}
	inline Z operator-() const {
		if (!x) return 0;
		return Z(P - x);
	}
	inline Z &operator+=(const Z &rhs) {
		x += rhs.x;
		if (x > P) x -= P;
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
	inline Z operator+(const Z &rhs) const {
		Z res = *this;
		return res += rhs;
	}
	inline Z operator-(const Z &rhs) const {
		Z res = *this;
		return res -= rhs;
	}
	inline Z operator*(const Z &rhs) const {
		Z res = *this;
		return res *= rhs;
	}
	inline Z operator/(const Z &rhs) const {
		Z res = *this;
		return res /= rhs;
	}
};
vector<int> rev;
vector<Z> roots{0, 1};
using poly = vector<Z>; 
void dft(poly &a) {
	int n = a.size();
	if (int(rev.size()) != n) {
		rev.resize(n);
		int k = __builtin_ctz(n) - 1;
		for (int i = 0; i < n; ++i) 
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
	}
	for (int i = 0; i < n; ++i)
		if (i < rev[i]) swap(a[i], a[rev[i]]);
	if (int(roots.size()) < n) {
		int k = __builtin_ctz(roots.size());
		roots.resize(n);
		for (; (1 << k) < n; ++k) {
			Z e = power(Z(3), (P - 1) >> (k + 1));
			for (int i = 1 << (k - 1); i < (1 << k); ++i) {
				roots[i * 2] = roots[i];
				roots[i * 2 + 1] = roots[i] * e;
			}
		}
	}
	for (int k = 1; k < n; k *= 2) {
		for (int i = 0; i < n; i += k * 2) {
			for (int j = 0; j < k; ++j) {
				Z x = a[i + j];
				Z y = a[i + j + k] * roots[k + j];
				a[i + j] = x + y;
				a[i + j + k] = x - y;
			}			
		}
	}
}
void idft(poly &a) {
	reverse(a.begin() + 1, a.end());
	dft(a);
	int n = a.size();
	Z inv = Z(n).inv();
	for (int i = 0; i < n; ++i)
		a[i] *= inv;
}
inline int extend(int len) {
	int n = 1;
	while (n < len) 
		n <<= 1;
	return n;
}
poly operator*(poly a, poly b) {
	if (a.empty() || b.empty()) return poly();
	int len = int(a.size() + b.size()) - 1;
	int n = extend(len);
	a.resize(n), dft(a);
	b.resize(n), dft(b);
	for (int i = 0; i < n; ++i)
		a[i] *= b[i];
	idft(a);
	a.resize(len);
	return a;
}
int n=100000,m,f[100010],g[100010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int t;
    cin >> t;

    while (t--) {
		int n, k;
		cin >> n >> k;

		int msk = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			msk |= 1 << x;
		}

		if (msk == 2) {
			cout << "YES\n";
		} else if (msk == 3) {
			cout << (n >= k ? "YES" : "NO") << "\n"; 
		} else {
			cout << "NO\n";
		}
	}
	
	return 0;
}