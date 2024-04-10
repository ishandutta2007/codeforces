#include <bits/stdc++.h>

#define to first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 301234;

int n, m, s, c, vis[MaxN], ans[MaxN], U[MaxN], V[MaxN], tp[MaxN];

vector<pair<int, int> > e[MaxN];

void dfs1(int x) {
	if(vis[x]) return;
	++c; vis[x] = 1;
	for(auto y : e[x]) {
		int o = y.sec;
		if(tp[o] == 1) 
			dfs1(y.to);
		else {
			if(!ans[o]) {
				(V[o] == y.to) ? ans[o] = 1 : ans[o] = 2;
				dfs1(y.to); 
			}
		}
	}
}

void dfs2(int x) {
	if(vis[x]) return;
	++c; vis[x] = 1;
	for(auto y : e[x]) {
		int o = y.sec;
		if(tp[o] == 1) 
			dfs2(y.to);
		else
			if(!ans[o]) 
				V[o] == y.to ? ans[o] = 2 : ans[o] = 1;
	}
}

int main() {
	int i;
	n = read(); m = read(); s = read();
	for(i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		U[i] = v, V[i] = w, tp[i] = u;
		e[U[i]].push_back(make_pair(V[i], i));
		if(tp[i] == 2)
			e[V[i]].push_back(make_pair(U[i], i));
	}
	
	dfs1(s);
	printf("%d\n", c);
	for(i = 1; i <= m; i++) 
		if(tp[i] == 2)
			if(ans[i] == 1) 
				putchar('+'); 
			else 
				putchar('-');
	puts("");
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans)); c = 0;
	
	dfs2(s);
	printf("%d\n", c);
	for(i = 1; i <= m; i++) 
		if(tp[i] == 2)
			if(ans[i] == 1) 
				putchar('+'); 
			else 
				putchar('-');
	
	return 0;
}