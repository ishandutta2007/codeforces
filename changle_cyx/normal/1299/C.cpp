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

const int MaxN = 1e6 + 5; 

int n; 
int a[MaxN]; 
double b[MaxN]; 

int ufs[MaxN], sze[MaxN]; 
double val[MaxN]; 

inline int ufs_find(int x)
{
	if (x == ufs[x])
		return x; 
	return ufs[x] = ufs_find(ufs[x]); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i)
		read(a[i]); 

	for (int i = n; i >= 1; --i)
	{
		ufs[i] = i, sze[i] = 1; 
		val[i] = a[i]; 

		int x = i; 
		while (x < n)
		{
			int y = ufs_find(x + 1); 
			if (val[x] >= val[y])
			{
				ufs[x] = y; 
				val[y] = (val[x] * sze[x] + val[y] * sze[y]) / (sze[x] + sze[y]); 
				sze[y] += sze[x]; 

				x = y; 
			}
			else
				break; 
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		printf("%.10f\n", val[ufs_find(i)]); 
		
		int x = ufs_find(i); 

	//	std::cout << x << '\n'; 
		if (sze[x] > 1)
		{
			// val[x] *= sze[x] / (sze[x] - 1); 
			// sze[x]--; 

			while (x < n)
			{
				int y = ufs_find(x + 1); 
				if (val[x] >= val[y])
				{
					ufs[x] = y; 
					val[y] = (val[x] * sze[x] + val[y] * sze[y]) / (sze[x] + sze[y]); 
					sze[y] += sze[x]; 

					x = y; 
				}
				else
					break; 
			}
		}
	}

	return 0; 
}