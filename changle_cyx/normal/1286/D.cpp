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

const int MaxN = 3e5 + 5; 
const int MaxS = 4e5 + 5; 
const int mod = 998244353; 

inline void add(int &x, const int &y)
{
	x += y; 
	if (x >= mod)
		x -= mod; 
}

inline void dec(int &x, const int &y)
{
	x -= y; 
	if (x < 0)
		x += mod; 
}

inline int qpow(int x, int y)
{
	int res = 1; 
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1)
			res = 1LL * res * x % mod; 
	return res; 
}

int n, m; 
int x[MaxN], v[MaxN], p[MaxN], q[MaxN]; 

struct collision
{
	int i, o1, o2; 
	collision(){}
	collision(int a, int b, int c):
		i(a), o1(b), o2(c) {}
	inline bool operator < (collision rhs) const
	{
		int y1 = x[i + 1] - x[i]; 
		int x1 = o1 == o2 ? abs(v[i + 1] - v[i]) : v[i] + v[i + 1]; 

		int j = rhs.i; 
		int y2 = x[j + 1] - x[j]; 
		int x2 = rhs.o1 == rhs.o2 ? abs(v[j + 1] - v[j]) : v[j] + v[j + 1]; 
		return 1LL * y1 * x2 < 1LL * y2 * x1; 
	}
}col[MaxN]; 

struct node
{
	int mat[2][2]; 
	inline int sum() const
	{
		int res = 0; 
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				add(res, mat[i][j]); 
		return res; 
	}
	inline void init(int i)
	{
		memset(mat, 0, sizeof(mat)); 
		mat[0][0] = p[i], mat[1][1] = q[i]; 
	}
}seg[MaxN], tag[MaxN]; 

int ans; 

inline void merge(node &x, const node &tag, const node &lc, const node &rc)
{
	memset(x.mat, 0, 16); 
	for (int k1 = 0; k1 < 2; ++k1)
	for (int k2 = 0; k2 < 2; ++k2)
		if (!tag.mat[k1][k2])
		{
			for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				x.mat[i][j] = (x.mat[i][j] + 1LL * lc.mat[i][k1] * rc.mat[k2][j]) % mod; 
		}
}


namespace segment_tree
{
	#define lcc x << 1, l, mid
	#define rcc x << 1 | 1, mid + 1, r

	inline void upt(int x)
	{
		merge(seg[x], tag[x], seg[x << 1], seg[x << 1 | 1]); 
	}
	inline void build(int x, int l, int r)
	{
		if (l == r)
		{
			seg[x].init(l); 
			return; 
		}
		int mid = (l + r) >> 1; 
		build(lcc), build(rcc); 
		upt(x); 
	}
	inline void modify(int x, int l, int r, collision c)
	{
		int mid = (l + r) >> 1; 
		if (mid == c.i)
		{
			tag[x].mat[c.o1][c.o2] = true; 
			upt(x); 

			return; 
		}

		if (c.i < mid)
			modify(lcc, c);
		else
			modify(rcc, c); 
		upt(x); 
	}
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n);
	for (int i = 1; i <= n; ++i)
	{
		read(x[i]), read(v[i]), read(q[i]); 
		q[i] = 1LL * q[i] * qpow(100, mod - 2) % mod; 
		p[i] = (mod + 1 - q[i]) % mod; 
	}
	for (int i = 1; i < n; ++i)
	{
		if (p[i + 1] && q[i])
			col[++m] = collision(i, 1, 0); 
		if (p[i + 1] && p[i] && v[i] < v[i + 1])
			col[++m] = collision(i, 0, 0); 
		if (q[i + 1] && q[i] && v[i] > v[i + 1])
			col[++m] = collision(i, 1, 1); 
	}

	if (!m)
	{
		puts("0"); 
		return 0; 
	}

	std::sort(col + 1, col + m + 1); 

	using namespace segment_tree; 

	build(1, 1, n); 
	for (int i = 1; i <= m; ++i)
	{
		int p = col[i].i; 
		int tim = (x[p + 1] - x[p]) % mod; 
		int vel = col[i].o1 == col[i].o2 ? abs(v[p + 1] - v[p]) : v[p] + v[p + 1]; 
		tim = 1LL * tim * qpow(vel, mod - 2) % mod;  
	
		add(ans, 1LL * seg[1].sum() * tim % mod); 
		modify(1, 1, n, col[i]); 
		dec(ans, 1LL * seg[1].sum() * tim % mod); 
	}

	std::cout << ans << std::endl; 

	return 0; 
}