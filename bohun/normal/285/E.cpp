#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

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
int dp[1001][1001][2][2]; // [i][j][x][y] - prefiks o dl i, mam do tej pory j dobrych, x / y - czy used

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

int ans[1001];
int fac[1001];
int rev[1001];

int newton(int N, int K) {
	if(N < K)
		return 0;
	int r = fac[N];
	r = 1ll * r * rev[K] % mod;
	r = 1ll * r * rev[N - K] % mod;
	return r;
}

int main() {
	
	fac[0] = rev[0] = 1;
	for(int i = 1; i <= 1000; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}
	
	scanf("%d %d", &n, &k);
	if(n == 1) {
		if(k == 0) 
			printf("1");
		else
			printf("0");
		return 0;
	}
	dp[0][0][0][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= i; ++j) {
			// 1. a) ja nie biore nikogo i nie jestem uzyty
			add(dp[i][j][0][0], dp[i - 1][j][1][0]);
			add(dp[i][j][0][0], dp[i - 1][j][0][0]);
			// b) jestem uzyty
			add(dp[i][j][1][0], dp[i - 1][j][0][1]);
			add(dp[i][j][1][0], dp[i - 1][j][1][1]);
			// 2. a) ja biore poprzednika i nie jestem uzyty
			if(j > 0 && i > 1)
				add(dp[i][j][0][0], dp[i - 1][j - 1][0][0]);
			// b) -- i jestem uzyty
			if(j > 0 && i > 1)
				add(dp[i][j][1][0], dp[i - 1][j - 1][0][1]);
			// 3. a) ja biore nastepnika i nie jestem uzyty
			if(j > 0 && i < n) {
				add(dp[i][j][0][1], dp[i - 1][j - 1][0][0]);
				add(dp[i][j][0][1], dp[i - 1][j - 1][1][0]);
			}
			// b) i jestem uzyty
			if(j > 0 && i < n) {
				add(dp[i][j][1][1], dp[i - 1][j - 1][0][1]);
				add(dp[i][j][1][1], dp[i - 1][j - 1][1][1]);
			}
		}
	for(int i = n; k <= i; --i) {
		ans[i] = 1ll * (dp[n][i][0][0] + dp[n][i][1][0]) * fac[n - i] % mod;
		for(int j = i + 1; j <= n; ++j) {
			ans[i] = (ans[i] - 1ll * newton(j, i) * ans[j] % mod + mod) % mod;
		}
	}
	printf("%d", ans[k]);		
					
	
	return 0;
}