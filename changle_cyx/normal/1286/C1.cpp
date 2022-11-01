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
using std::map; 
using std::string; 
typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 110; 

int n; 
char ans[MaxN]; 
string s, t[MaxN]; 

map<string, int> cnt; 

inline void query(int l, int r)
{
	printf("? %d %d\n", l, r); 
	fflush(stdout); 
}

inline void psort(string &s)
{
	int n = s.length(); 
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < n; ++j)
			if (s[i] > s[j])
				std::swap(s[i], s[j]); 
}

int main()
{
	read(n); 
	if (n == 1)
	{
		query(1, n); 
		std::cin >> s; 
		std::cout << "! " << s << '\n'; 
		return 0; 
	}

	query(1, 1); 
	std::cin >> s; 
	ans[1] = s[0]; 
	++cnt[s]; 

	query(2, n); 
	int tot = ((n - 1) * (n - 2) >> 1) + (n - 1); 
	for (int i = 1; i <= tot; ++i)
	{
		std::cin >> s; 
		psort(s); 
		++cnt[s]; 
	}

	query(1, n); 
	tot = (n * (n - 1) >> 1) + n; 

	int m = 0; 
	for (int i = 1; i <= tot; ++i)
	{
		std::cin >> s; 
		psort(s); 
		if (cnt[s])
			--cnt[s]; 
		else
			t[++m] = s; 
	}
	std::sort(t + 1, t + m + 1); 

	static int buc[300]; 
	for (int i = 1; i <= m; ++i)
	{
		memset(buc, 0, sizeof(buc)); 
		int len = t[i].length(); 
		for (int j = 0; j < len; ++j)
			++buc[t[i][j]]; 
		for (int j = 1; j <= i; ++j)
			--buc[ans[j]]; 
		for (int j = 0; j < len; ++j)
			if (buc[t[i][j]])
			{
				ans[i + 1] = t[i][j]; 
				break; 
			}
	}

	printf("! "); 
	for (int i = 1; i <= n; ++i)
		putchar(ans[i]); 

	return 0; 
}