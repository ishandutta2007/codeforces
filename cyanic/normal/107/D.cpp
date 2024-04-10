#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
using namespace std;
typedef long long LL;

const int maxn = 126, MOD = 12345;
int res[maxn][maxn], tmp[maxn][maxn], POW[maxn][maxn], flag[maxn], check[maxn];
int A[maxn][maxn], B[maxn][maxn], a[maxn<<3], b[maxn<<3];
int m, size = 1, temp, ans, vec[maxn<<3], judge; char ch; LL n;

void mul(int a[maxn][maxn], int b[maxn][maxn], int c[maxn][maxn]) {
	rep (i, 1, size) rep (j, 1, size) {
		tmp[i][j] = 0; 
		rep (k, 1, size) tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
	}
	rep (i, 1, size) rep (j, 1, size) c[i][j] = tmp[i][j];
}

void power(int a[maxn][maxn], LL p, int b[maxn][maxn]) {
	rep (i, 1, size) rep (j, 1, size) 
		POW[i][j] = a[i][j], res[i][j] = (i == j);
	while (p) {
		if (p & 1) mul(res, POW, res);
		mul(POW, POW, POW); p >>= 1;
	}
	rep (i, 1, size) rep (j, 1, size) b[i][j] = res[i][j];
}

int main() {
	scanf("%lld%d", &n, &m);
	rep (i, 1, m) {
		scanf("\n%c %d", &ch, &b[i]);
		a[i] = ch - 'A'; flag[a[i]] = 1;
		size *= b[i];
	}
	rep (i, 0, size - 1) {
		temp = i; 
		per (j, m, 1)
			vec[j] = temp % b[j], temp /= b[j];
		rep (j, 0, 25) if (flag[j]) {
			temp = 0;
			rep (k, 1, m)
				temp = temp * b[k] + (vec[k] + (a[k] == j)) % b[k];
			A[temp+1][i+1]++;
		}
	}
	power(A, n, A); B[1][1] = 1; mul(A, B, B);
	rep (i, 0, size - 1) {
		temp = i;
		per (j, m, 1)
			check[a[j]] |= !(temp % b[j]), temp /= b[j];
		judge = 1;
		rep (j, 0, 25) {
			judge &= !(flag[j] ^ check[j]);
			check[j] = 0;
		}
		if (judge) ans = (ans + B[i+1][1]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}