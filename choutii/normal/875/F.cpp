#include<bits/stdc++.h>

using namespace std;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 401234;

int n, m, f[MaxN], c[MaxN];

struct edge {
	int a, b, w;
}e[MaxN];


int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool cmp(edge x, edge y) {
	return x.w > y.w;
}

int main() {
	int i;
	n = read(); m = read();
	for(i = 1; i <= m; i++) {
		e[i].a = read(); e[i].b = read(); e[i].w = read();
	}	
	
	sort(e + 1, e + m + 1, cmp);
	for(i = 1; i <= n; i++) f[i] = i;
	long long ans = 0;
	for(i = 1; i <= m; i++) {
		int a = e[i].a, b = e[i].b;
		int u = find(a), v = find(b);
		if(u == v) {
			if(!c[u]) {
				c[u]++; ans += e[i].w;
			}
		} else {
			if(c[u] + c[v] <= 1) {
				f[v] = u; c[u] += c[v];
				ans += e[i].w;
			}
		}
	}
	cout << ans;
	return 0;
}