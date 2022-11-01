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

typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e5 + 5; 

int n; 
int a[MaxN]; 
s64 s1, s2; 

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	int QAQ; 
	read(QAQ); 
	while(QAQ--)
	{
		read(n); 

		s1 = s2 = 0; 
		for (int i = 1; i <= n; ++i)
		{
			read(a[i]); 
			s1 += a[i]; 
			s2 ^= a[i]; 
		}

		s64 ans[3]; 
		memset(ans, 0, sizeof(ans)); 

		if (s1 & 1) ++s1, s2 ^= 1, ans[0] = 1; 

		for (int i = 1; i <= 62; ++i)
		{
			bool b1 = s1 >> i & 1; 
			bool b2 = s2 >> (i - 1) & 1; 

			if (b1 == b2)
				continue; 
			else
			{
				ans[0] |= 1LL << i; 
				s1 += 1LL << i; 
				s2 ^= 1LL << i; 
			}
		}

		puts("1"); 
		putint(ans[0]), putchar('\n'); 

		// s1 = s2 = ans[0]; 
		// for (int i = 1; i <= n; ++i)
		// {
		// 	s1 += a[i]; 
		// 	s2 ^= a[i]; 
		// }
		// std::cout << ':' << s1 << ' ' << 2 * s2 << '\n'; 
	}

	return 0; 
}