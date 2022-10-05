#include<bits/stdc++.h>
#define rep(i,a,b) for (register int i = a; i <= b; ++i)
#define _rep(i,a,b) for (register int i = a; i >= b; --i)
using namespace std;

const int maxn = 20009;
int a[maxn], b[maxn], f[maxn], g[maxn];
char s[maxn<<2];
int n, m, p, t;

inline int v(int x, int y) {
	return (a[x] + b[y]) % p;
}

int solve(int U, int D, int L, int R) {
	if (U > D) return 0;
	if (U == D) {
		int ans = 0;
		rep (i, L, R - 1) s[t++] = 'S', ans += v(U, i);
		return ans + v(U, R);
	}
	int mid = (U + D) >> 1, cur = 0, ans = -1;
	rep (i, L - 1, R + 1) f[i] = g[i] = 0;
	rep (i, U, mid) rep (j, L, R) 
		f[j] = max(f[j], f[j - 1]) + v(i, j);
	_rep (i, D, mid + 1) _rep (j, R, L)
		g[j] = max(g[j], g[j + 1]) + v(i, j);
	rep (i, L, R) if (f[i] + g[i] > ans)
		ans = f[i] + g[i], cur = i;
	solve(U, mid, L, cur); s[t++] = 'C';
	solve(mid+1, D, cur, R);
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &p);
	rep (i, 1, n) scanf("%d", &a[i]);
	rep (i, 1, m) scanf("%d", &b[i]);
	printf("%d\n", solve(1, n, 1, m)); 
	puts(s);
	return 0;
}