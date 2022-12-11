#include <bits/stdc++.h>
const int P = 1e9 + 7;

struct mint
{
  public:
	mint(int x = 0): v(x % P) { v += ((v >> 31) & P); }
	mint(const mint &rhs): v(rhs.v) {}
	int val() const { return v; }
	
	mint &operator += (const mint &rhs) { v += rhs.v - P; v += ((v >> 31) & P); return *this; }
	mint &operator -= (const mint &rhs) { v -= rhs.v; v += ((v >> 31) & P); return *this;}
	mint &operator *= (const mint &rhs) { v = (unsigned long long)(v) * rhs.v % P; return *this; }
	mint &operator /= (const mint &rhs) { return *this *= rhs.inv(); }
	mint operator - () const { return mint() - *this; }
	
	mint pow(int n) const
	{
		mint x = *this, r = 1;
		for(; n; n >>= 1, x *= x) if(n & 1) r *= x;
		return r;
	}
	
	mint inv() const;
	
	friend mint operator + (mint lhs, const mint &rhs) { return lhs += rhs; }
	friend mint operator - (mint lhs, const mint &rhs) { return lhs -= rhs; }
	friend mint operator * (mint lhs, const mint &rhs) { return lhs *= rhs; }
	friend mint operator / (mint lhs, const mint &rhs) { return lhs /= rhs; }
	
  private:
  	int v;
};

struct _simple
{
  public:
  	friend struct mint;
  	
  	mint fac(int m) { return _fac[m]; }
  	mint ifac(int m) { return _ifac[m]; }
  	mint inv(int m) { return _inv[m]; }
  	mint binom(int n, int m)
  	{
  		if(m < 0 || m > n) return 0;
  		return _fac[n] * _ifac[m] * _ifac[n - m];
	}
  	
  	_simple(int m = 1) { init(m); }
  	
  	void init(int m)
  	{
  		n = m;
  		_fac.resize(n + 1); _ifac.resize(n + 1); _inv.resize(n + 1);
  		
  		_fac[0] = 1;
  		for(int i = 1; i <= n; ++i) _fac[i] = _fac[i - 1] * i;
  		
  		_ifac[n] = _fac[n].pow(P - 2);
  		for(int i = n; i; --i) _ifac[i - 1] = _ifac[i] * i;
  		
  		for(int i = 1; i <= n; ++i) _inv[i] = _ifac[i] * _fac[i - 1];
	}
	
  private:
  	int n;
  	std::vector<mint> _fac, _ifac, _inv;
} simple;

mint mint::inv() const
{
	if(v <= simple.n) return simple.inv(v);
	else return pow(P - 2);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		if(n == 1) { std::cout << 1 << "\n"; continue; }
		
		std::vector<mint> f(n + 1), g(n + 1), s(n + 2);
		for(int i = 2; i < n; ++i) f[i] = mint(2).pow((i + 1) / 2).inv();
		f[n] = mint(2).pow((n - 1) / 2).inv();
		for(int i = n; i >= 2; --i)
		{
			g[i] = f[i] * (1 - s[std::min(2 * i, n + 1)]);
			s[i] = g[i] + s[i + 1];
		}
		
		for(int i = 1; i <= n; ++i) std::cout << g[i].val() << "\n";
	}
	return 0;
}