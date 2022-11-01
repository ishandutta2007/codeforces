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

template <class T>
inline void putint(T x)
{
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

using std::min; 
using std::max; 
using std::pair; 
using std::cin; 
using std::cout; 
using std::vector; 
typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e5 + 5; 

struct point
{
	int x, y; 
	point(){}
	point(int _x, int _y):
		x(_x), y(_y) {}
	inline s64 norm() const
	{
		return 1LL * x * x + 1LL * y * y; 
	}
	inline void scan()
	{
		read(x), read(y); 
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
}a[MaxN]; 

int n; 

inline int nxt(int i)
{
	return i == n ? 1 : i + 1; 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i)
		a[i].scan(); 

	int j = 3; 
	for (int i = 1; i <= n; ++i)
	{
		point d = a[nxt(i)] - a[i]; 
		while (nxt(j) != i && d * (a[nxt(j)] - a[i]) > d * (a[j] - a[i]))
			j = nxt(j); 
		if ((a[nxt(j)] - a[j]) * point(-d.x, -d.y) || (a[nxt(j)] - a[j]).norm() != point(-d.x, -d.y).norm())
			return puts("NO"), 0; 
	}

	puts("YES"); 

	return 0; 
}