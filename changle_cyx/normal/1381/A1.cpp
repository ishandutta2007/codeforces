#include <bits/stdc++.h>

template <class T>
inline void read(T &x) {
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
inline void putint(T x) {
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else {
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y) {
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}

template <class T>
inline T getAbs(const T &x) {
	return x < 0 ? -x : x; 
}

typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 2e5 + 5; 
const int MaxS = MaxN << 1; 

#define lcc x << 1, l, mid
#define rcc x << 1 | 1, mid + 1, r

int n, L; 
int b[MaxN]; 
char s[MaxN], t[MaxN]; 

int rt, pool, a[MaxN]; 
int sze[MaxN], fa[MaxN], lc[MaxN], rc[MaxN], val[MaxN]; 
bool tag[MaxN]; 

inline bool which(int x)
{
	return rc[fa[x]] == x; 
}

inline void upt(int x)
{
	sze[x] = sze[lc[x]] + sze[rc[x]] + 1; 
}

inline void dnt(int x)
{
	if (tag[x])
	{
		val[x] ^= 1; 
		std::swap(lc[x], rc[x]); 
		tag[lc[x]] ^= 1; 
		tag[rc[x]] ^= 1; 
		tag[x] = 0; 
	}
}

inline void Rotate(int x)
{
	int y = fa[x], z = fa[y]; 
	dnt(y), dnt(x); 
	int b = lc[y] == x ? rc[x] : lc[x]; 
	fa[x] = z, fa[y] = x; 
	if (b) fa[b] = y; 
	if (z) (lc[z] == y ? lc[z] : rc[z]) = x; 
	if (lc[y] == x)
		lc[y] = b, rc[x] = y; 
	else
		rc[y] = b, lc[x] = y; 
	upt(y); 
}

inline void Splay(int x, int tar)
{
	while (fa[x] != tar)
	{
		if (fa[fa[x]] != tar)
			if (which(x) == which(fa[x]))
				Rotate(fa[x]); 
			else
				Rotate(x); 
		Rotate(x); 
	}
	if (!tar) rt = x; 
	upt(x); 
}

inline int Find(int k)
{
	++k; 
	int x = rt; 
	while (x)
	{
		dnt(x); 
		if (sze[lc[x]] >= k)
			x = lc[x]; 
		else if (k == sze[lc[x]] + 1)
			return Splay(x, 0), x; 
		else
		{
			k -= sze[lc[x]] + 1; 
			x = rc[x]; 
		}
	}
}

inline void Rev(int l, int r)
{
	int x = Find(l - 1), y = Find(r + 1); 
	Splay(x, 0), Splay(y, x); 
	tag[lc[y]] ^= 1; 
}

inline int Build(int lst, int l, int r)
{
	if (l > r) return 0; 
	int mid = l + r >> 1, x = ++pool; 
	fa[x] = lst, val[x] = a[mid], tag[x] = 0, sze[x] = 1; 
	lc[x] = Build(x, l, mid - 1); 
	rc[x] = Build(x, mid + 1, r); 
	upt(x); 
	return x; 
}

void work() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = s[i] == '1'; 
		b[i] = t[i] == '1'; 
	}

	pool = 0, rt = Build(0, 0, n + 1); 
	
	std::vector<int> ans; 
	for (int i = n; i >= 2; --i) {
		if (val[Find(i)] == b[i]) continue; 
	
		if ((val[Find(1)] ^ 1) != b[i]) {
			ans.push_back(1); 
			Rev(1, 1); 
		}

		ans.push_back(i); 
		Rev(1, i); 
	}

	if (val[Find(1)] != b[1]) {
		ans.push_back(1); 
		Rev(1, 1); 
	}

	printf("%d ", (int)ans.size()); 
	for (int i = 0; i < (int)ans.size(); ++i)
		printf("%d%c", ans[i], ' ' ); 
	puts(""); 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	int T; 
	read(T); 
	while (T--) work(); 

	return 0; 
}