#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define mp make_pair
#define MAXN 10 
#define MAXM 10 
#define inf 1e+10
#define eps 1e-10
using namespace std;
inline int sgn(const double& x){return (x>+eps)-(x<-eps);}
int n = 9, m = 8;
double A[9][10],X[10];
double norm[9][10] = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, 0},
							{2, 1, 1, -1, -1, 1, 0, 1, 0, 0},
							{-1, 1, 0, 2, 1, -2, -1, -1, 1, 0},
							{0, -1, 1, -1, 1, 1, 2, -1, -2, 0},
							{0, 0, -1, 0, -1, 0, -1, 1, 1, 0}};
int basis[MAXM+1],out[MAXN+1];

void pivot(int a, int b) {
	int i, j;
	for (i = 0; i <= m; i++) if (i != a && sgn(A[i][b])) for (j = 0; j <= n; j++) if (j != b) A[i][j] -= A[a][j]*A[i][b] / A[a][b];
	for (j = 0; j <= n; j++) if (j != b) A[a][j] /= A[a][b];
	for (i = 0; i <= m; i++) if (i != a) A[i][b] /= -A[a][b];
	A[a][b] = 1 / A[a][b];
	swap(basis[a], out[b]);
}

double simplex() {
	int i, j, ii, jj;
	for (j = 0; j < n; j++) A[0][j] = -A[0][j];
	for (i = 0; i <= m; i++) basis[i] = -i;
	for (j = 0; j <= n; j++) out[j] = j;
	while(true) {
		ii = 1, jj = 0;
		for (i = 1; i <= m; i++) if (mp(A[i][n], basis[i]) < mp(A[ii][n], basis[ii])) ii = i;
		if (A[ii][n] > -eps) break;
		for (j = 0; j < n; j++) if (A[ii][j] < A[ii][jj]) jj = j;
		if (A[ii][jj] > -eps) return -inf;
		pivot(ii, jj);
	}
	while(true)	{
		ii = 1, jj = 0;
		for (j = 0; j < n; j++) if (mp(A[0][j], out[j]) < mp(A[0][jj], out[jj])) jj = j;
		if (A[0][jj] > -eps) break;
		for (i = 1; i <= m; i++)
			if (A[i][jj] > 0 && (A[ii][jj] < eps || mp(A[i][n] / A[i][jj], basis[i]) < mp(A[ii][n] / A[ii][jj], basis[ii]))) ii=i;
		if (A[ii][jj] < eps) return +inf;
		pivot(ii, jj);
	}
	for (j = 0; j < n; j++) X[j] = 0;
	for (i = 1; i <= m; i++) if (basis[i] >= 0) X[basis[i]] = A[i][n];
	return A[0][n];
}

int a[5], N;
main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int i, j, k, tot = 0, x, y;
	double ans = inf;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &k);
		a[k]++;
		tot += k;
	}
	for (i = 5; i < 9; i++) for (j = 0; j <= n; j++) norm[i][j] = -norm[i - 4][j];
	for (x = 0; x <= tot; x += 3) {
		if ((tot - x) % 4) continue;
		y = (tot - x) / 4;
		for (i = 0; i <= m; i++) for (j = 0; j <= n; j++) A[i][j] = norm[i][j];
		A[1][n] = a[1];
		A[5][n] = -a[1];
		A[2][n] = a[2];
		A[6][n] = -a[2];
		A[3][n] = a[3] - x / 3;
		A[7][n] = x / 3 - a[3];
		A[4][n] = a[4] - y;
		A[8][n] = y - a[4];
		ans = min(-simplex(), ans);
	}
	if (ans == inf) printf("-1");
	else printf("%d\n", int(ans + eps));
}