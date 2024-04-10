#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;

const int maxn = 309;
int n, m, a, b, c, d, ans, flag, w[maxn][maxn];
struct Matrix {
	int d[maxn][maxn];
	Matrix operator * (const Matrix &a) const {
		Matrix res;
		rep (i, 1, n) rep (j, 1, n) {
			res.d[i][j] = max(d[i][j], a.d[i][j]);
			rep (k, 1, n) 
				res.d[i][j] = max(res.d[i][j], d[i][k] + a.d[k][j]);
		}
		return res;
	}
} A[15], S, T;

int main() {
	scanf("%d%d", &n, &m);
	memset(S.d, 0xc0, sizeof S.d);
	memset(A[0].d, 0xc0, sizeof A[0].d);
	rep (i, 1, n) S.d[i][i] = 0;
	rep (i, 1, m) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		A[0].d[a][b] = c; A[0].d[b][a] = d;
	}
	rep (i, 1, 9) A[i] = A[i-1] * A[i-1];
	per (i, 9, 0) {
		T = S * A[i]; flag = 0;
		rep (j, 1, n) if (T.d[j][j] > 0) flag = 1;
		if (flag) continue;
		S = T; ans += 1 << i;
	}
	if (ans > n) puts("0");
	else printf("%d\n", ans + 1);
	return 0;
}