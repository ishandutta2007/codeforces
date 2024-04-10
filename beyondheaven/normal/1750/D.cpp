#include <bits/stdc++.h>
constexpr int P = 998244353;
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
	mint inv(int n)	const { return _inv[n]; }
	mint binom(int n, int m) const {
		if (m < 0 || m > n) {
			return 0;
		} else {
			return _fac[n] * _ifac[m] * _ifac[n - m];
		}
	}
	
	void init(int n) {
		_n = n;
		_fac.resize(n + 1), _ifac.resize(n + 1), _inv.resize(n + 1);
		
		_fac[0] = 1;
		for (int i = 1; i <= n; i++) {
			_fac[i] = _fac[i - 1] * i;
		}
		
		_ifac[n] = _fac[n].pow(P - 2);
		for (int i = n; i >= 1; i--) {
			_ifac[i - 1] = _ifac[i] * i;
		}
		
		for (int i = 1; i <= n; ++i) {
			_inv[i] = _ifac[i] * _fac[i - 1];
		}
	}
  private:
  	int _n;
  	std::vector<mint> _fac, _ifac, _inv;
} simple;

mint mint::inv() const {
	if (v <= simple._n) {
		return simple.inv(v);
	} else {
		return pow(P - 2);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	auto factorize = [&](int n) {
		std::vector<int> res;
		int x = n;
		for (int i = 2; i * i <= n; i++) {
			if (x % i == 0) {
				res.push_back(i);
				while (x % i == 0) {
					x /= i;
				}
			}
		}
		if (x != 1) {
			res.push_back(x);
		}
		return res;
	};
	
	int T;
	std::cin >> T;
	while (T--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n);
		for (int &x : a) {
			std::cin >> x;
		}
		
		mint ans = 1;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] % a[i] != 0) {
				ans = 0;
				break;
			}
			
			auto p = factorize(a[i - 1] / a[i]);
			int cnt = 0;
			for (int S = 0; S < (1 << p.size()); S++) {
				int mul = a[i];
				for (int i = 0; i < int(p.size()); i++) {
					if ((S >> i) & 1) {
						mul *= p[i];
					}
				}
				
				if (__builtin_parity(S)) {
					cnt -= m / mul;
				} else {
					cnt += m / mul;
				}
			}
			
			ans *= cnt;
		}
		
		std::cout << ans.val() << "\n";
	}
	return 0;
}