#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
using namespace std;
 
inline int read() {
	char ch = getchar(); int x = 0, op = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x*10 + ch-'0'; ch = getchar(); }
	return op * x;
}
 
const int maxn = 200009;
struct edge {
	int u, v, val;
	bool operator < (const edge &e) const {
		return val > e.val;
	}
} e[maxn];
int n, m, x, y, pa[maxn], f[maxn];
long long ans;
 
int getpa(int x) {
	return pa[x] == x ? x : pa[x] = getpa(pa[x]);
}
 
int main() {
	n = read(); m = read();
	rep (i, 1, m) {
		e[i].u = read(); e[i].v = read();
		e[i].val = read();
	}
	sort(e+1, e+m+1);
	rep (i, 1, n) { pa[i] = i; f[i] = 0; }
	rep (i, 1, m) {
		x = getpa(e[i].u); y = getpa(e[i].v);
		if (x != y) {
			if (f[x] && f[y]) continue;
			f[x] |= f[y];
			pa[y] = x;
			ans += e[i].val;
		}
		else if (!f[x]) {
			f[x] = 1;
			ans += e[i].val;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}