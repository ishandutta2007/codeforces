#include<cstdio>
#include<vector>
#include<cmath>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define pb push_back
using namespace std;
typedef long double LD;

const int maxn = 505;
int cur[maxn][maxn], n, m, size, u, v, x, y;
LD A[maxn][maxn], p[maxn];
vector<int> e[maxn];

void Gauss(int n, int m) {
	LD tmp; int k;
	rep (i, 1, n) {
		tmp = 0; k = i;
		rep (j, i, n) if (fabs(A[i][j]) > tmp) tmp = fabs(A[i][j]), k = j;
		if (k != i) rep (j, i, m) swap(A[k][j], A[i][j]);
		rep (j, i + 1, n) {
			tmp = A[j][i] / A[i][i];
			rep (k, i, m) A[j][k] -= A[i][k] * tmp;
		}
	}
	per (i, n, 1) rep(j, 1, i - 1) {
		tmp = A[j][i] / A[i][i];
		rep (k, i, m) A[j][k] -= A[i][k] * tmp;
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &x, &y);
	rep (i, 1, m) scanf("%d%d", &u, &v), e[u].pb(v), e[v].pb(u);
	rep (i, 1, n) scanf("%Lf", &p[i]);
	rep (i, 1, n) rep (j, 1, n) 
		cur[i][j] = (j < i ? cur[j][i] : ++size);
	rep (i, 1, n) rep (j, 1, n) {
		A[cur[i][j]][cur[i][j]] += 1;
		if (i == j) continue;
		rep (a, -1, e[i].size()-1)
			rep (b, -1, e[j].size()-1)
				A[cur[i][j]][cur[a == -1 ? i : e[i][a]][b == -1 ? j : e[j][b]]] -= 
					(a == -1 ? p[i] : (1 - p[i]) / e[i].size()) *
					(b == -1 ? p[j] : (1 - p[j]) / e[j].size());
	}
	rep (i, 1, n) A[cur[i][i]][size+i] = 1;
	Gauss(size, size + n);
	rep (i, 1, n) printf("%.8Lf ", A[cur[x][y]][size+i] / A[cur[x][y]][cur[x][y]]);
	return 0;
}