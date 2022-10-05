#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define all(v) (v).begin(), (v).end()
using namespace std;
const int N = 35, B = 1000000, revB = 616898040, MOD = 998244353;
int n, m, res, p[N*N], sum[N*N], sz[N*N], f[N*N][N], inv[N], a[N];
inline int get(int x) { return find(p, p+(n*m+1), x) - p; }
inline void update(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
int main() {
	inv[1] = 1; rep (i, 2, N-1) inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
	vector<int> frac; frac.push_back(0); scanf("%d", &n);
	rep (i, 0, n-1) {
		double x; scanf("%lf", &x);
		a[i] = int(x * B + 0.2); frac.push_back(a[i] % B);
	}
	sort(all(frac)); frac.erase(unique(all(frac)), frac.end()); m = frac.size();
	per (i, n*m, 0) {
		p[i] = (i/m) * B + frac[i%m];
		if (i < n*m) sz[i] = 1LL * (p[i+1] - p[i]) * revB % MOD;
	}
	per (i, min(get(a[0]), m)-1, 0) sum[i] = sz[i], f[i][1] = 1;
	rep (i, 1, n-1) {
		int cut = get(a[i]);
		per (j, n*m-1, 0) if (j < cut) {
			rep (k, max(0, j-m), j-1) update(f[j][0], sum[k]);
			if (j >= m) rep (k, 0, n) update(f[j][k], MOD - f[j-m][k]);
			per (k, n-1, 0) f[j][k+1] = 1LL * f[j][k] * inv[k+1] % MOD;
			f[j][0] = sum[j] = 0;
			per (k, n, 0) sum[j] = (1LL * sum[j] * sz[j] + f[j][k]) % MOD;
		}
		else { sum[j] = 0; memset(f[j], 0, sizeof f[j]); }
	}
	rep (i, 0, n*m-1) update(res, sum[i]);
	printf("%d\n", res);
	return 0;
}