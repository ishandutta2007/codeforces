#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 
typedef pair<int, int> pii; 

#define foredge(u) for (int e = adj[u], v; v = to[e], e; e = nxt[e])

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
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

template <class T>
inline bool tense(T &x, const T &y) {
	return x > y ? x = y, true : false; 
}

const int MaxQ = 50 + 5; 
const int MaxN = 100000 + 5; 
const int MaxE = MaxN << 1; 

int n; 

s64 dis[MaxN]; 
int ect, adj[MaxN], nxt[MaxE], to[MaxE], weight[MaxE]; 

void addEdge(int u, int v, int w) {
	nxt[++ect] = adj[u], adj[u] = ect, to[ect] = v, weight[ect] = w; 
}

int findFarthest(int src, s64 *d = dis) {
	static int que[MaxN], qr, res; 
	for (int i = 1; i <= n; ++i) d[i] = -1; 

	d[res = que[qr = 1] = src] = 0; 
	for (int i = 1, u; i <= qr; ++i) {
		if (d[u = que[i]] > d[res]) res = u; 
		foredge(u) if (d[v] == -1) {
			d[que[++qr] = v] = d[u] + weight[e]; 
		}
	}
	
	return res; 
}

namespace ufs {
	int ufs[MaxN], sze[MaxN], val[MaxN]; 

	void init() {
		for (int i = 1; i <= n; ++i) ufs[i] = i, sze[i] = val[i] = 1; 
	}

	inline int find(int x) {
		return ufs[x] == x ? x : ufs[x] = find(ufs[x]); 
	}

	void merge(int x, int y) {
		x = find(x), y = find(y); 
		if (sze[x] > sze[y]) swap(x, y); 
		ufs[x] = y, sze[y] += sze[x], val[y] += val[x]; 
	}

	void decval(int x) {--val[find(x)];}
	int getval(int x) {return val[find(x)];}
}

int p[MaxN]; 
int S, T; 
s64 disS[MaxN], disT[MaxN]; 

int main() {
	read(n); 
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		read(u), read(v), read(w); 
		addEdge(u, v, w), addEdge(v, u, w); 
	}

	S = findFarthest(1); 
	T = findFarthest(S, disS); 
	findFarthest(T, disT); 
	
	for (int u = 1; u <= n; ++u) dis[u] = max(disS[u], disT[u]); 

	for (int i = 1; i <= n; ++i) p[i] = i; 
	sort(p + 1, p + n + 1, [=](int x, int y) {return dis[x] < dis[y];}); 

	int Q; 
	read(Q); 
	for (int q = 1; q <= Q; ++q) {
		s64 L; 
		read(L); 

		ufs::init(); 
		
		int res = 0; 
		static bool vis[MaxN]; 
		for (int i = 1; i <= n; ++i) vis[i] = false; 
		for (int i = n, j = n; i >= 1; --i) {
			int u = p[i]; 
			vis[u] = true; 
			foredge(u) if (vis[v]) ufs::merge(u, v); 
			while (j >= i && dis[p[j]] > dis[u] + L) ufs::decval(p[j--]); 
			relax(res, ufs::getval(u)); 
		}

		putint(res), putchar('\n'); 
	}
//
	return 0; 
}