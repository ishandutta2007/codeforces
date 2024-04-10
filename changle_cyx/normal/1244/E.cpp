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
	static char buf[25], *tail = buf; 
	if (x < 0)
		x = ~x + 1, putchar('-'); 
	if (!x)
		putchar('0'); 
	else
	{
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

typedef unsigned u32; 
typedef long long s64; 
typedef unsigned long long u64; 
typedef std::pair<int, int> pii; 

#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e5 + 5; 

int n; 
s64 K; 

int cnt[MaxN]; 
int a[MaxN], b[MaxN], m; 

inline void shuffle()
{
	for (int i = 1; i <= n; ++i)
	{
		b[i] = a[i]; 
	}
	std::sort(b + 1, b + n + 1); 
	m = std::unique(b + 1, b + n + 1) - b - 1; 
	for (int i = 1; i <= n; ++i)
	{
		a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b; 
		++cnt[a[i]]; 
	}
}

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n), read(K); 
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]); 
	}

	shuffle(); 

	int l = 1, r = m; 
	while (l < r && K >= std::min(cnt[l], cnt[r]))
	{
		s64 cl = 1LL * cnt[l] * (b[l + 1] - b[l]); 
		s64 cr = 1LL * cnt[r] * (b[r] - b[r - 1]); 

	//	printf("%d %d: %lld %lld: %lld: %d %d\n", l, r, cl, cr, K, cnt[l], cnt[r]); 

		if (cnt[l] < cnt[r])
		{
			if (K < cl)
			{
				int maxtim = K / cnt[l]; 
				std::cout << b[r] - b[l] - maxtim << std::endl; 
				return 0; 
			}
			K -= cl, cnt[l + 1] += cnt[l], ++l; 
		}
		else
		{
			if (K < cr)
			{
				int maxtim = K / cnt[r]; 
				std::cout << b[r] - b[l] - maxtim << std::endl; 
				return 0; 
			}
			K -= cr, cnt[r - 1] += cnt[r], --r; 
		}
	}

	std::cout << b[r] - b[l] << std::endl; 

	return 0; 
}