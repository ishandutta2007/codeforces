#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
using namespace std;
typedef long long LL;
 
const int maxn = 128, MOD = 1000000007;
int f[10][2], w[10], n, A[maxn][maxn], B[maxn][maxn], C[maxn][maxn], tmp[maxn][maxn], res[maxn][maxn], pow[maxn][maxn];
 
void mul(int a[maxn][maxn], int b[maxn][maxn]) {
	memset(tmp, 0, sizeof n * maxn * maxn);
	rep (i, 0, n) rep (j, 0, n) rep (k, 0, n)
		tmp[i][j] = (tmp[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
	memcpy(b, tmp, sizeof n * maxn * maxn);
}
 
void mul2(int a[maxn][maxn], int b[maxn][maxn]) {
	memset(tmp, 0, sizeof n * maxn * maxn);
	rep (i, 0, n) rep (j, 0, n) rep (k, 0, n)
		tmp[i][j] = (tmp[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
	memcpy(a, tmp, sizeof n * maxn * maxn);
}
 
void power(int a[maxn][maxn], int p) {
	memcpy(pow, a, sizeof n * maxn * maxn);
	memset(res, 0, sizeof n * maxn * maxn);
	rep (i, 0, n) res[i][i] = 1;
	/*
	puts("*");
	rep (i, 0, n) {
		rep (j, 0, n)
			printf("%d", pow[i][j]);
		puts("");
	}
	puts("*");
	*/
	while (p) {
		if (p&1) mul2(res, pow);
		mul2(pow, pow); p >>= 1;
	}
	//printf("%d\n", a[1][0]);
	memcpy(a, res, sizeof n * maxn * maxn);
	//printf("!%d\n", res[1][0]);
}
 
int solve(int len, int L, int R) {
	f[0][1] = 1;
	rep (i, 1, len) {
		f[i][0] = (f[i-1][0] + f[i-1][1]) % MOD;
		if ((L>>(i-1)&1) && (R>>(i-1)&1)) f[i][1] = f[i-1][0];
		else f[i][1] = (f[i-1][0] + f[i-1][1]) % MOD;
	}
	return f[len][1];
}
 
int main() { 
	rep (i, 1, 7) scanf("%d", &w[i]);
	A[1][0] = 1;
	rep (i, 1, 7) {
		n = (1<<i)-1;
		memset(B, 0, sizeof B);
		rep (j, 0, n) rep (k, 0, n)
			B[k][j] = solve(i, j, k);
		//printf("%d\n", B[1][0]);
		power(B, w[i]); 
		/*
		rep (i, 0, n) {
			rep (j, 0, n)
				printf("%d", B[i][j]);
			puts("");
		}
		puts("");
		*/
		mul(B, A); //printf("%d\n\n", A[0][0]);
		if (i == 7) break;
		rep (j, 0, n) {
			A[j+(1<<i)][0] = A[j][0];
			A[j][0] = 0;
		}
	}
	printf("%d\n", (A[127][0]+MOD)%MOD);
	//system("pause");
	return 0;
}