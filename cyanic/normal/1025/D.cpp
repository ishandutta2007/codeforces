#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 705;
bitset<maxn> fL[maxn], fR[maxn];
bitset<maxn> gL[maxn], gR[maxn], tmp, tmp2;
int a[maxn], n;

inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &a[i]);
	rep (i, 0, n) rep (j, i, n + 1)
		if (i == 0 || j == n + 1 || gcd(a[i], a[j]) >= 2) {
			gL[i][j] = 1;
			gR[j][i] = 1;
		}
	rep (i, 1, n)
		fL[i][i] = fR[i][i] = 1;
	int r;
	rep (len, 1, n) rep (l, 1, n - len + 1) {
		r = l + len - 1;
		tmp = fL[l] & fR[r];
		if (!tmp.count()) continue;
		// printf("%d %d   %d\n", l, r, tmp.count());
		tmp2 = tmp & gR[r+1];
		if (tmp2.count()) {
			fL[l][r+1] = 1;
			// printf("L  %d %d\n", l, r);
		}
		tmp2 = tmp & gL[l-1];
		if (tmp2.count()) {
			// printf("R  %d %d\n", l, r);
			fR[r][l-1] = 1;
		}
	}
	if (fL[1][n+1] || fR[n][0]) puts("Yes");
	else puts("No");
	return 0;
}