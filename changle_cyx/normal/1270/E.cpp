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
		x = -x; 
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

const int MaxN = 1e3 + 5; 
const int MaxM = 1e6 + 5; 

int n; 
double x[MaxN], y[MaxN]; 

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i)
		read(x[i]), read(y[i]); 

	bool same = false; 
	do
	{
		same = false; 

		int cnt[2]; 
		memset(cnt, 0, sizeof(cnt)); 
		for (int i = 1; i <= n; ++i)
			++cnt[(int)(x[i] + y[i] + 200000000) & 1]; 

		if (cnt[0] == n || cnt[1] == n)
		{
			same = true; 
			for (int i = 1; i <= n; ++i)
			{
				double a = (x[i] + y[i]) / 2; 
				double b = (x[i] - y[i]) / 2; 
				x[i] = a, y[i] = b; 
			}
		}
	}while (same); 

	int a = 0; 
	for (int i = 1; i <= n; ++i)
		if ((int)(x[i] + y[i] + 200000000) & 1)
			++a; 

	putint(a), putchar('\n'); 
	for (int i = 1; i <= n; ++i)
		if ((int)(x[i] + y[i] + 200000000) & 1)
			putint(i), putchar(' '); 

	return 0; 
}