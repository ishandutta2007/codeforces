#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N(1555), M(111111);
int fac[M], inv[M], invFac[M];
int modulo(1e9 + 7);
int dpl[N][N], dpr[N][N], c[N], sc[N];
int pw(int x, int n) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = (long long)res * x % modulo;
		}
		n /= 2;
		x = (long long)x * x % modulo;
	}
	return res;
}
int main() {

	int n, m, a, b, k;
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
	fac[0] = 1;
	inv[0] = 1;
	invFac[0] = 1;
	//printf("%d\n", pw(b, modulo - 2));
	int p((long long)a * pw(b, modulo - 2) % modulo);
	for(int i(1); i <= k; i++) {
		fac[i] = (long long)fac[i - 1] * i % modulo;
		inv[i] = i == 1 ? 1 : (long long)(modulo / i + 1) * inv[i - modulo % i] % modulo;
		invFac[i] = (long long)invFac[i - 1] * inv[i] % modulo;
		//printf("fac[%d] = %d, inv[%d] = %d, invFac[%d] = %d\n", i, fac[i], i, inv[i], i, invFac[i]);
	}
	//printf("p = %d\n", p);
	for(int i(0); i < m; i++) {
		dpl[0][i] = i == 0;
		dpr[0][i] = i == 0;
		c[i] = (k >= i ? (long long)fac[k] * invFac[k - i] % modulo * invFac[i] % modulo : 0) * pw(p, i) % modulo * pw((1 - p + modulo) % modulo, k - i) % modulo;
		sc[i] = i ? (sc[i - 1] + c[i]) % modulo : c[i];
	//printf("c[%d] = %d\n", i, c[i]);
	//printf("%d\n", k >= i);
	}
	for(int i(1); i <= n; i++) {
		int tot(0);
		for(int j(m - 1); j >= 0; j--) {
			tot = (tot + (long long)c[m - j - 1] * (modulo - dpr[i - 1][j + 1])) % modulo;
			dpl[i][j] = ((long long)c[j] * ((long long)sc[m - j - 1] * (dpl[i - 1][0] + modulo - dpl[i - 1][m - j]) % modulo + tot)) % modulo;
		}
		for(int j(m - 1); j >= 0; j--) {
			dpl[i][j] = (dpl[i][j + 1] + dpl[i][j]) % modulo;
		}
		
		tot = 0;
		for(int j(m - 1); j >= 0; j--) {
			tot = (tot + (long long)c[m - j - 1] * (modulo - dpl[i - 1][j + 1])) % modulo;
			dpr[i][j] = ((long long)c[j] * ((long long)sc[m - j - 1] * (dpr[i - 1][0] + modulo - dpr[i - 1][m - j]) % modulo + tot)) % modulo;
		}
		for(int j(m - 1); j >= 0; j--) {
			dpr[i][j] = (dpr[i][j + 1] + dpr[i][j]) % modulo;
		}
				
	}
	printf("%d\n", dpl[n][0]);
}