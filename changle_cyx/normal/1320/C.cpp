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

const int MaxN = 2e5 + 5; 

int n, m, p, ans = -2e9; 
int bx[MaxN], mx; 
int by[MaxN], my; 

int a[MaxN], ca[MaxN], mina[MaxN]; 
int b[MaxN], cb[MaxN], minb[MaxN]; 

struct node
{
	int l, r, d; 
}; 

std::vector<node> req[MaxN]; 

const int MaxS = MaxN << 2; 

#define lcc x << 1, l, mid
#define rcc x << 1 | 1, mid + 1, r

int maxv[MaxS], tag[MaxS]; 

inline void upt(int x)
{
	maxv[x] = std::max(maxv[x << 1], maxv[x << 1 | 1]); 
}

inline void node_add(int x, int d)
{
	maxv[x] += d; 
	tag[x] += d; 
}

inline void dnt(int x)
{
	if (tag[x])
	{
		node_add(x << 1, tag[x]); 
		node_add(x << 1 | 1, tag[x]); 
		tag[x] = 0; 
	}
}

inline void build(int x, int l, int r)
{
	if (l == r)
	{
		maxv[x] = -minb[l]; 
		return; 
	}
	int mid = (l + r) >> 1; 
	build(lcc), build(rcc); 
	upt(x); 
}

inline void modify(int x, int l, int r, int u, int v, int d)
{
	if (u <= l && r <= v)
		return node_add(x, d); 
	dnt(x); 
	int mid = (l + r) >> 1; 
	if (u <= mid)
		modify(lcc, u, v, d); 
	if (v > mid)
		modify(rcc, u, v, d); 
	upt(x); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n), read(m), read(p); 
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]), read(ca[i]); 
		bx[++mx] = a[i]; 
	}
	for (int i = 1; i <= m; ++i)
	{
		read(b[i]), read(cb[i]); 
		by[++my] = b[i]; 
	}

	std::sort(bx + 1, bx + mx + 1); 
	std::sort(by + 1, by + my + 1); 
	mx = std::unique(bx + 1, bx + mx + 1) - bx - 1; 
	my = std::unique(by + 1, by + my + 1) - by - 1; 

	memset(mina, 0x3f, sizeof(mina)); 
	memset(minb, 0x3f, sizeof(minb)); 

	for (int i = 1; i <= n; ++i)
	{
		a[i] = std::lower_bound(bx + 1, bx + mx + 1, a[i]) - bx; 
		tense(mina[a[i]], ca[i]); 
	}
	for (int i = 1; i <= m; ++i)
	{
		b[i] = std::lower_bound(by + 1, by + my + 1, b[i]) - by; 
		tense(minb[b[i]], cb[i]); 
	}

	while (p--)
	{
		int x, y, c; 
		read(x), read(y), read(c); 
		x = std::upper_bound(bx + 1, bx + mx + 1, x) - bx; 
		y = std::upper_bound(by + 1, by + my + 1, y) - by; 

		if (y <= my)
			req[x].push_back((node){y, my, c}); 
	}

	build(1, 1, my); 

	for (int i = 1; i <= mx; ++i)
	{
		for (auto p : req[i])
			modify(1, 1, my, p.l, p.r, p.d); 
		relax(ans, maxv[1] - mina[i]); 
	}

	std::cout << ans << '\n'; 

	return 0; 
}