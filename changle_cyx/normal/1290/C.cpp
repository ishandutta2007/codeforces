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

inline int get_sta()
{
	char ch; 
	while (!isdigit(ch = getchar())); 
	return ch - '0'; 
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
typedef std::vector<int> vi; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 3e5 + 5; 

int n, K, fir_sta[MaxN], oppo[MaxN]; 
int ufs[MaxN], col[MaxN], sze[MaxN]; 

int ans; 
vi bel[MaxN]; 

inline int ufs_find(int x)
{
	if (x == ufs[x])
		return x; 
	return ufs[x] = ufs_find(ufs[x]); 
}

inline void fix_col(int x, int c)
{
	if (!x) return; 

	x = ufs_find(x); 
	if (col[x] != -1) return; 

	col[x] = c; 
	if (oppo[x])
		col[oppo[x]] = c ^ 1; 
	//std::cout << x << ' ' << c << '\n'; 

	ans -= std::min(sze[x], sze[oppo[x]]); 
	if (c) ans += sze[x]; 
	else if (oppo[x]) ans += sze[oppo[x]]; 
}

inline void ufs_merge(int &x, int y)
{
	if (!x || !y) return (void)(x += y); 

	x = ufs_find(x), y = ufs_find(y); 
	if (x == y) return; 

	ufs[y] = x, sze[x] += sze[y]; 
}

inline void set_same(int x, int y)
{
//	std::cout << x << '~' << y << '\n'; 

	x = ufs_find(x), y = ufs_find(y); 

	if (x == y || (col[x] != -1 && col[y] != -1)) return; 

	//std::cout << ":" << x << ' ' << y << ' ' << col[x] << ' ' << col[y] << '\n'; 

	if (col[x] != -1) std::swap(x, y); 
	if (col[y] != -1)
	{
		fix_col(x, col[y]); 
	}
	else
	{
		ans -= min(sze[x], sze[oppo[x]]);
		ans -= min(sze[y], sze[oppo[y]]); 
		ufs_merge(x, y); 
		ufs_merge(oppo[x], oppo[y]); 
		oppo[oppo[x]] = ufs_find(x); 

		ans += min(sze[x], sze[oppo[x]]); 
	}
}

inline void set_oppo(int x, int y)
{
//	std::cout << x << '-' << y << '\n'; 
	x = ufs_find(x), y = ufs_find(y); 

	if (col[x] != -1 && col[y] != -1)
		return; 
	if (col[x] != -1) std::swap(x, y); 
	if (col[y] != -1)
	{
		fix_col(x, col[y] ^ 1); 
	}
	else
	{
		if (oppo[x] == y) return; 

		ans -= min(sze[x], sze[oppo[x]]);
		ans -= min(sze[y], sze[oppo[y]]); 
		ufs_merge(x, oppo[y]); 
		ufs_merge(y, oppo[x]); 
		oppo[x] = y, oppo[y] = x; 
		ans += min(sze[x], sze[y]); 
	}
}

int main()
{
	read(n), read(K); 
	for (int i = 1; i <= n; ++i)
		fir_sta[i] = get_sta(); 

	for (int i = 1; i <= K; ++i)
	{
		ufs[i] = i, col[i] = -1, sze[i] = 1; 

		int c, x; 
		read(c); 
		while (c--)
		{
			read(x); 
			bel[x].push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (bel[i].empty())
		{
			printf("%d\n", ans); 
			continue;
		}
		else if (bel[i].size() == 1)
			fix_col(bel[i][0], fir_sta[i] ^ 1); 
		else
		{
			if (fir_sta[i] == 0)
				set_oppo(bel[i][0], bel[i][1]); 
			else
				set_same(bel[i][0], bel[i][1]); 
		}

		printf("%d\n", ans); 
	}

	return 0; 
}