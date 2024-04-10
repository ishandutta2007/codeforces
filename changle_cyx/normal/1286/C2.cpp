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
using std::multiset; 
using std::string; 
typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 110; 

int n, m; 
char ans[MaxN]; 
string s, t[MaxN]; 

struct number
{
	int a[26]; 
	inline number operator + (number rhs) const
	{
		number res; 
		for (int i = 0; i < 26; ++i)
			res.a[i] = a[i] + rhs.a[i]; 
		return res; 
	}
	inline number operator - (number rhs) const
	{
		number res; 
		for (int i = 0; i < 26; ++i)
			res.a[i] = a[i] - rhs.a[i]; 
		return res; 
	}
	inline bool operator != (number rhs) const
	{
		for (int i = 0; i < 26; ++i)
			if (a[i] != rhs.a[i])
				return true; 
		return false; 
	}
	inline bool operator < (number rhs) const
	{
		for (int i = 0; i < 26; ++i)
			if (a[i] != rhs.a[i])
				return a[i] < rhs.a[i]; 
		return false; 
	}
	inline bool only1() const
	{
		bool has = false; 
		for (int i = 0; i < 26; ++i)
			if (a[i] == 1 && !has)
				has = true; 
			else if (a[i])
				return false; 
		return has; 
	}
	inline char get1() const
	{
		for (int i = 0; i < 26; ++i)
			if (a[i])
				return i + 'a'; 
		return 0; 
	}

	inline void print()
	{
		for (int i = 0; i < 26; ++i)
			if (a[i] >= 0)
			{

				for (int j = 0; j < a[i]; ++j)
					printf("%c", i + 'a'); 
			}
			else
				printf("%c", i + 'a'), printf("nan"); 
	}
}all[MaxN], pans[MaxN]; 

multiset<number> S; 

inline void query(int l, int r)
{
	printf("? %d %d\n", l, r); 
	fflush(stdout); 
}

inline int calc(int n)
{
	return (n * (n - 1) >> 1) + n; 
}

number convert(char c)
{
	number res; 
	memset(res.a, 0, sizeof(res.a)); 
	++res.a[c - 'a'];  
	return res; 
}

number convert(string s)
{
	number res; 
	memset(res.a, 0, sizeof(res.a)); 
	int len = s.length(); 
	for (int i = 0; i < len; ++i)
		++res.a[s[i] - 'a']; 
	return res; 
}

inline void solve(int n)
{
	query(1, n); 
	for (int i = 1; i <= calc(n); ++i)
	{
		std::cin >> s; 
		S.insert(convert(s)); 
	}
	if (n == 1)
	{
		ans[1] = (S.begin())->get1(); 
		return; 
	}

	query(2, n); 
	for (int i = 1; i <= calc(n - 1); ++i)
	{
		std::cin >> s;
		S.erase(S.find(convert(s))); 
	}
	for (int i = 1; i <= n; ++i)
	{
		number tmp; 
		for (auto t : S)
			if (t.only1())
			{
				tmp = t; 
				ans[i] = t.get1(); 
				S.erase(S.find(t)); 
				break; 
			}

		multiset<number> T; 
		T.clear(); 
		for (auto w : S)
			T.insert(w - tmp); 
		S = T; 
	}
}

int main()
{
#ifdef orzczk
	freopen("tmp.in", "r", stdin); 
#endif

	read(n); 
	if (n == 1)
	{
		query(1, n); 
		std::cin >> s; 
		std::cout << "! " << s << '\n'; 
		return 0; 
	}

	m = n >> 1; 
	query(1, n); 
	for (int i = 1, lim = calc(n); i <= lim; ++i)
	{
		std::cin >> s; 
		int len = s.length(); 
		all[len] = all[len] + convert(s); 
	}
	for (int i = 1; i <= m; ++i)
	{
		pans[i] = all[i + 1]; 
		for (int j = 0; j < i; ++j)
			for (int k = 1; k <= i - j + 1; ++k)
				pans[i] = pans[i] + pans[j]; 
		for (int j = 1; j <= i + 1; ++j)
			pans[i] = pans[i] - all[1]; 
		for (int j = 0; j < 26; ++j)
			pans[i].a[j] = -pans[i].a[j]; 

	//	printf("%d\n", i); 
	//	pans[i].print(); puts(""); 
	}
	if (n & 1)
	{
		number tmp = all[1]; 
		for (int i = 1; i <= m; ++i)
			tmp = tmp - pans[i]; 
		ans[m + 1] = tmp.get1(); 
	}

	solve(m); 
	for (int i = 1; i <= m; ++i)
		ans[n - i + 1] = (pans[i] - convert(ans[i])).get1(); 
	
	printf("! "); 
	for (int i = 1; i <= n; ++i)
		putchar(ans[i]); 

	return 0; 
}