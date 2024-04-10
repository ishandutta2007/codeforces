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

const int MaxN = 1 << 22 | 5; 

int ma, mb; 
int na, nb; 

int pos[MaxN]; 

s64 minans; 
int ans[MaxN]; 
int full[MaxN], sze[MaxN]; 
int a[MaxN], b[MaxN]; 

inline bool check(int x)
{
	if (full[x] == sze[x])
		return false; 
	if (!a[x << 1] && !a[x << 1 | 1])
		return true; 

	return check(a[x << 1] > a[x << 1 | 1] ? (x << 1) : (x << 1 | 1)); 
}

inline void del(int x)
{
	--sze[x]; 
	if (!a[x << 1] && !a[x << 1 | 1])
		return (void)(a[x] = 0); 

	int hev = a[x << 1] > a[x << 1 | 1] ? (x << 1) : (x << 1 | 1); 
	pos[a[hev]] = x, a[x] = a[hev]; 
	del(hev); 
}

inline void solve()
{
	read(ma), read(mb); 
	na = (1 << ma) - 1; 
	nb = (1 << mb) - 1; 
	for (int i = 1; i <= (na << 1 | 1); ++i)
		full[i] = sze[i] = a[i] = 0; 

	minans = 0; 
	for (int i = 1; i <= na; ++i)
	{
		read(a[i]); 
		pos[a[i]] = i; 
		b[i] = a[i]; 
		minans += a[i]; 
	}

	for (int i = na; i >= 1; --i)
		sze[i] = 1 + sze[i << 1] + sze[i << 1 | 1]; 
	for (int i = nb; i >= 1; --i)
		full[i] = 1 + full[i << 1] + full[i << 1 | 1]; 

	std::sort(b + 1, b + na + 1, std::greater<int>()); 

	int cnt = 0; 
	for (int i = 1; i <= na && cnt < na - nb; ++i)
	{
		if (!check(pos[b[i]]))
			continue; 

		ans[++cnt] = pos[b[i]]; 
		minans -= b[i]; 
		del(pos[b[i]]); 
	}

	putint(minans), putchar('\n'); 
	for (int i = 1; i <= cnt; ++i)
		putint(ans[i]), putchar(" \n"[i == cnt]); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	int T; 
	read(T); 
	while (T--)
		solve(); 

	return 0; 
}