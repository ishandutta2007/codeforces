#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;		

const int nax = 505;
const ll inf = 1e18;

int n, k;
int a[nax], b[nax];
ll p[nax];
ll dp[nax][nax];
	
int main() {
	scanf ("%d%d", &n, &k);
	rep(i, 0, n - 1) {
		scanf ("%d%d", a + i, b + i);
		p[i] = (i > 0 ? p[i - 1] : 0) + a[i] + b[i];
	}
	rep(i, 0, n) rep(j, 0, k - 1) dp[i][j] = -inf;
	dp[0][0] = 0;
	rep(i, 0, n - 1) {
		int z = (a[i] + b[i]) / k;
		int r = (a[i] + b[i]) - z * k;
		rep(j, 0, k - 1) {
			if (dp[i][j] == -inf) continue;
			
			int R = j;
			int B = (i > 0 ? p[i - 1] : 0) - R - dp[i][j] * k;
			rep(red, 0, min(r, a[i])) {
				int blue = r - red;
				if (blue > b[i]) continue;
				ll C = dp[i][j] + (blue + B) / k + (red + R) / k + z;
				dp[i + 1][(red + R) % k] = max(dp[i + 1][(red + R) % k], C);
			}
			if (a[i] + b[i] < r + k) continue;
			r += k;
			rep(red, 0, min(r, a[i])) {
				int blue = r - red;
				if (blue > b[i]) continue;
				ll C = dp[i][j] + (blue + B) / k + (red + R) / k + z - 1;
				dp[i + 1][(red + R) % k] = max(dp[i + 1][(red + R) % k], C);
			}
			r -= k;
			
			
		}
	}
	ll answer = 0;
	rep(j, 0, k - 1)
		answer = max(answer, dp[n][j]);
	printf ("%lld\n", answer);
				
				
			
	
	return 0;
}