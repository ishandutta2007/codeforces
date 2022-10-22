#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 405;
const int P = 998244353;

ll bin_pow(ll a, ll b) {
	ll c = 1;
	while (b) {
		if (b & 1) c = c * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return c;
}

int n, c[26];
int dp1[N][N][2], dp2[N][N][N][3], qq[N][N];

ll s1(int m, int x) {
	return (dp1[m][x][0] + dp1[m][x][1]) % P;
}

ll s2(int m, int x, int y) {
	ll ans = 0;
	rep(j, 0, 2)
		ans += dp2[m][x][y][j];
	return ans % P;
}

int main() {
	scanf("%d", &n);
	rep(i, 0, 25) scanf("%d", c + i);
	
	dp1[1][0][0] = 25;
	dp1[1][1][1] = 1;
	
	ll w = 24 * bin_pow(25, P - 2) % P;
	rep(i, 1, n - 1) 
		rep(j, 0, i) {
			dp1[i + 1][j + 1][1] = dp1[i][j][0];
			dp1[i + 1][j][0] = ll(25) * ((1LL * dp1[i][j][0] * w + dp1[i][j][1]) % P) % P;
		}
		
	dp2[1][0][0][0] = 24;
	dp2[1][1][0][1] = 1;
	dp2[1][0][1][2] = 1;
	
	w = 23 * bin_pow(24, P - 2) % P;
	rep(i, 1, n - 1)
		rep(j, 0, i) 
			rep(k, 0, i) {
				dp2[i + 1][j + 1][k][1] = (dp2[i][j][k][0] + dp2[i][j][k][2]) % P;
				dp2[i + 1][j][k + 1][2] = (dp2[i][j][k][0] + dp2[i][j][k][1]) % P;
				dp2[i + 1][j][k][0] = ll(24) * ((dp2[i][j][k][1] + dp2[i][j][k][2] + 1LL * dp2[i][j][k][0] * w % P) % P) % P;
			}
	
	ll ans = 26 * 26 * bin_pow(25, n - 2) % P;
	
	rep(i, 0, 25)
		rep(a, 0, n)
			rep(b, 0, n)
				if (a + b > c[i])
					ans = (ans - 1LL * s1(n / 2, a) * s1((n + 1) / 2, b) % P + P) % P;
	
	per(a, 0, n)
		per(b, 0, n)
			qq[a][b] = (1LL * qq[a + 1][b] + qq[a][b + 1] - qq[a + 1][b + 1] + s2(n / 2, a, b)) % P;
			
	rep(i, 0, 25)
		rep(j, i + 1, 25) 
			rep(a, 0, n)
				rep(b, 0, n) 
					ans = (ans + 1LL * s2((n + 1) / 2, a, b) * qq[max(0, c[i] - a + 1)][max(0, c[j] - b + 1)]) % P;
			
	printf("%lld\n", ans);
	return 0;
}