#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;

const int maxn = 3009, maxm = 309;
double p[maxn][maxm], f[maxm][maxn], c[maxn], g[maxm], mx, ans;
int n, m, cur;

void calc(int x) {
	rep (i, 1, n) c[i] = f[x][i-1] * p[i][x] + c[i-1] * (1 - p[i][x]);
	rep (i, 0, n) f[x][i] = c[i]; g[x] -= c[n];
}

int main() {
	scanf("%d%d", &n, &m);
	rep (i, 1, n) rep (j, 1, m)
		scanf("%lf", &p[i][j]), p[i][j] /= 1000;
	rep (i, 1, m) { 
		f[i][0] = 1;
		rep (j, 1, n) f[i][j] = f[i][j-1] * (1 - p[j][i]);
		g[i] = 1 - f[i][n];
	}
	rep (i, 1, n) {
		mx = -1e9;
		rep (j, 1, m)
			if (g[j] > mx) mx = g[j], cur = j;
		ans += mx; calc(cur);
	}
	printf("%.12lf\n", ans);
	return 0;
}