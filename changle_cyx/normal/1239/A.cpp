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
	if (!x)
		putchar('0'); 
	else
	{
		if (x < 0)
			putchar('-'), x = ~x + 1; 

		static char buf[25], *tail = buf; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return x > y ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

typedef long long s64; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pi; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e5 + 5; 
const int mod = 1e9 + 7; 

int n, m, cur; 
int f[MaxN][3], fac[MaxN]; 

inline void add(int &x, const int &y)
{
	x += y; 
	if (x >= mod)
		x -= mod; 
}

inline int qpow(int x, int y)
{
	int res = 1; 
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1)
			res = 1LL * res * x % mod; 
	return res;
}

inline void fac_init(int n)
{
	fac[0] = 1; 

	for (int i = 1; i <= n; ++i)
		fac[i] = 1LL * fac[i - 1] * i % mod; 
}

inline int C(int n, int m)
{
	return 1LL * fac[n] * qpow(fac[m], mod - 2) % mod * qpow(fac[n - m], mod - 2) % mod; 
}

inline int count()
{
	int res = 0; 
	for (int i = 1; i * 2 <= n; ++i)
		add(res, 2LL * C(n - i, i) % mod); 
	return res; 
}

int main()
{
#ifdef orzczk 
	freopen("input.txt", "r", stdin); 
#endif

	std::cin >> n >> m; 

	fac_init(n); 

	f[0][0] = 2; 
	f[1][0] = 2; 

	for (int i = 2; i <= m; ++i)
	{
		if (i != 2)
			add(f[i][2], (f[i - 2][0] + f[i - 2][2]) % mod); 
		else
			f[i][2] = 2; 
		add(f[i][0], (f[i - 1][0] + f[i - 1][2]) % mod); 
	}

//	std::cout << count() << '\n'; 

	std::cout << ((s64)f[m][0] + count() + f[m][2]) % mod << '\n'; 


	return 0; 
}