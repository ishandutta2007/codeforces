#include <bits/stdc++.h>
const int P = 998244353;

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
		int n, sum = 0; std::cin >> n;
		std::vector<int> a(n);
		for(int &x : a) std::cin >> x, sum += x;
		
		int t = 0;
		for(int i = n - sum; i < n; ++i) t += a[i];
		
		mint ans = 0;
		while(t < sum)
		{
			mint p = mint(sum - t) * (sum - t);
			ans += mint(n) * (n - 1) / 2 / p;
			t += 1;
		}
		
		std::cout << ans.val() << "\n";
	}
	return 0;
}