#include <bits/stdc++.h>
int P;
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

int main() {
	int n;
	std::cin >> n >> P;
	
	std::vector<mint> f(n + 1), g(n + 1), s(n + 2);
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			g[i] += f[i / 2];
		}
		
		for (int j = 1; 3 * j <= i; j++) {
			g[i] += f[j] * s[i - 3 * j];
		}
		
		f[i] = mint(2).pow(i - 2);
		for (int j = 1; 2 * j <= i; j++) {
			f[i] -= f[j] * s[i - 2 * j];
		}
		
		s[i + 1] = s[i] + g[i];
	}
	
	std::cout << f[n].val() << "\n";
	return 0;
}