#include <bits/stdc++.h>
const int P = 1e9 + 7;
struct mint {
  public:
  	mint(int x = 0): v(x % P) { x += ((x >> 31) & P); }
  	int val() const { return v; }
  	
  	mint &operator += (const mint &rhs) { v += rhs.v - P; v += ((v >> 31) & P); return *this; }
  	mint &operator -= (const mint &rhs) { v -= rhs.v; v += ((v >> 31) & P); return *this; }
  	mint &operator *= (const mint &rhs) { v = (unsigned long long)(v) * rhs.v % P; return *this; }
  	mint &operator /= (const mint &rhs) { return *this *= rhs.inv(); }
  	
  	friend mint operator + (mint lhs, const mint &rhs) { return lhs += rhs; }
  	friend mint operator - (mint lhs, const mint &rhs) { return lhs -= rhs; }
  	friend mint operator * (mint lhs, const mint &rhs) { return lhs *= rhs; }
  	friend mint operator / (mint lhs, const mint &rhs) { return lhs /= rhs; }
  	
  	mint inv() const;
  	
  	mint pow(int n) const {
  		mint x = *this, r = 1;
  		for (; n; n >>= 1, x *= x) {
  			if (n & 1) {
  				r *= x;
			}
		}
		return r;
	}
  private:
  	int v;
};

struct _simple {
  public:
	friend struct mint;
	_simple() { init(1); }
	
	mint fac(int n) const { return _fac[n]; }
	mint ifac(int n) const { return _ifac[n]; }
	mint binom(int n, int m) const {
		if (m < 0 || m > n) {
			return 0;
		} else {
			return _fac[n] * _ifac[m] * _ifac[n - m];
		}
	}
	
	void init(int n) {
		_n = n;
		_fac.resize(n + 1), _ifac.resize(n + 1);
		
		_fac[0] = 1;
		for (int i = 1; i <= n; i++) {
			_fac[i] = _fac[i - 1] * i;
		}
		
		_ifac[n] = _fac[n].pow(P - 2);
		for (int i = n; i >= 1; i--) {
			_ifac[i - 1] = _ifac[i] * i;
		}
	}
  private:
  	int _n;
  	std::vector<mint> _fac, _ifac;
} simple;

mint mint::inv() const {
	return pow(P - 2);
}

using matrix = std::array<std::array<mint, 2>, 2>;
matrix operator * (matrix a, matrix b) {
	matrix c;
	for (int i : { 0, 1 }) {
		for (int j : { 0, 1 }) {
			for (int k : { 0, 1 }) {
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	return c;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T;
	std::cin >> T;
	
	mint f0 = mint(1) / 2, f1 = mint(3) / 4;
	while (T--) {
		int n, m;
		std::cin >> n >> m;
		simple.init(n + m);
		
		matrix t {{ { 2, 0 }, { 1, 2 } }};
		std::vector<matrix> pw(std::max(n, m) + 1);
		pw[0] = {{ { 1, 0 }, { 0, 1 } }};
		for (int i = 1; i <= std::max(n, m); i++) {
			pw[i] = pw[i - 1] * t;
		}
		
		mint ans = 0;
		for (int i = 0; i <= std::min(n, m); i++) {
			matrix z = pw[i] * pw[n - i] * pw[m - i];
			mint res = z[1][0] * f0 + z[1][1] * f1;
			mint coef = simple.fac(i + (n - i) + (m - i));
			for (int x : { i, n - i, m - i }) {
				coef *= simple.ifac(x);
			}
			
			if (i & 1) {
				ans -= res * coef;
			} else {
				ans += res * coef;
			}
		}
		std::cout << ans.val() << "\n";
	}
	return 0;
}