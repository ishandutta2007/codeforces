#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
using namespace std;
typedef long long LL;
 
const int maxn = 55;
int r[maxn][maxn], d[maxn][maxn], a[maxn];
LL T; int n = 2, m, K, ans;
 
int main() {
	scanf("%I64d", &T);
	for (; T; T/=6) a[++m] = T % 6;
	r[2][1] = d[1][2] = 1;
	for (int i=m; i>=1; i--) {
		n += 2; 
		r[n-1][n-3] = r[n][n-3] = 1;
		d[n-3][n-1] = d[n-3][n] = 1;
		if (a[i] >= 3) d[n-3][n-1] = 0, a[i] -= 3;
		if (a[i] >= 1) d[n-3][n] = 0;
		if (a[i] >= 2) r[n][n-3] = 0;
		r[n-2][n] = r[n-1][n] = 1;
		d[n][n-2] = d[n][n-1] = 1;
		d[n-4][n+1] = d[n-2][n+2] = 1;
		r[n+1][n-4] = r[n+2][n-2] = 1;
	}
	rep (i, 1, n) rep (j, 1, n-1) ans += r[i][j];
	rep (i, 1, n-1) rep (j, 1, n) ans += d[i][j];
	printf("%d %d %d\n", n, n, ans);
	rep (i, 1, n) rep (j, 1, n-1)
		if (r[i][j]) printf("%d %d %d %d\n", i, j, i, j+1);
	rep (i, 1, n-1) rep (j, 1, n)
		if (d[i][j]) printf("%d %d %d %d\n", i, j, i+1, j);
	return 0;
}