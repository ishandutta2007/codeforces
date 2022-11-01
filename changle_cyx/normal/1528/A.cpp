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

const int MaxN = 1e5 + 5; 

int n, lef[MaxN], rit[MaxN]; 
vi adj[MaxN]; 

s64 f[MaxN][2]; 

void dfs(int u, int pre = 0) {
	f[u][0] = f[u][1] = 0; 
	for (int v : adj[u]) if (v != pre) {
		dfs(v, u); 

		f[u][0] += std::max(f[v][0] + abs(lef[u] - lef[v]), f[v][1] + abs(lef[u] - rit[v])); 
		f[u][1] += std::max(f[v][0] + abs(rit[u] - lef[v]), f[v][1] + abs(rit[u] - rit[v])); 
	}
}

void work() {
	read(n); 
	for (int i = 1; i <= n; ++i) {
		read(lef[i]), read(rit[i]); 

		adj[i].clear(); 
	}

	for (int i = 1; i < n; ++i) {
		int u, v; 
		read(u), read(v); 

		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}

	dfs(1); 

	printf("%lld\n", std::max(f[1][0], f[1][1])); 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	int T; 
	read(T); 
	while (T--) {
		work(); 
	}

	return 0; 
}