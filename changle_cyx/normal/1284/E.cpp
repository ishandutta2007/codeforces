#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

typedef long long s64; 

const int MaxN = 1e4 + 5; 

struct point
{
	int x, y; 
	point(){}
	point(int _x, int _y):
		x(_x), y(_y) {}

	inline void scan()
	{
		read(x), read(y); 
	}
	inline bool which() const
	{
		return y < 0 || (!y && x < 0); 
	}
	inline void adjust()
	{
		if (which())
			x = -x, y = -y; 
	}

	inline point operator + (const point &rhs) const
	{
		return point(x + rhs.x, y + rhs.y); 
	}
	inline point operator - (const point &rhs) const
	{
		return point(x - rhs.x, y - rhs.y); 
	}
	inline s64 operator * (const point &rhs) const
	{
		return 1LL * x * rhs.y - 1LL * y * rhs.x; 
	}
	inline bool operator < (const point &rhs) const
	{
		if (which() == rhs.which())
			return *this * rhs > 0; 
		else
			return which() < rhs.which(); 
	}
}a[MaxN], b[MaxN]; 

int n, m; 

inline s64 C4(int n)
{
	return 1LL * n * (n - 1) * (n - 2) * (n - 3) / 24; 
} 

inline s64 C3(int n)
{
	return 1LL * n * (n - 1) * (n - 2) / 6; 
}

inline s64 C2(int n)
{
	return 1LL * n * (n - 1) >> 1; 
}

int main()
{
	read(n); 
	for (int i = 1; i <= n; ++i)
		a[i].scan(); 
	
	s64 ans = 0;  
	for (int st = 1; st <= n; ++st)
	{
		ans += C4(n - 1); 

		m = 0; 
		for (int i = 1; i <= n; ++i)
			if (st != i)
				b[++m] = a[i] - a[st]; 
		std::sort(b + 1, b + m + 1); 
		for (int i = 1; i <= m; ++i)
			b[i + m] = b[i]; 

		s64 res = 0; 
		for (int i = 1, j = 2; i <= m; ++i)
		{
			if (j == i - 1)
				j = i;
			while (j + 1 < i + m && b[i] * b[j + 1] > 0)
				++j; 
			ans -= C3(j - i); 
		}
		ans -= res; 
	}

	std::cout << ans << std::endl; 

	return 0; 
}