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
const int MaxS = MaxN << 2; 

struct node
{
	int d, a, b; 

	node(){}
	node(int _d, int _a, int _b):
		d(_d), a(_a), b(_b){}

	inline node operator + (const node &rhs) const
	{
		node res = *this; 
		if (res.a >= rhs.d)
		{
			res.a -= rhs.d; 
			res.a += rhs.a; 
			res.b += rhs.b + rhs.d; 
		}
		else
		{
			res.d += rhs.d - res.a; 
			res.b += res.a + rhs.b; 
			res.a = rhs.a; 
		}
		return res; 
	}
}seg[MaxS]; 

int n; 
int idx[MaxN], p[MaxN], q[MaxN]; 

#define lcc x << 1, l, mid
#define rcc x << 1 | 1, mid + 1, r

inline void upt(int x)
{
	seg[x] = seg[x << 1] + seg[x << 1 | 1]; 
}

inline void build(int x, int l, int r)
{
	if (l == r)
		return (void)(seg[x] = node(0, 0, 1)); 
	int mid = (l + r) >> 1; 
	build(lcc), build(rcc); 
	upt(x); 
}

inline void node_ban(int x)
{
	if (seg[x].a)
		seg[x] = node(0, 0, 0); 
	else
		seg[x] = node(1, 0, 0); 
}

inline void modify_ban(int x, int l, int r, int pos)
{
	if (l == r)
	{
		node_ban(x); 
		return; 
	}
	int mid = (l + r) >> 1; 
	if (pos <= mid)
		modify_ban(lcc, pos); 
	else
		modify_ban(rcc, pos); 
	upt(x); 
}

inline void modify_add(int x, int l, int r, int pos)
{
	if (l == r)
	{
		bool flg = !seg[x].b; 
		seg[x] = node(0, 1, 0); 
		if (flg)
			node_ban(x); 
		return; 
	}
	int mid = (l + r) >> 1; 
	if (pos <= mid)
		modify_add(lcc, pos); 
	else
		modify_add(rcc, pos); 
	upt(x); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i)
		read(p[i]), idx[p[i]] = i; 
	for (int i = 1; i <= n; ++i)
		read(q[i]); 

	int cur_ans = n + 1; 
	build(1, 1, n); 

	for (int i = 1; i <= n; ++i)
	{
	//	std::cerr << i << ':' << " cur = " << cur_ans << ':' << seg[1].d << ' ' << seg[1].a << ' ' << seg[1].b << '\n'; 

		while (!seg[1].a)
			modify_add(1, 1, n, idx[--cur_ans]); 

		putint(cur_ans); 
		putchar(" \n"[i == n]); 

		modify_ban(1, 1, n, q[i]); 
	}

	return 0; 
}