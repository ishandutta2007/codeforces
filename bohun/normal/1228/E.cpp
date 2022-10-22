#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;
const int mod = 1e9 + 7;
const int nax = 300;

int n, k;
int dp[nax][nax];

int res = 0;

int pt(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1)
			r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}

int main() {
	scanf("%d%d", &n, &k);
	
	FOR(i, 0, n) {
		dp[i][0] = dp[i][i] = 1;
		FOR(j, 1, i - 1)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
	}
	
	FOR(i, 0, n)
		FOR(j, 0, n) {
			int ile = n * (i + j) - i * j;
			int ways = (ll) pt(k - 1, ile) * pt(k, n * n - ile) % mod * dp[n][i] % mod * dp[n][j] % mod;
			res += ((i + j) % 2 == 0 ? ways : mod - ways);
			res %= mod;
		}
	
	printf("%d\n", res);
		
	
	
	return 0;
}