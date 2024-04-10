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

int n;
int a[2001];
int jest[2001];
int dp[2001][2001];
int fac[2001];
 
int main() {
	fac[0] = 1;
	for(int i = 1; i <= 2000; ++i)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 0; i <= 2000; ++i) {
		dp[i][0] = dp[i][i] = 1;
		for(int j = 1; j < i; ++j)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		jest[a[i]] = 1;
	}
	int good = 0;
	int fre = 0;
	for(int i = 1; i <= n; ++i) {
		good += (!jest[i] && a[i] == -1);
		fre += (a[i] == -1);
	}
	int ans = 0;
	for(int i = 0; i <= good; ++i) {
		int res = 1ll * dp[good][i] * fac[fre - i] % mod;
		if(i % 2)
			ans = (ans - res + mod) % mod;
		else
			ans = (ans + res) % mod;
	}
	printf("%d", ans);
	
	
	
	
	
	return 0;
}