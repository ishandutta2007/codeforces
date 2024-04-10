#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;
 
const int INF = 1e9 + 7, N = 320 , M = 1e5 + 7, MOD = 1e9 + 7;
 
int dp[2][N][N];
 
void add(int &a, int b) {
	a += b;
	if(a >= MOD) a -= MOD;
}
 
signed main()
{
	IO_OP;
	
	int n, m, x;
	cin >> n >> m >> x;
	if(n > m) return cout << 0 << endl, 0;
	dp[0][0][0] = 1;
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k <= n; k++) {
				dp[i & 1][j][k] = 0;
				if(i != x) {
					// close
					add(dp[i & 1][j][k], dp[(i & 1) ^ 1][j + 1][k]);
					// open
					if(j && k) add(dp[i & 1][j][k], dp[(i & 1) ^ 1][j - 1][k - 1]);
					// open and close
					if(k && j == 0) add(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k - 1]);
					// close and open
					if(j && k) add(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k - 1]);
					// no
					add(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k]);
				} else {
					// open
					if(j && k) add(dp[i & 1][j][k], dp[(i & 1) ^ 1][j - 1][k - 1]);
					// open and close
					if(k && j == 0) add(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k - 1]);
					// close and open
					if(j && k) add(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k - 1]);
				}
			}
		}
	}
	ll ans = dp[m & 1][0][n];
	for(int i = 1; i <= n; i++) ans = ans * i % MOD;
	cout << ans << endl;
}