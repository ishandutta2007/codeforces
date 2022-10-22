#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define int long long

using namespace std;

const int N = 510;

int n;
int dp[N + 1][50 * N + 5];
 
int nom[] = {1, 5, 10, 50}; 

map <int, int> bylo;
 
int32_t main() {
	scanf ("%lld", &n);
	
	dp[0][0] = 1;
	rep(i, 0, 3)
		rep(j, 1, N) 
			per(s, 0, 50 * N) 
				if (s - nom[i] >= 0)
					dp[j][s] |= dp[j - 1][s - nom[i]];
	
	if (n <= N) {
		int res = 0;
		rep(i, n, 50 * n)
			res += dp[n][i];
		printf ("%lld", res);
		exit(0);
	}
	
	LL ans = 50 * n - n + 1;

	rep(i, 1, N) {
		int x = n + i;
		int good = 0;
		rep(j, 1, N) {
			if (j > n) break;
			int z = x - (n - j);
			good |= dp[j][z];
		}
		if (!good && x <= 50 * n && (bylo.find(x) == bylo.end())) ans--;
		
		bylo[x] = 1;
		
		x = 50 * n - i;
		good = 0;
		rep(j, 1, N) {
			if (j > n) break;
			int z = x - (n - j) * 50;
			good |= dp[j][z];
		}
		if (!good && n <= x && (bylo.find(x) == bylo.end())) ans--;
		
		bylo[x] = 1;
	}
	printf ("%lld", ans);
	
			
	
	return 0;
}