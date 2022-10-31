#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
 
using namespace std;
 
template <typename T> void chkmax(T &x, T y) {x = x > y ? x : y;}
template <typename T> void chkmin(T &x, T y) {x = x > y ? y : x;}
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
 
#define DEBUG(x) std::cerr << #x << " = " << x << std::endl
 
template <typename T> void read (T &x) {
	x = 0; bool f = 1; char ch;
	do {ch = getchar(); if (ch == '-') f = 0;} while (ch > '9' || ch < '0');
	do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
	x = f ? x : -x;
}
 
template <typename T> void write (T x) {
	if (x < 0) x = ~x + 1, putchar ('-');
	if (x > 9) write (x / 10);
	putchar (x % 10 + '0');
}
 
const int N = 4e5 + 7;
 
int n, m, e, E, rt, mxsz, tot, sz[N], tmpH[N], head[N];
ll ans[N];
bool vis[N];
 
struct EDGE {
	int a, b, to, nxt;
} tmpE[N << 1], edge[N << 1];
 
struct Point {
	ll x, y;
	Point(ll X = 0, ll Y = 0) {
		x = X; y = Y;
	}
	friend Point operator + (Point a, Point b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	friend Point operator - (Point a, Point b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	friend bool operator <= (Point a, Point b) {
		return a.y * b.x <= a.x * b.y;
	}
} stk[N*10], A[N], B[N], All[N*10];
 inline bool cmp(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y > b.y);
}
 
struct Hull {
	Point *s; int T;
	inline void clear() {
		T = 0;
	}
	inline void push(Point a) {
		s[++T] = a;
	}
	inline void build() {
		sort(s + 1, s + T + 1, cmp);
		int top = 0;
		for(int i = 1; i <= T; i++) {
			if(i > 1 && s[i].x == s[i - 1].x) continue;
			while(top > 1 && (stk[top] - stk[top - 1]) <= (s[i] - stk[top - 1])) top -- ;
			stk[++top] = s[i];
		}
		for(int i = 1; i <= top; i++) s[i] = stk[i];
		T = top; 
	}
	inline void merge(Hull a, Hull b) {
		int i = 1, j = 1; push(a.s[1] + b.s[1]);
		while(i < a.T || j < b.T) {
			if(j >= b.T || (i < a.T && (b.s[j + 1] - b.s[j]) <= (a.s[i + 1] - a.s[i]))) i++;
			else j++;
			push(a.s[i] + b.s[j]);
		}
	}
	inline void query() {
		int o = 1;
		for(int i = 0; i < m; i++) {
			while(o < T && i * s[o + 1].x + s[o + 1].y >= i * s[o].x + s[o].y) o ++ ;
			ans[i] = i * s[o].x + s[o].y;
		}
	}
} a, b, all;
 
inline void Addedge(int u, int v, int a, int b) {
	tmpE[++e].to = v;
	tmpE[e].nxt = tmpH[u];
	tmpE[e].a = a;
	tmpE[e].b = b;
	tmpH[u] = e;
}
 
inline void addedge(int u, int v, int a, int b) {
	edge[++E].to = v;
	edge[E].nxt = head[u];
	edge[E].a = a;
	edge[E].b = b;
	head[u] = E;
}
 
inline void rebuild(int u, int f) {
	int ff = 0;
	for(int i = tmpH[u]; i; i = tmpE[i].nxt) {
		int v = tmpE[i].to, a = tmpE[i].a, b = tmpE[i].b;
		if(v == f) continue;
		if(!ff) {
			addedge(u, v, a, b);
			addedge(v, u, a, b);
			ff = u;
		} else {
			int tmp = ++tot;
			addedge(ff, tmp, 0, 0); addedge(tmp, ff, 0, 0);
			addedge(tmp, v, a, b); addedge(v, tmp, a, b);
			ff = tmp;
		}
		rebuild(v, u);
	}
}
 
inline void findroot(int u, int fa, int sum) {
	sz[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		if(v == fa || vis[i >> 1]) continue;
		findroot(v, u, sum); sz[u] += sz[v];
		int tmp = min(sz[v], sum - sz[v]);
		if(tmp > mxsz) mxsz = tmp, rt = i;
	}
}
 
inline void getdis(int u, int f, Hull &H, ll A, ll B) {
	if(u <= n) H.push(Point(A, B));
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to, aa = edge[i].a, bb = edge[i].b;
		if(v == f || vis[i >> 1]) continue;
		getdis(v, u, H, A + aa, B + bb);
	}
}
 
inline void divide(int u, int sum) {
	mxsz = -INF; rt = 0; findroot(u, 0, sum);
	if(mxsz == -INF) return;
	vis[rt >> 1] = true; a.clear(); b.clear();
	getdis(edge[rt].to, 0, a, edge[rt].a, edge[rt].b);
	getdis(edge[rt ^ 1].to, 0, b, 0, 0);
	a.push((Point)(0, 0)); b.push((Point)(0, 0));
	a.build(); b.build(); all.merge(a, b);
	int now = rt, size = sum - sz[edge[now].to];
	divide(edge[now].to, sz[edge[now].to]);
	divide(edge[now ^ 1].to, size);
}
 
int main() {
	all.s = All; a.s = A; b.s = B;
	read(n); read(m); tot = n; E = 1;
	for(int i = 1, u, v, a, b; i < n; i++) {
		read(u); read(v); read(a); read(b);
		Addedge(u, v, a, b);
		Addedge(v, u, a, b);
	}
	rebuild(1, 0); divide(1, tot); 
	all.build(); all.query();
	for(int i = 0; i < m; i++) printf("%lld ", ans[i]);
	return 0;
}