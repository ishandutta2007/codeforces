#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 2011;
const int LOG = 20;
const int mod = 998244353;
const int inf = 1e9 + 7;
int c[N][N], Q[N], ans[N], pw[N * N], pq[N * N], K[N][N];
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int p = (LL)a * fastpo(b, mod - 2, mod) % mod;
	int q = (1 - p + mod) % mod;
	pw[0] = 1;
	pq[0] = 1;
	for(int i(1); i <= n * n; i++)
		pw[i] = pw[i - 1] * (LL)p % mod, pq[i] = pq[i - 1] * (LL)q % mod;
	for(int i(0); i <= n; i++)
		for(int j(0); j <= i; j++)
			c[i][j] = (i == 0 || j == 0 ? 1 : (c[i - 1][j - 1] + c[i - 1][j]) % mod);
	Q[1] = 1;
	K[0][0] = 1;
	for(int sum(0); sum <= n; sum++) {
		for(int i(0); i <= sum; i++) {
			int j = sum - i;
			K[i + 1][j] = (K[i + 1][j] + K[i][j] * (LL)pq[j]) % mod;
			K[i][j + 1] = (K[i][j + 1] + K[i][j] * (LL)pw[i]) % mod;
		}
	}
	for(int i(2); i <= n; i++) {
		Q[i] = 1;
		for(int j(1); j < i; j++) {
			Q[i] = (Q[i] - (LL)Q[j] % mod * K[j][i - j] % mod + mod) % mod;
		}
		//cout << i << ' ' << Q[i] << endl;
	}
	ans[1] = 0;
	for(int i(1); i <= n; i++) {
		ans[i] = c[i][2];
		for(int j(1); j <= i; j++) {
			ans[i] = (ans[i] + (LL)K[j][i - j] % mod * Q[j] % mod * ((j == i ? 0 : ans[j]) + ans[i - j] - c[i - j][2] + (LL)mod) % mod) % mod;
		}
		int coe = 1;
		coe = (coe - Q[i] + mod) % mod;
		ans[i] = ans[i] * (LL)fastpo(coe, mod - 2, mod) % mod;
	}
	printf("%d\n", ans[n]);
}