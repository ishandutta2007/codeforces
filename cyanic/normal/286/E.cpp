#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;
 
const int maxn = 1 << 21;
const int MOD = 998244353, base = 3;
int flag[maxn], a[maxn], g[maxn], R[maxn];
int K, m, x, n, L, rev, tmp;
vector<int> ans;
 
inline int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p&1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}
 
void NTT(int a[maxn], int n) {
	rep (i, 0, n-1) if (i < R[i]) swap(a[i], a[R[i]]);
	for (int d = 1, t = n >> 1; d < n; d <<= 1, t >>= 1)
		for (int i = 0; i < n; i += (d << 1))
			for (int j = 0; j < d; j++) {
				tmp = 1LL * g[t*j] * a[i+j+d] % MOD;
				a[i+j+d] = (a[i+j] - tmp + MOD) % MOD;
				a[i+j] = (a[i+j] + tmp) % MOD;
			}
}
 
int main() {
	scanf("%d%d", &K, &m); m++;
	rep (i, 1, K) scanf("%d", &x), flag[x] = a[x] = 1;
	for (n = 1; n <= 2 * m; n <<= 1, L++);
	rep (i, 0, n-1) R[i] = (R[i>>1]>>1) | ((i&1)<<(L-1));
	g[0] = 1; g[1] = power(base, (MOD - 1) / n);
	rep (i, 2, n-1) g[i] = 1LL * g[i-1] * g[1] % MOD;
	NTT(a, n); 
	rep (i, 0, n-1) a[i] = 1LL * a[i] * a[i] % MOD;
	g[1] = power(g[1], MOD - 2);
	rep (i, 2, n-1) g[i] = 1LL * g[i-1] * g[1] % MOD;
	NTT(a, n); rev = power(n, MOD-2);
	rep (i, 0, n-1) a[i] = 1LL * a[i] * rev % MOD;
	rep (i, 0, m-1) 
		if (a[i] && !flag[i]) return puts("NO"), 0;
		else if (!a[i] && flag[i]) ans.push_back(i);
	puts("YES");
	printf("%d\n", ans.size());
	rep (i, 0, ans.size()-1) printf("%d ", ans[i]);
	return 0;
}