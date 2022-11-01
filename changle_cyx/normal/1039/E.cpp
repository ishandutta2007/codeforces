#include <bits/stdc++.h>

using namespace std; 

typedef pair<int, int> pii; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void putint(T x) {
	static char buf[25], *tail = buf; 
	if (!x) putchar('0'); 
	else {
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline void tense(T &x, const T &y) {
	if (x > y) x = y; 
}

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

namespace LCT {
	const int MaxN = 1e5 + 5; 
	
	int fa[MaxN], lc[MaxN], rc[MaxN], sze[MaxN]; 
	
	inline bool isroot(int x) {
		return !fa[x] || (lc[fa[x]] != x && rc[fa[x]] != x); 
	}
	
	inline int which(int x) {
		return x == rc[fa[x]]; 
	}
	
	inline void upt(int x) {
		sze[x] = 1 + (lc[x] ? sze[lc[x]] : 0) + (rc[x] ? sze[rc[x]] : 0); 
	}
	
	void rotate(int x) {
		int y = fa[x], z = fa[y], b = which(x) ? lc[x] : rc[x]; 
		if (!isroot(y)) (y == rc[z] ? rc[z] : lc[z]) = x; 
		fa[x] = z, fa[y] = x, b ? fa[b] = y : 0; 
		if (lc[y] == x) lc[y] = b, rc[x] = y; 
		else rc[y] = b, lc[x] = y; 
		upt(y);
	}
	
	void splay(int x) {
		while (!isroot(x)) {
			if (!isroot(fa[x])) rotate(which(x) == which(fa[x]) ? fa[x] : x); 
			rotate(x); 
		}
		upt(x); 
	}
	
	int access(int x) { // return y
		int y; 
		for (y = 0; x; y = x, x = fa[x]) {
			splay(x), rc[x] = y, upt(x); 
		}
		return y; 
	}
	
	int findRoot(int x) {
		access(x), splay(x); 
		while (lc[x]) x = lc[x]; 
		return splay(x), x; 
	}
	
	void cut(int x, int nxt) {
//		cerr << "\ncut : " << x << ' ' << nxt << '\n'; 
		
		access(nxt); 
		
//		cerr << nxt << ':' << lc[nxt] << ' ' << rc[nxt] << ':' << fa[x] << ' ' << lc[x] << ' ' << rc[x] << ':' << LCT::isroot(x) << '\n'; //
		
		splay(x); 
		
		if (lc[x]) cerr << "FUCK : " << x << ' ' << lc[x] << '\n'; 
		assert(!lc[x]), assert(fa[x] == nxt), assert(LCT::isroot(x)); 
		
		fa[x] = 0; 
	}
	
	void link(int x, int y) {
		assert(!fa[x]); 
		
		fa[x] = y; 
	}
	
	void init(int *nxt, int n) {
		for (int i = 1; i <= n; ++i) fa[i] = nxt[i]; 
	}
}

const int INF = 0x3f3f3f3f; 
const int MaxN = 1e5 + 5; 
const int MaxQ = 1e5 + 5; 
const int MaxLog = 18; 

int n, W, a[MaxN]; 
int Q, ans[MaxQ]; 
pii req[MaxQ]; 

int amin[MaxLog][MaxN], amax[MaxLog][MaxN]; 
int nxt[MaxN], curmin[MaxN], curmax[MaxN]; 

void findNext(int x, int lim) {
	int &p = nxt[x]; 
	for (int j = MaxLog - 1; j >= 0; --j)
		if (p + (1 << j) - 1 <= n && max(curmax[x], amax[j][p]) - min(curmin[x], amin[j][p]) <= lim) {
			relax(curmax[x], amax[j][p]), tense(curmin[x], amin[j][p]); 
			p += 1 << j; 
		}
}

int jump(int d) {
	int x = 1, res = 0; 
	while (x != n + 1) {
		int y = LCT::findRoot(x); 
		
	//	cerr << "jump : " << x << ' ' << y <<  ':' << LCT::sze[y] - 1 << ' ' << res << '\n'; 
		
		res += LCT::sze[y] - 1, x = y; 
		if (x != n + 1) findNext(x, d), x = nxt[x], ++res; 
	}
	
//	cerr << res << '\n'; //
	
	return res - 1; 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif
	
	read(n), read(W), read(Q); 
	for (int i = 1; i <= n; ++i) read(a[i]), amin[0][i] = amax[0][i] = a[i]; 
	for (int q = 1; q <= Q; ++q) {
		int x; 
		read(x), req[q] = make_pair(W - x, q); 
	}
	
	for (int j = 1; j < MaxLog; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			tense(amin[j][i] = amin[j - 1][i], amin[j - 1][i + (1 << (j - 1))]); 
			relax(amax[j][i] = amax[j - 1][i], amax[j - 1][i + (1 << (j - 1))]); 
		}
	
	priority_queue<pii, vector<pii>, greater<pii> > heap; 
	for (int i = 1; i <= n; ++i) {
		curmin[i] = curmax[i] = a[i], nxt[i] = i + 1; 
		if (i < n) heap.push({max(a[i], a[i + 1]) - min(a[i], a[i + 1]), i}); 
	}
	
	LCT::init(nxt, n); 
	sort(req + 1, req + Q + 1); 

	int S = max(1, min((int)sqrt(n * 0.25), n)); 
	for (int q = 1; q <= Q; ++q) {
		int d = req[q].first; 
		while (!heap.empty() && heap.top().first <= d) {
			int x = heap.top().second; 
			LCT::cut(x, nxt[x]), findNext(x, d), heap.pop(); 
			
			if (nxt[x] - x <= S) {
				LCT::link(x, nxt[x]); 
				if (nxt[x] <= n) heap.push({max(curmax[x], a[nxt[x]]) - min(curmin[x], a[nxt[x]]), x}); 
			}
		}
		ans[req[q].second] = jump(d); 
	}
	
	for (int q = 1; q <= Q; ++q) putint(ans[q]), putchar('\n'); 
	
	return 0; 
}