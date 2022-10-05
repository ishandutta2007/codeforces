#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 100009;
struct edge {
	int u, v, pos; double w;
	bool operator < (const edge &e) const {
		return w < e.w;
	}
} e[maxn], E[maxn];
int pa[maxn], ans[maxn], n, m, size, Size, K, a, b, c;
double l, r, mid;

inline int getpa(int x) {
	return pa[x] == x ? x : pa[x] = getpa(pa[x]);
}

int solve(double x) {
	rep (i, 1, Size) E[i].w += x;
	int res = 0, cnt = 0, cur = 1, Cur = 1, a, b;
	rep (i, 1, n) pa[i] = i;
	while (cur <= size || Cur <= Size) {
		if (cur <= size && (Cur > Size || e[cur].w < E[Cur].w)) {
			a = getpa(e[cur].u); b = getpa(e[cur].v);
			if (a == b) { cur++; continue; }
			pa[a] = b; ans[++cnt] = e[cur++].pos;
		}
		else {
			a = getpa(E[Cur].u); b = getpa(E[Cur].v);
			if (a == b) { Cur++; continue; } res++;
			pa[a] = b; ans[++cnt] = E[Cur++].pos; 
		}
	}
	rep (i, 1, Size) E[i].w -= x;
	if (res != K) return res;
	printf("%d\n", cnt);
	rep (i, 1, cnt) printf("%d ", ans[i]);
	exit(0);
}

int main() {
	scanf("%d%d%d", &n, &m, &K);
	rep (i, 1, m) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1 || b == 1) {
			E[++Size].u = a; E[Size].v = b; 
			E[Size].w = c + 0.0000001 * (500 - rand() % 1000);
			E[Size].pos = i;
		}
		else {
			e[++size].u = a; e[size].v = b;
			e[size].w = c; e[size].pos = i;
		}
	}
	sort(e+1, e+size+1); sort(E+1, E+Size+1);
	l = -1e5; r = 1e5;
	while (r - l >= 1e-6) {
		mid = (l + r) * 0.5;
		if (solve(mid) > K) l = mid;
		else r = mid;
	}
	puts("-1");
	return 0;
}