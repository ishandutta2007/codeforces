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
	using ll = long long;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		simple.init(n);
		
		std::vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		if(*std::max_element(a.begin(), a.end()) == 0)
		{
			mint ans = 0;
			for(int i = 1; i <= n; ++i) ans += simple.binom(n - 1, i - 1);
			std::cout << ans.val() << "\n";
			continue;
		}
		
		int l = 1, r = n, cl = 0, cr = 0;
		while(a[l] == 0) ++l, ++cl;
		while(a[r] == 0) --r, ++cr;
		
		mint ans = 0;
		for(int i = 0; i <= std::min(cl, cr); ++i)
		ans += simple.binom(cl, i) * simple.binom(cr, i);
		
		auto solve = [&](auto self, int l, int r) -> mint
		{
			// fprintf(stderr, "solve(%d, %d)\n", l, r);
			
			ll sl = a[l++], sr = 0;
			while(l <= r && sl != sr)
			{
				if(sl < sr) sl += a[l++];
				else sr += a[r--];
			}
			
			if(sl != sr) return 1;
			if(l > r) return 2;
			
			bool flag = true;
			for(int i = l; i <= r; ++i) if(a[i] != 0) { flag = false; break; }
			if(flag)
			{
				int len = r - l + 1;
				mint ans = 1;
				for(int i = 0; i <= len; ++i) ans += simple.binom(len + 1, i + 1);
				return ans;
			}
			
			int cl = 0, cr = 0;
			while(a[l] == 0) ++l, ++cl;
			while(a[r] == 0) --r, ++cr;
			
			mint coef = 0;
			for(int i = 0; i <= std::min(cl, cr); ++i)
			coef += simple.binom(cl + 1, i + 1) * simple.binom(cr + 1, i + 1);
			return self(self, l, r) * (coef + 1);
		};
		
		std::cout << (ans * solve(solve, l, r)).val() << "\n";
	}
	return 0;
}