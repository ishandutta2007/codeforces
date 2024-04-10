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

const int base = 7; 
const int MaxN = 2e5 + 5; 
const int mod[3] = {(int)1e9 + 7, (int)1e9 + 9, 998244353}; 

int n; 
char s[MaxN]; 

int cnt[MaxN][2], pw[MaxN][3]; 
int val[MaxN][3], full[MaxN][3]; 

inline int get_val(int l, int r, int opt)
{
	int c0 = cnt[r][0] - cnt[l - 1][0]; 
	int res = (val[r][opt] - 1LL * val[l - 1][opt] * pw[c0][opt] % mod[opt] + mod[opt]) % mod[opt]; 
	if (~l & 1)
		res = (full[c0][opt] - res + mod[opt]) % mod[opt]; 

	return res; 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	scanf("%d%s", &n, s + 1); 

	for (int i = 0; i < 3; ++i)
		pw[0][i] = 1; 
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 2; ++j)
			cnt[i][j] = cnt[i - 1][j]; 
		++cnt[i][s[i] - '0']; 

		bool opt = s[i] - '0'; 

		for (int j = 0; j < 3; ++j)
		{
			val[i][j] = val[i - 1][j]; 
			pw[i][j] = 1LL * base * pw[i - 1][j] % mod[j]; 
			full[i][j] = (1LL * base * full[i - 1][j] + 3) % mod[j]; 
		}

		if (!opt)
		{
			for (int j = 0; j < 3; ++j)
				val[i][j] = (1LL * base * val[i][j] + (i & 1) + 1) % mod[j]; 
		}
	}

	int Q; 
	read(Q); 
	while (Q--)
	{
		int l1, l2, len; 
		read(l1), read(l2), read(len); 

		bool flg = true; 
		for (int i = 0; i < 3; ++i)
		{
		//	std::cout << get_val(l1, l1 + len - 1, i) << ' ' << get_val(l2, l2 + len - 1, i) << '\n'; 
			flg &= get_val(l1, l1 + len - 1, i) == get_val(l2, l2 + len - 1, i); 
		}

		puts(flg ? "Yes" : "No"); 
	}

	return 0; 
}