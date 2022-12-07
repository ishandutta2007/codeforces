#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;
typedef long double r32;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int MaxN = 2005;

struct edge {
	int to, nxt; r32 cap;
}e[MaxN * 6]; int cnt = 1, lst[MaxN], h[MaxN], s, t; queue<int> q;

void clear() {
	for (int i = 1; i <= t; i++) lst[i] = 0; cnt = 1;
}

void addEdge(int u, int v, r32 w) {
	e[++cnt] = (edge) {v, lst[u], w}; lst[u] = cnt;
	e[++cnt] = (edge) {u, lst[v], 0}; lst[v] = cnt;
}
bool bfs() {
	memset(h, -1, sizeof(h));
	h[s] = 0; q.push(s);
	while(!q.empty()) {
		int c = q.front(); q.pop(); 
		for (int i = lst[c], b; i; i = e[i].nxt) {
			if(!~h[b = e[i].to] && e[i].cap) {
				h[b] = h[c] + 1;
				q.push(b);
			}
		}
	}
	return h[t] != -1;
}

r32 dfs(int x, r32 f = INT_MAX) {
	if(x == t) return f;
	r32 u = 0;
	for (int i = lst[x], b; i; i = e[i].nxt) {
		if(h[b = e[i].to] == h[x] + 1 && e[i].cap) {
			r32 w = dfs(b, min(e[i].cap, f - u));
			e[i].cap -= w; e[i ^ 1].cap += w; if((u += w) == f) return u;
		}
	}
	h[x] = -1; return u;
}

r32 dinic() {
	r32 ans = 0;
	while(bfs()) {
		ans += dfs(s);
	} 
	return ans;
}

int n, m, u[MaxN], v[MaxN], a[MaxN], b[MaxN], c[MaxN], d[MaxN];

r32 check(r32 t) {
	clear();
	r32 flow = 0;
	for (int e = 1; e <= m; e++) {
		r32 l = a[e] * t + b[e];
		r32 r = c[e] * t + d[e];
		addEdge(u[e], v[e], r - l);
		addEdge(s, v[e], l);
		addEdge(u[e], ::t, l);  
		flow -= l;
	}	
	flow += dinic();
	return flow;	
} 
 
int main() {
	read(n); read(m); s = n + 1; t = s + 1;
	for (int i = 1; i <= m; i++) {
		read(u[i]); read(v[i]); read(a[i]); read(b[i]); read(c[i]); read(d[i]);
	}
	
	r32 l = 0, r = 1, m1, m2, ans = 0;
	
	for (int T = 0; T < 50; T++) {
		m1 = (2 * l + r) / 3;
		m2 = (l + 2 * r) / 3;
		r32 v1 = check(m1);
		r32 v2 = check(m2);
		if(v1 > -1e-9 && v2 > -1e-9) 
			break;
		if(v1 > v2) r = m2; else l = m1;
	}
	
	l = m1; r = 0;
	for (int T = 0; T < 50; T++) {
		r32 m = (l + r) / 2;
		if(check(m) > -1e-9)
			l = m;
		else
			r = m;
	}
	
	ans = -(l + r) / 2;
	
	l = m1; r = 1;
	for (int T = 0; T < 50; T++) {
		r32 m = (l + r) / 2;
		if(check(m) > -1e-9) 
			l = m;
		else
			r = m;
	}
	ans += (l + r) / 2;
	printf("%.10Lf", ans);
	return 0;
}