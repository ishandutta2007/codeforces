#include <bits/stdc++.h>
const int MaxN = 1e3 + 5;
using ll = __int128_t;
const ll base = 1e18;

template <class T>
void read(T &x)
{
	x = 0; int ch = getchar();
	while(ch < 48 || ch > 57) ch = getchar();
	while(ch > 47 && ch < 58) x = 10 * x + ch - 48, ch = getchar();
}

struct node
{
	node *ls, *rs;
	ll val;
	
	node(int l, int r): val(0)
	{
		if(l == r) ls = rs = nullptr;
		else
		{
			int mid = (l + r) / 2;
			ls = new node(l, mid);
			rs = new node(mid + 1, r);
		}
	}
	
	~node()
	{
		if(ls != nullptr) delete ls;
		if(rs != nullptr) delete rs;
	}
	
	void update(int p, ll v, int l, int r)
	{
		if(l == r) return val = v, void();
		int mid = (l + r) / 2;
		if(p <= mid) ls -> update(p, v, l, mid);
		else rs -> update(p, v, mid + 1, r);
		val = std::__gcd(ls -> val, rs -> val);
	}
};

int main()
{
	int T; read(T);
	while(T--)
	{
		int n, m; read(n); read(m);
		
		std::vector<ll> a(n), b(m);
		for(int i = 0; i < n; ++i) read(a[i]);
		for(int i = 0; i < m; ++i) read(b[i]);
		
		std::vector<node *> x(n);
		for(int i = 0; i < n; ++i)
		{
			x[i] = new node(0, m - 1);
			for(int j = 0; j < m; ++j) x[i] -> update(j, a[i] / std::__gcd(a[i], b[j]), 0, m - 1);
		}
		
		std::vector<node *> y(m);
		for(int i = 0; i < m; ++i)
		{
			y[i] = new node(0, n - 1);
			for(int j = 0; j < n; ++j) y[i] -> update(j, b[i] / std::__gcd(b[i], a[j]), 0, n - 1);
		}
		
		bool flag = true;
		while(flag)
		{
			flag = false;
			
			for(int i = 0; i < n; ++i) if(a[i] && !flag && x[i] -> val > 1)
			{
				flag = true;
				a[i] = 0;
				for(int j = 0; j < m; ++j) if(b[j]) y[j] -> update(i, 0, 0, n - 1);
			}
			
			for(int i = 0; i < m; ++i) if(b[i] && !flag && y[i] -> val > 1)
			{
				flag = true;
				b[i] = 0;
				for(int j = 0; j < n; ++j) if(a[j]) x[j] -> update(i, 0, 0, m - 1);
			}
		}
		
		a.erase(std::remove(a.begin(), a.end(), 0), a.end());
		b.erase(std::remove(b.begin(), b.end(), 0), b.end());
		
		if(!a.size() || !b.size()) std::cout << "NO" << "\n";
		else
		{
			std::cout << "YES" << "\n";
			std::cout << a.size() << " " << b.size() << "\n";
			
			for(ll x : a)
			{
				if(x >= base) std::cout << static_cast<long long>(x / base) << std::right << std::setfill('0') << std::setw(18);
				std::cout << static_cast<long long>(x % base) << " ";
			}
			std::cout << "\n";
			
			for(ll x : b)
			{
				if(x >= base) std::cout << static_cast<long long>(x / base) << std::right << std::setfill('0') << std::setw(18);
				std::cout << static_cast<long long>(x % base) << " ";
			}
			std::cout << "\n";
		}
		
		for(int i = 0; i < n; ++i) delete x[i];
		for(int i = 0; i < m; ++i) delete y[i];
	}
	return 0;
}