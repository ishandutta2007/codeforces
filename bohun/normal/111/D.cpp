#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define DOW(i, n) for(int i = n - 1; 0 <= i; --i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 11;

void add(ll &a, ll b) {
	a += b;
	if(a >= mod) 
		a -= mod;
}

ll pt(ll a, ll b) {
	if(!b) return 1;
	if(b & 1) return a * pt(a, b - 1) % mod;
	return pt(a * a % mod, b / 2);
}

int n, m, k;
int dp[1005][1005];
int fac[N];
int rev[N];

int newton(int N, int K) {
	if(N < K) return 0;
	return 1LL * fac[N] * rev[K] % mod * rev[N - K] % mod;
}

int main() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	rev[0] = 1;
	for(int i = 1; i < N; ++i)
		rev[i] = pt(fac[i], mod - 2);
	
	dp[0][0] = 1;
	for(int i = 1; i <= 1000; ++i)
		for(int j = 1; j <= 1000; ++j)
			dp[i][j] = (dp[i - 1][j - 1] + 1LL * j * dp[i - 1][j]) % mod;
	
	ll ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	if(m == 1) {
		printf("%lld", pt(k, n));
		return 0;
	}
	for(int dif = 1; dif <= min(n, k); ++dif) {
		for(int mid = 0; mid <= dif; ++mid) { // wspolne elementy w kolumnach...
			ll ways = 1LL * newton(k, mid) * newton(k - mid, 2 * (dif - mid)) % mod;
			ways = ways * newton(2 * (dif - mid), dif - mid) % mod;
			ways = ways * dp[n][dif] % mod * fac[dif] % mod;
			ways = ways * dp[n][dif] % mod * fac[dif] % mod;
			if(mid == 0 && m > 2) continue;
			ways = ways * pt(mid, n * m - 2 * n) % mod;
			add(ans, ways);
		}
	}
	printf("%lld", ans);	
	
	return 0;
}