#include <bits/stdc++.h>

#define fir first
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

const int MaxN = 1001234;
int n, m;

vector<int> e[MaxN];

void insert(int u, int v) {
	e[u].push_back(v);
}

int dfn[MaxN], low[MaxN], ins[MaxN]; stack<int> s;
int scc, bel[MaxN], clk;

void tarjan(int x) {
	dfn[x] = low[x] = ++clk; ins[x] = 1; s.push(x);
	for(auto y : e[x]) {
		if(!dfn[y]) {
			tarjan(y);
			cmin(low[x], low[y]);
		} else 
			if(ins[y]) 
				cmin(low[x], dfn[y]);
	}
	if(low[x] == dfn[x]) {
		scc++;
		int z;
		do {
			z = s.top(); s.pop();
			bel[z] = scc; ins[z] = 0;
		} while(z != x);
	}
}

int x, y, a[MaxN], b[MaxN];

vector<int> ans;
bool twosat() {
	scc = clk = 0;
	int i;
	for(i = 1; i <= m + m; i++) dfn[i] = low[i] = ins[i] = 0;
	for(i = 1; i <= m + m; i++) 
		if(!dfn[i]) 
			tarjan(i);
	for(i = 1; i <= m; i++) {
		if(bel[i] == bel[i + m]) 
			return false;
	}	
	
	for(i = 1; i <= m; i++) {
		if(bel[i] >= bel[i + m]) 
			ans.push_back(i);
	}
	return 1;
}

int main() {
	int i, j;
	n = read(); m = read(); 
	x = read();
	for(i = 1; i <= x; i++) a[i] = read();
	for(j = 2; j <= n; j++) {
		y = read();
		for(i = 1; i <= y; i++) b[i] = read();
		int lcp = 0;
		for(i = 1; i <= max(x, y); i++)
			if(a[i] != b[i]) {
				lcp = i; break;
			}
		if(lcp) {
			if(lcp > x) {
				for(i = 1; i <= x; i++) a[i] = 0;
				x = y;
				for(i = 1; i <= y; i++) a[i] = b[i], b[i] = 0; continue;
			}
			if(lcp > y) {
				return puts("No"), 0;
			}
			if(a[lcp] < b[lcp]) insert(a[lcp], b[lcp]), insert(b[lcp] + m, a[lcp] + m);
			if(a[lcp] > b[lcp]) insert(a[lcp], a[lcp] + m), insert(b[lcp] + m, b[lcp]);
			for(i = 1; i <= x; i++) a[i] = 0;
 			x = y;
			for(i = 1; i <= y; i++) a[i] = b[i], b[i] = 0;
		}
 	}
 	
 	if(twosat()) {
		puts("Yes"); 
		printf("%d\n", ans.size());
		for(auto i : ans) printf("%d ", i);
	}else puts("No");
	return 0;
}