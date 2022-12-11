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
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
		x--;
	}
	
	std::vector<std::vector<mint>> f(n + 1, std::vector<mint>(n + 1));
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i][0] = f[i - 1][0] * i;
		for (int j = 1; j <= i; j++) {
			f[i][j] = f[i][j - 1] - f[i - 1][j - 1];
		}
	}
	
	std::vector<std::vector<mint>> C(n + 1, std::vector<mint>(n + 1));
	C[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
	
	std::vector<mint> ans(n);
	std::vector<bool> mark(n);
	for (int i = 0, pre = 0; i < n; i++) {
		auto solve = [&](int m, int coef) {
			for (int j = 0; j <= m; j++) {
				ans[j + pre] += f[n - i - 1 - j][m - j] * C[m][j] * coef;
			}
		};
		
		int m = 0;
		for (int j = 1; j < n; j++) {
			if (!mark[j] && !mark[j - 1]) {
				m += 1;
			}
		}
		
		int cnt[2] = { 0, 0 }, bel = -1;
		for (int j = 0; j < n; j++) {
			if (!mark[j] && j < a[i]) {
				int t = (j && !mark[j - 1]);
				cnt[t] += 1;
				if (i && j == a[i - 1] + 1) {
					bel = t;
				}
			}
		}
		
		for (int t : { 0, 1 }) {
			if (cnt[t]) {
				solve(m - t, cnt[t]);
			}
		}
		
		if (bel != -1) {
			solve(m - bel, P - 1);
			pre += 1;
			solve(m - bel, 1);
			pre -= 1;
		}
		
		mark[a[i]] = true;
		if (i && a[i] == a[i - 1] + 1) {
			pre += 1;
		}
	}
	
	for (int i = n; i--; ) {
		std::cout << ans[i].val() << " ";
	}
	return 0;
}