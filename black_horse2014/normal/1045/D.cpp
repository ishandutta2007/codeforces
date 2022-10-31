#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1<<16;
char ibuf[SIZE];

int ibufp = SIZE, ibufn = SIZE;

int read(char *s) {
	while (ibufn) {
		for (; ibufp < ibufn && ibuf[ibufp] <= ' '; ibufp++);
		if (ibufp < ibufn) break;
		ibufn = fread(ibuf, 1, SIZE, stdin), ibufp = 0;
	}
	int n = 0;
	while (ibufn) {
		for (; ibufp < ibufn && ibuf[ibufp] > ' '; ibufp++) s[n++] = ibuf[ibufp];
		if (ibufp < ibufn) break;
		ibufn = fread(ibuf, 1, SIZE, stdin), ibufp = 0;
	}
	if (n) s[n] = 0;
	return n;
}

int read(char& x) {
	if (ibufn == ibufp && ibufn) ibufn = fread(ibuf, 1, SIZE, stdin), ibufp = 0;
	if (!ibufn) return 0;
	x = ibuf[ibufp++];
	return 1;
}

bool read_line(char *s) {
	int n = 0;
	while (ibufn) {
		for (; ibufp < ibufn && ibuf[ibufp] != '\n'; ibufp++) s[n++] = ibuf[ibufp];
		if (ibufp < ibufn) {
			ibufp++, s[n] = 0;
			return 1;
		}
		ibufn = fread(ibuf, 1, SIZE, stdin), ibufp = 0;
	}
	s[n] = 0;
	return !!n;
}

template<typename U>
int read(U& x) {
	char str[100]; if (!read(str)) return 0;
	x = (U)atoll(str);
	return 1;
}

int read(double& x) {
	char str[100]; if (!read(str)) return 0;
	x = atof(str);
	return 1;
}

inline unsigned long long rnd() {
	return ((unsigned long long)rand() << 49) | ((unsigned long long)rand() << 33)
		| ((unsigned long long)rand() << 17) | rand();
}
const int N = 110000;
typedef double DB;
const DB eps = 1e-8;
DB dn[4 * N], sum[4 * N], val[N], p[N];
void mul(int u, int st, int ed, DB p) {
	sum[u] *= p;
	dn[u] *= p;
}

void update(int u) {
	sum[u] = sum[2 * u] + sum[2 * u + 1];
}

void down(int u, int st, int ed) {
	if (dn[u] == 1) return;
	int md = st + ed >> 1;
	mul(2 * u, st, md, dn[u]);
	mul(2 * u + 1, md + 1, ed, dn[u]);
	dn[u] = 1;
}

void mul(int u, int st, int ed, int l, int r, DB p) {
	if (st > ed) return;
	if (l <= st && ed <= r) {
		mul(u, st, ed, p);
		return;
	}
	int md = st + ed >> 1;
	down(u, st, ed);
	if (md >= l) mul(2 * u, st, md, l, r, p);
	if (md < r) mul(2 * u + 1, md + 1, ed, l, r, p);
	update(u);
}

void build(int u, int st, int ed) {
	if (st > ed) return;
	dn[u] = 1;
	if (st == ed) {
		sum[u] = val[st];
		return;
	}
	int md = st + ed >> 1;
	build(2 * u, st, md);
	build(2 * u + 1, md + 1, ed);
	update(u);
}

int T, fa[N], st[N], L[N], R[N];
vector<int> adj[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n; 
	read(n);
	for (int i = 0; i < n; i++) {
		read(p[i]);
		p[i] = min(p[i], 1.0 - eps);
		p[i] = max(p[i], eps);
	}
	for (int i = 1; i < n; i++) {
		int u, v; read(u), read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	queue<int> Q;
	Q.push(0);
	st[0] = -1;
	while (!Q.empty()) {
		int e = Q.front();
		Q.pop();
		L[e] = T + 1;
		for (auto f: adj[e]) {
			if (st[f]) continue;
			st[f] = ++T;
			val[T] = (1 - p[f]) * p[e];
			fa[f] = e;
			Q.push(f);
		}
		R[e] = T;
	}
	build(1, 1, n - 1);
	int q;
	for (read(q); q--; ) {
		int x; DB pp;
		read(x), read(pp);
		pp = min(pp, 1.0 - eps);
		pp = max(pp, eps);
		
		DB ratio = pp / p[x];
		if (L[x] <= R[x]) mul(1, 1, n - 1, L[x], R[x], ratio);
		ratio = (1 - pp) / (1 - p[x]);
		if (x) mul(1, 1, n - 1, st[x], st[x], ratio);
		p[x] = pp;
		printf("%.5lf\n", sum[1] + 1 - p[0]);
	}
	return 0; 
}