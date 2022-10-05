#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;
typedef long long LL;

const int maxn = 500005;
int a[maxn], b[maxn], c[maxn][22], f[maxn][22];
int n, t, u; LL ans;

int ask(int x, int y) {
	if (x <= 0) return 0; int k = log2(y-x+1);
	return b[c[x][k]] < b[c[y-(1<<k)+1][k]] ? c[x][k] : c[y-(1<<k)+1][k];
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &a[i]), a[i+n] = a[i];
	rep (i, 1, 2*n) b[i] = i - a[i], c[i][0] = i; t = 1;
	rep (j, 1, 20) { rep (i, 1, 2*n) if (i+t-1 <= 2*n)
		c[i][j] = b[c[i][j-1]] < b[c[i+t][j-1]] ? c[i][j-1] : c[i+t][j-1]; t += t; }
	rep (i, 1, 2*n) f[i][0] = ask(b[i], i);
	rep (j, 1, 20) rep (i, 1, 2*n) f[i][j] = f[f[i][j-1]][j-1];
	for (int i=2*n; i>=n+1; i--) { u = i;
		if (b[i] <= i-n+1) { ans++; continue;}
		for (int j=20; j>=0; j--)
			if (b[f[u][j]] > i-n+1) u = f[u][j], ans += 1<<j;
		ans += 2;
	}
	printf("%I64d\n", ans);
	return 0;
}