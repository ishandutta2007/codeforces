#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;

_ n, m, x, y, z, a[maxn][maxn], sn, sm;

void no();
int main() {
	
	scanf("%lld%lld%lld%lld%lld", &n, &m, &x, &y, &z);
	if((n&1) && (m&1)) no();
	if(n&1) {
		if(x < m>>1) no();
		x -= m>>1;
		for(_ i = 1, j = 1; i <= m; i += 2, j ^= 1) a[n][i] = a[n][i+1] = 25-j;
		--n;
		sn = 1;
	}
	if(m&1) {
		if(y < n>>1) no();
		y -= n>>1;
		for(_ i = 1, j = 1; i <= n; i += 2, j ^= 1) a[i][m] = a[i+1][m] = 25-j;
		--m;
		sm = 1;
	}
	if((z<<2)+(((x|1)^1)<<1)+(((y|1)^1)<<1) < n*m) no();
	x >>= 1;
	y >>= 1;
	for(_ i = 1, k = 0; i <= n; i += 2, k ^= 4) for(_ j = 1, l = 0; j <= m; j += 2, l ^= 2) if(z) {
		a[i][j] = a[i+1][j] = a[i][j+1] = a[i+1][j+1] = l|k;
		--z;
	} ef(y) {
		a[i][j] = a[i+1][j] = l|k;
		a[i][j+1] = a[i+1][j+1] = l|k|1;
		--y;
	} ef(x) {
		a[i][j] = a[i][j+1] = l|k;
		a[i+1][j] = a[i+1][j+1] = l|k|1;
		--x;
	}
	for(_ i = 1; i <= n+sn; ++i, putchar(10)) for(_ j = 1; j <= m+sm; ++j) putchar('a'+a[i][j]);
	
	return 0;
}

void no() {
	puts("IMPOSSIBLE");
	exit(0);
	return;
}