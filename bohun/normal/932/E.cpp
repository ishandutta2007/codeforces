#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;
		
const int nax = 5005;		
const int mod = 1e9 + 7;	

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}
		
int n, k;
int dp[nax][nax];
int fac[nax];
int rev[nax];

int newton(int N, int K) {
	if(N < K) return 0;
	int res = 1;
	for(int i = N - K + 1; i <= N; ++i)
		res = 1ll * res * i % mod;
	return 1ll * res * rev[K] % mod;
}

int main() {
	fac[0] = 1;
	rev[0] = 1;
	for(int i = 1; i <= 5000; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}
	scanf("%d %d", &n, &k);
	dp[0][0] = 1;
	for(int i = 1; i <= 5000; ++i)
		for(int j = 1; j <= i; ++j) 
			dp[i][j] = (dp[i - 1][j - 1] + 1ll * dp[i - 1][j] * j) % mod;
	int ans = 0;
	for(int i = 1; i <= k; ++i) 
		ans = (ans + 1ll * dp[k][i] * fac[i] % mod * newton(n, i) % mod * pt(2, n - i)) % mod;
	printf("%d", ans);

	return 0;
}