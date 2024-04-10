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

using std::cerr; 
using std::cout; 
using std::vector; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int INFint = 0x3f3f3f3f; 

namespace SEG {
	const int MaxS = 35001 * 4 + 5; 

	#define lcc x << 1, l, mid
	#define rcc x << 1 | 1, mid + 1, r

	int n; 
	int seg[MaxS], tag[MaxS]; 

	void upt(int x) {
		seg[x] = std::min(seg[x << 1], seg[x << 1 | 1]); 
	}

	void nodeAdd(int x, int d) {
		tag[x] += d; 
		seg[x] += d; 
	}

	void dnt(int x) {
		if (tag[x]) {
			nodeAdd(x << 1 | 0, tag[x]); 
			nodeAdd(x << 1 | 1, tag[x]); 
			tag[x] = 0; 
		}
	}

	void modify(int u, int v, int d, int x = 1, int l = 0, int r = n) {
		if (u <= l && r <= v) {
			nodeAdd(x, d); 
			return; 
		}
		dnt(x); 
		int mid = (l + r) >> 1; 
		if (u <= mid) modify(u, v, d, lcc); 
		if (v >  mid) modify(u, v, d, rcc); 
		upt(x); 
	}

	void build(int x = 1, int l = 0, int r = n) {
		tag[x] = 0, seg[x] = INFint; 
		if (l == r) return; 
		int mid = (l + r) >> 1; 
		build(lcc), build(rcc); 
	}
}

const int MaxK = 100 + 5; 
const int MaxN = 35000 + 5; 

int n, K, a[MaxN]; 
vi pos[MaxN]; 

struct node {
	int l, r, d; 
	node(){}
	node(int xa, int xb, int xc): l(xa), r(xb), d(xc) {}
}; 

int f[MaxK][MaxN]; 
vector<node> addseg[MaxN]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	read(n), read(K); 
	SEG::n = n; 

	for (int i = 1; i <= n; ++i) pos[i].push_back(0); 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
		pos[a[i]].push_back(i); 
	}
	for (int i = 1; i <= n; ++i) pos[i].push_back(n + 1); 

	for (int v = 1; v <= n; ++v) {
		int s = pos[v].size() - 2; 
		for (int i = 1; i <= s; ++i) {
			int x = pos[v][i]; 
			int xl = pos[v][i - 1]; 
			int xr = pos[v][i + 1]; 

			addseg[x].emplace_back(xl, x - 1, -x); 
			addseg[x].emplace_back(0, x - 1, +x); 
			addseg[xr].emplace_back(0, x - 1, -x); 
		}
	}

	for (int k = 0; k <= K; ++k)
		for (int i = 0; i <= n; ++i)
			f[k][i] = INFint;

	f[0][0] = 0; 
	for (int k = 1; k <= K; ++k) {
		SEG::build(); 
		SEG::modify(0, 0, f[0][0] - INFint); 

		for (int i = 1; i <= n; ++i) {
			for (auto q : addseg[i])
				SEG::modify(q.l, q.r, q.d); 
			
			tense(f[k][i], SEG::seg[1]); 
			SEG::modify(i, i, f[k - 1][i] - INFint); 
		}
	}

	std::cout << f[K][n] << '\n'; 

	return 0; 
}