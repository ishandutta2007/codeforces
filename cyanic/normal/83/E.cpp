#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define upd(a,b) a = min(a, b)
using namespace std; char s[30];
int n, m, k, ans, t, a[1<<20], f[22][1<<20];
int main() {
	scanf("%d", &n);
	rep (i, 0, n) {
		scanf("%s", s); m = strlen(s);
		rep (j, 0, m) a[i] = a[i] * 2 + s[j] - '0';
	}
	memset(f, 0x3f, sizeof f); f[0][0] = 0; ans = m;
	rep (i, 1, n) {
		for (k = m; k; k--) if ((a[i-1] & ((1 << k) - 1)) == (a[i] >> (m - k))) break;
		t = 1 << 30; ans += m - k;
		rep (j, 0, m + 1) upd(t, f[m - j][a[i] >> j] + j);
		rep (j, 0, m + 1) upd(f[j][a[i-1] & ((1 << j) - 1)], t - m + k);
	}
	t = 1 << 30;
	rep (i, 0, m + 1) rep (j, 0, (1 << i)) upd(t, f[i][j]);
	printf("%d\n", ans + t);
	return 0;
}