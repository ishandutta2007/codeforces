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

	inline point operator + (point rhs) const
	{
		return point(x + rhs.x, y + rhs.y); 
	}
	inline point operator - (point rhs) const
	{
		return point(x - rhs.x, y - rhs.y); 
	}
	inline s64 operator * (point rhs) const
	{
		return 1LL * x * rhs.y - 1LL * y * rhs.x; 
	}
	inline bool operator < (const point &rhs) const
	{
		if (which() != rhs.which())
			return which() < rhs.which(); 
		else
			return *this * rhs > 0; 
	}
}a[MaxN]; 

int n, m; 
s64 ans; 

inline s64 C2(int n)
{
	return 1LL * n * (n - 1) >> 1;
}

int main()
{
	read(n); 
	for (int i = 1; i <= n; ++i)
		a[i].scan(); 
	for (int st = 1; st <= n; ++st)
	{
		static point b[MaxN]; 
		static int cnt[2]; 

		m = 0; 
		memset(cnt, 0, sizeof(cnt)); 

		for (int i = 1; i <= n; ++i)
			if (i != st)
			{
				b[++m] = a[i] - a[st]; 
				++cnt[0]; 
			}
		std::sort(b + 1, b + m + 1); 
		for (int i = 1; i <= m; ++i)
			b[i + m] = b[i]; 

		for (int i = 1, j = 1; i <= m; ++i)
		{
			if (j == i)
			{
				--cnt[0]; 
				++cnt[1]; 
				++j; 
			}

			while (j < i + m && b[i] * b[j] > 0)
			{
				--cnt[0]; 
				++cnt[1]; 
				++j; 
			}
			ans += C2(cnt[0]) * C2(cnt[1] - 1); 

			++cnt[0], --cnt[1]; 
		}
	}

	std::cout << (ans >> 1) << std::endl; 

	return 0; 
}