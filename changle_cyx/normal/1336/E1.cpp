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

const int mod = 998244353; 

const int MaxN = 2e5 + 5; 

int pw2[MaxN], cnt_free; 
s64 base[MaxN]; 

int n, m; 
s64 a[MaxN]; 

int ans[66];  
s64 all0, all1; 
int cnt0 = 0, cnt1 = 0; 

inline bool insert(s64 x)
{
	for (int i = m - 1; i >= 0; --i)
		if (x >> i & 1)
		{
			if (base[i])
				x ^= base[i]; 
			else
				return base[i] = x, true; 
		}
	return false; 
}

inline void dfs(int k, int upper, int *f, s64 cur = 0)
{
	if (k == upper)
	{
		// std::cout << cur << '\n'; 
		++f[__builtin_popcountll(cur)]; 
		return; 
	}

	dfs(k + 1, upper, f, cur); 
	if (base[k])
		dfs(k + 1, upper, f, cur ^ base[k]); 
}

std::map<s64, int> fa[66], fb[66];

inline void dfs2(int k, int upper, int opt, s64 cur = 0)
{
	if (k == upper)
	{
		if (opt == 0)
			++fa[__builtin_popcountll(cur & all1)][cur & all0]; 
		else
			++fb[__builtin_popcountll(cur & all1)][cur & all0]; 
		return; 
	}

	dfs2(k + 1, upper, opt, cur); 
	if (base[k])
		dfs2(k + 1, upper, opt, cur ^ base[k]); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	pw2[0] = 1; 
	read(n), read(m); 
	for (int i = 1; i <= n; ++i)
	{
		pw2[i] = 1LL * pw2[i - 1] * 2 % mod; 
		read(a[i]); 

		cnt_free += !insert(a[i]); 
	}

	for (int i = m - 1; i >= 0; --i)
		if (base[i])
			for (int j = m - 1; j > i; --j)
				if (base[j] >> i & 1)
					base[j] ^= base[i]; 

	for (int i = m - 1; i >= 0; --i)
		if (!base[i])
		{
			++cnt0; 
			all0 |= 1LL << i; 
		}
		else
		{
			++cnt1; 
			all1 |= 1LL << i; 
			// std::cout << i << ' ' << base[i] << '\n'; 
		}

	// std::cout << ':' << cnt1 << '\n'; 

	if (cnt1 <= 26)
		dfs(0, m, ans); 
	else
	{
		int half = 18; 
		dfs2(0, half, 0); 
		dfs2(half, 35, 1); 

		for (int i = 0; i < 66; ++i)
			for (int j = 0; j < 66; ++j)
				if (fa[i].size() && fb[j].size())
				{
					for (auto u : fa[i])
						for (auto v : fb[j])
						{
							int c = __builtin_popcountll(u.first ^ v.first); 
							ans[i + j + c] = (ans[i + j + c] + 1LL * u.second * v.second) % mod; 
						}
				}
	}

	for (int i = 0; i <= m; ++i)
	{
		putint(1LL * pw2[cnt_free] * ans[i] % mod); 
		putchar(" \n"[i == m]); 
	}

	return 0; 
}