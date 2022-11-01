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

const int MaxN = 2e5 + 5; 

int n; 
vi adj[MaxN]; 

s64 ans[MaxN]; 
int dfsClock, fa[MaxN], dfn[MaxN], sze[MaxN], dep[MaxN]; 

int sonL, sonR, botL, botR; 

void dfsInit(int u, int pre) {
	sze[u] = 1; 
	dfn[u] = ++dfsClock; 
	
	for (int v : adj[u])
		if (v != pre) {
			fa[v] = u; 
			dep[v] = dep[u] + 1; 

			dfsInit(v, u); 
			
			sze[u] += sze[v]; 
		}
}

inline bool isAnc(int x, int y) {
	return dfn[x] >= dfn[y] && dfn[x] < dfn[y] + sze[y]; 
}

void work() {
	read(n); 

	for (int i = 0; i < n; ++i) adj[i].clear(); 

	for (int i = 1; i < n; ++i) {
		int u, v; 
		read(u), read(v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}

	for (int i = 0; i <= n + 1; ++i)
		ans[i] = 0; 
	
	dfsClock = 0; 
	dfsInit(0, 0); 

	sonL = sonR = botL = botR = 0; 
	ans[0] = 1LL * n * (n - 1) / 2; 

	int cur = 1; 
	for (int v : adj[0]) {
		ans[1] += 1LL * sze[v] * cur; 
		cur += sze[v]; 
	}

	static bool vis[MaxN]; 
	std::fill(vis, vis + n, false); 

	vis[0] = true; 
	for (int u = 1; u < n; ++u) {
		if (vis[u]) {
			ans[u + 1] = ans[u]; 
			continue; 
		}

		int up = u; 
		while (!vis[fa[up]]) {
			vis[up] = true, up = fa[up]; 
		}
		vis[up] = true; 

		if (!sonL) {
			sonL = up; 
		} else if (!isAnc(up, sonL) && !sonR) {
			sonR = up; 
		}

		if ((!isAnc(up, sonL) && !isAnc(up, sonR)) || !isAnc(u, isAnc(up, sonL) ? botL : botR)) {
			for (int i = u + 1; i <= n; ++i)
				ans[i] = 0; 
			break; 
		}

		(isAnc(up, sonL) ? botL : botR) = u; 

		if (!sonR)
			ans[u + 1] = 1LL * sze[u] * (n - sze[sonL]); 
		else
			ans[u + 1] = 1LL * sze[u] * sze[isAnc(up, sonL) ? botR : botL]; 
	}

	for (int i = 0; i <= n; ++i)
		printf("%lld%c", ans[i] - ans[i + 1], " \n"[i == n]); 
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