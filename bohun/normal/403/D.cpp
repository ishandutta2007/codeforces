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

const int nax = 1005;
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

int T, a, b;
int dp[nax][nax];
int ans[nax][nax];

int fac[5000];
int rev[5000];

int newton(int N, int K) {
	return 1ll * fac[N] * rev[K] % mod * rev[N - K] % mod;
}

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}


int main() {
	fac[0] = 1;
	rev[0] = 1;
	for(int i = 1; i < 5000; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}

	dp[0][0] = 1;
	for(int i = 1; i <= 1000; ++i)
		for(int j = 1; j <= i; ++j)
			dp[i][j] = (dp[i - j][j] + dp[i - j][j - 1]) % mod;
	
	for(int s = 1; s <= 1000; ++s)
		for(int k = 1; k * (k + 1) / 2 <= s; ++k) {
			int res = 0;
			for(int g = 1; g <= s; ++g) 
				add(res, 1ll * dp[g][k] * newton(s - g + k, k) % mod);
			ans[s][k] = 1ll * fac[k] * res % mod;
		}
	
	
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", ans[a][b]);
	}
			


	return 0;
}