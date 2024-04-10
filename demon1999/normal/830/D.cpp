#include <bits/stdc++.h>  

using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int ma = 2 * 128 * 1024;
const ll mod = int(1e9) + 7;
ll dp[800][800], c[800][800];
int n;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	c[0][0] = 1;
	for (int i = 1; i < 800; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod; 
		}
		//cout << "\n";
	}
	dp[1][1] = 1;
	dp[1][0] = 1;
	//cout << 1 << "\n";
	for (int k = 2; k <= n; k++) {
		dp[k][0] = 1;
		for (int i = 1; i <= n + 1; i++) {
			for (int j = 0; j <= i + 1; j++) {
				if (i - j >= 0) {
					dp[k][i] += ((1LL + 2LL * i) * dp[k - 1][i - j])%mod * dp[k - 1][j];
				}
				dp[k][i] %= mod;
				if (i - j > 0) {
					dp[k][i] += dp[k - 1][j]  * dp[k - 1][i - j - 1];
				}
				dp[k][i] %= mod;
				dp[k][i] += ((2LL * c[i + 1][2] * dp[k - 1][j])%mod) * dp[k - 1][i + 1 - j];
				dp[k][i] %= mod;
			}
			//cout << dp[k][i] << " ";
		}
//		cout << "\n";
	}
	cout << dp[n][1];
}