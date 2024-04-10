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
typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 3e5 + 5; 

int n; 

int fa[2][MaxN]; 
int dfsClock[2]; 
int sze[2][MaxN], dfn[2][MaxN], idx[2][MaxN]; 

vi adj[2][MaxN];  

void dfsInit(int u, int opt) {
	sze[opt][u] = 1; 
	idx[opt][dfn[opt][u] = ++dfsClock[opt]] = u; 

	// cerr << opt << ' ' << u << ' ' << dfn[opt][u] << '\n'; 
	
	for (int v : adj[opt][u]) {
		dfsInit(v, opt); 
		sze[opt][u] += sze[opt][v]; 
	}
}

inline int isAnc(int x, int y) {
	return dfn[1][x] >= dfn[1][y] && dfn[1][x] <= dfn[1][y] + sze[1][y] - 1; 
}

std::set<int> S; 
int cnt = 0, ans = 0; 

bool vis[MaxN]; 

void dfsSolve(int u) {
	int lstcnt = cnt, curvis = 0; 
	bool flg = false; 

	auto it = S.lower_bound(dfn[1][u]); 
	if (it == S.end() || !isAnc(idx[1][*it], u)) {
		flg = true; 

		if (it != S.begin()) {
			int v = idx[1][*std::prev(it)]; 

			if (!vis[v] && isAnc(u, v)) {
				vis[curvis = v] = true; 
				--cnt; 
			}
		}
		
		++cnt; 
		S.insert(dfn[1][u]); 
	}

	relax(ans, cnt); 

	for (int v : adj[0][u]) {
		dfsSolve(v); 
	}

	if (flg) {
		vis[curvis] = false; 
		cnt = lstcnt; 
		S.erase(dfn[1][u]); 
	}
}

void work() {
	read(n); 
	for (int i = 1; i <= n; ++i) {
		adj[0][i].clear(); 
		adj[1][i].clear(); 
	}
	
	for (int i = 2; i <= n; ++i) {
		read(fa[0][i]); 
		adj[0][fa[0][i]].push_back(i); 
	}
	for (int i = 2; i <= n; ++i) {
		read(fa[1][i]); 
		adj[1][fa[1][i]].push_back(i); 
	}

	for (int opt = 0; opt <= 1; ++opt) {
		dfsClock[opt] = 0; 
		dfsInit(1, opt); 
	}

	// cerr << "FUCK\n"; 

	ans = 0; 
	dfsSolve(1); 

	putint(ans), putchar('\n'); 
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