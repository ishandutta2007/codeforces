#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 55;
LL a[maxn], s[maxn][maxn], ans;
int f[maxn][maxn];
int n, K;

int check(LL need) {
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	rep (i, 0, n-1) rep (j, 0, K-1) if (f[i][j])
		rep (k, i+1, n) if ((s[i+1][k] & need) == need) f[k][j+1] = 1;
	return f[n][K];
}

int main() {
	scanf("%d%d", &n, &K);
	rep (i, 1, n) scanf("%I64d", &a[i]);
	rep (l, 1, n) rep (r, l, n)
		rep (i, l, r) s[l][r] += a[i];
	per (i, 60, 0)
		if (check(ans + (1LL << i))) ans += 1LL << i;
	printf("%I64d\n", ans);	
	return 0;
}