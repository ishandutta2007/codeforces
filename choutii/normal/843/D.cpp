#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

namespace io{
	const int L = (1 << 18) + 1;
	
	char buf[L], *S , *T, c;
	 
	char getchar() {
		if(S == T) {
			T = (S = buf) + fread(buf, 1, L, stdin);
			return (S == T ? EOF : *S++);
		}
		return *S++;
	}
	
	int read() {
		int x = 0, f = 1; char ch;
		for(ch = getchar(); !isdigit(ch); ch = getchar())
			if(ch == '-') f = -1;
		for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return x * f;
	}
};

using io :: read;

const int MaxN = 101234;
const LL infL = 1ll << 60;

int n, m, Q;
struct edge {
	int to, nxt, v;
}e[MaxN << 1]; int cnt, lst[MaxN];

void ins(int a, int b, int c) {
	e[++cnt] = (edge) {b, lst[a], c}; lst[a] = cnt;
}

LL dis[MaxN]; int vis[MaxN];
priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > q;

void dijkstra(int s) {
	for(int i = 1; i <= n; i++) dis[i] = infL;
	q.push(make_pair(0, s)); dis[s] = 0;
	while(!q.empty()) {
		int c = q.top().sec; q.pop(); if(vis[c]) continue; vis[c] = 1;
		for(int i = lst[c], b; b = e[i].to, i; i = e[i].nxt) 
			if(cmin(dis[b], dis[c] + e[i].v))
				q.push(make_pair(dis[b], b));
	}
}

LL ans[MaxN]; vector<int> g[MaxN];

void rebuild(int s) {
	int i, j, k, b, x; LL up = 0;
	for(i = 1; i <= n; i++) ans[i] = infL;
	ans[s] = 0; g[0].push_back(s);
	for(i = 0; i <= up; i++) 
		for(j = 0; j < g[i].size(); j++) {
			if(i > ans[x = g[i][j]]) continue;
			for(k = lst[x]; b = e[k].to, k; k = e[k].nxt) 
				if(cmin(ans[b], ans[x] + dis[x] + e[k].v - dis[b])) 
					if(ans[b] <= n) g[ans[b]].push_back(b), cmax(up, ans[b]);
		}
	for(i = 0; i <= up; i++) g[i].clear();
	for(i = 1; i <= n; i++) if(dis[i] < infL) dis[i] += ans[i];
}

int main() {
	int i, x;
	n = read(); m = read(); Q = read();
	for(i = 1; i <= m; i++) {
		int a = read(), b = read();
		ins(a, b, read());
	}
	
	dijkstra(1);
	
	for(i = 1; i <= Q; i++)
		if(read() == 1) 
			printf("%lld\n", dis[x = read()] >= infL ? -1 : dis[x]);
		else {
			for(x = read(); x; x--) e[read()].v++;
			rebuild(1);
		}
	return 0;
}