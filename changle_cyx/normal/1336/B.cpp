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
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e5 + 5; 

int T; 
int n[3]; 
int a[3][MaxN]; 

inline s64 pw(s64 d)
{
	return d * d; 
}

inline s64 calc(int x, int y, int z)
{
	return pw(x - y) + pw(y - z) + pw(x - z); 
}

inline void work()
{
	for (int i = 0; i < 3; ++i)
		read(n[i]);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 1; j <= n[i]; ++j)
			read(a[i][j]);
		std::sort(a[i] + 1, a[i] + n[i] + 1); 
	}

	s64 res = 1LL << 62; 

	for (int i = 1; i <= n[0]; ++i)
	{
		int x = a[0][i]; 
		int posy = std::lower_bound(a[1] + 1, a[1] + n[1] + 1, x) - a[1]; 
		int posz = std::lower_bound(a[2] + 1, a[2] + n[2] + 1, x) - a[2]; 

//		std::cout << i << ' ' << posy << ' ' << posz << '\n'; 

		vi vy(0), vz(0); 
		for (int j = posy - 2; j <= posy + 2; ++j)
			if (j >= 1 && j <= n[1])
				vy.push_back(a[1][j]); 
		for (int j = posz - 2; j <= posz + 2; ++j)
			if (j >= 1 && j <= n[2])
				vz.push_back(a[2][j]); 

		for (int y : vy)
			for (int z : vz)
				tense(res, calc(x, y, z)); 
	}

	for (int i = 1; i <= n[1]; ++i)
	{
		int x = a[1][i]; 
		int posy = std::lower_bound(a[0] + 1, a[0] + n[0] + 1, x) - a[0]; 
		int posz = std::lower_bound(a[2] + 1, a[2] + n[2] + 1, x) - a[2]; 

//		std::cout << i << ' ' << posy << ' ' << posz << '\n'; 

		vi vy(0), vz(0); 
		for (int j = posy - 2; j <= posy + 2; ++j)
			if (j >= 1 && j <= n[0])
				vy.push_back(a[0][j]); 
		for (int j = posz - 2; j <= posz + 2; ++j)
			if (j >= 1 && j <= n[2])
				vz.push_back(a[2][j]); 

		for (int y : vy)
			for (int z : vz)
				tense(res, calc(x, y, z)); 
	}

	for (int i = 1; i <= n[2]; ++i)
	{
		int x = a[2][i]; 
		int posy = std::lower_bound(a[1] + 1, a[1] + n[1] + 1, x) - a[1]; 
		int posz = std::lower_bound(a[0] + 1, a[0] + n[0] + 1, x) - a[0]; 

//		std::cout << i << ' ' << posy << ' ' << posz << '\n'; 

		vi vy(0), vz(0); 
		for (int j = posy - 2; j <= posy + 2; ++j)
			if (j >= 1 && j <= n[1])
				vy.push_back(a[1][j]); 
		for (int j = posz - 2; j <= posz + 2; ++j)
			if (j >= 1 && j <= n[0])
				vz.push_back(a[0][j]); 

		for (int y : vy)
			for (int z : vz)
				tense(res, calc(x, y, z)); 
	}

	std::cout << res << '\n'; 
	// putint(res); 
	// putchar('\n'); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(T); 
	while (T--)
		work(); 

	return 0; 
}