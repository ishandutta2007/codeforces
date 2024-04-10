#include <bits/stdc++.h>

typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void tense(T &x, const T &y) {
	if (x > y) x = y; 
}

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

const int MaxN = 510; 
const int MaxM = MaxN * MaxN / 2; 

struct edge {
	int u, v, w; 
}e[MaxM]; 

int n, m; 
int p[MaxN][MaxN]; 
s64 dis[MaxN][MaxN]; 

int curP; 
inline bool cmp(int x, int y) {
	return dis[curP][x] < dis[curP][y]; 
}

inline void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			p[i][j] = j; 
		
		curP = i; 
		std::sort(p[i] + 1, p[i] + n + 1, cmp); 
	}
}

s64 solve(int u, int v, int w) {
	s64 res = 1LL << 50; 
	tense(res, dis[u][p[u][n]] << 1);
	tense(res, dis[v][p[v][n]] << 1);  

	for (int i = n - 1, lst = p[u][n]; i >= 1; --i) {
		int x = p[u][i]; 
		if (dis[v][x] > dis[v][lst]) {
			tense(res, dis[u][x] + dis[v][lst] + w); 
			lst = x; 
		}
	}
	
	return res; 
}

int main() {
#ifdef orzczk
	freopen("diameter.in", "r", stdin); 
#endif

	read(n), read(m); 

	memset(dis, 0x3f, sizeof(dis)); 
	for (int i = 1; i <= m; ++i) {
		int u, v, w; 
		read(u), read(v), read(w); 

		e[i] = (edge){u, v, w}; 
		tense(dis[u][v], (s64)w); 
		tense(dis[v][u], (s64)w); 
	}

	for (int i = 1; i <= n; ++i) {
		dis[i][i] = 0; 
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				tense(dis[i][j], dis[i][k] + dis[k][j]); 
			}
	init(); 

	s64 ans = 1LL << 50; 
	for (int i = 1; i <= m; ++i)
		tense(ans, solve(e[i].u, e[i].v, e[i].w)); 
	
	printf("%.2f\n", (double)(ans / 2.0)); 

	return 0; 
}