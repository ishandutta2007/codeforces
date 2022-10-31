#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;
#define mp make_pair
#define MAXN 510
#define MAXM 511
#define inf 1e+8
#define eps 1e-8
inline int sgn(const double& x){return (x>+eps)-(x<-eps);}
int n, m;
int N, x, D[MAXN][MAXN], adj[MAXN][MAXN], size[MAXN];
double A[MAXM+1][MAXN+1], X[MAXN];
int basis[MAXM+1], out[MAXN+1];

void pivot(int a, int b) {
	int i, j;
	for (i = 0; i <= m; i++) if (i != a && sgn(A[i][b])) for (j = 0; j <= n; j++) if (j != b) A[i][j] -= A[a][j] * A[i][b] / A[a][b];
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
		if (A[ii][n] >= 0) break;
		for (j = 0; j < n; j++) if (A[ii][j] < A[ii][jj]) jj = j;
		if (A[ii][jj] >= 0) return -inf;
		pivot(ii, jj);
	}
	while(true)	{
		ii = 1, jj = 0;
		for (j = 0; j < n; j++) if (mp(A[0][j], out[j]) < mp(A[0][jj], out[jj])) jj = j;
		if (A[0][jj] >= 0) break;
		for (i = 1; i <= m; i++)
			if (A[i][jj] > 0 && (A[ii][jj] <= 0 || mp(A[i][n] / A[i][jj], basis[i]) < mp(A[ii][n] / A[ii][jj], basis[ii]))) ii=i;
		if (A[ii][jj] <= 0) return +inf;
		pivot(ii, jj);
	}
	for (j = 0; j < n; j++) X[j] = 0;
	for (i = 1; i <= m; i++) if (basis[i] >= 0) X[basis[i]] = A[i][n];
	return A[0][n];
}

void init(int k, int u, int par, int d) {
	if (d >= 0) {
		A[k][u]--;
		int i, v;
		for (i = 0; i < size[u]; i++) {
			v = adj[u][i];
			if (v != par) init(k, v, u, d - D[u][i]);
		}
	}
}
main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int i, j, k, u, v, tot = 0;
	double ans;
	scanf("%d%d", &N, &x);
	for (i = 0; i < N; i++) {
		scanf("%d", &k);
		tot += k;
		A[0][i] = k - 1;
	}
	A[0][N] = 0;
	for (i = 0; i < N - 1; i++) {
		scanf("%d%d%d", &u, &v, &k);
		u--, v--;
		adj[u][size[u]] = v;
		adj[v][size[v]] = u;
		D[u][size[u]++] = D[v][size[v]++] = k;
	}
	for (i = 0; i < N; i++) {
		init(i + 1, i, -1, x);
		A[i + 1][N] = -1;
		A[N + 1][i] = 1;
	}
	A[N + 1][N] = tot;
	m = N + 1, n = N;
	ans = simplex();
	if (ans == -inf) printf("-1\n");
	else printf("%d\n", int(-ans + eps));
}